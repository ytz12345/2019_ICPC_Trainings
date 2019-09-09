#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int B = 20;

int n, m, a[N];

struct node {
	int c[2];
	int rev, cov, clr;
}tr[B][N << 2];

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)

void pushup(node *T, int o) {
	T[o].c[0] = T[lc].c[0] + T[rc].c[0];
	T[o].c[1] = T[lc].c[1] + T[rc].c[1];
}

void build(node *T, int o, int l, int r, int b) {
	T[o].rev = T[o].cov = T[o].clr = 0;
	if (l == r) {  
		T[o].c[1] = a[r] >> b & 1;
		T[o].c[0] = 1 ^ T[o].c[1];
		return;
	}
	build (T, lc, l, mid, b);
	build (T, rc, mid + 1, r, b);
	pushup(T, o);
}

void pushdown(node *T, int o, int l, int r) {
	if (T[o].rev) {
		if (T[lc].cov) T[lc].cov = 0, T[lc].clr = 1;
		else if (T[lc].clr) T[lc].cov = 1, T[lc].clr = 0;
		else T[lc].rev ^= 1;
		swap(T[lc].c[0], T[lc].c[1]);

		if (T[rc].cov) T[rc].cov = 0, T[rc].clr = 1;
		else if (T[rc].clr) T[rc].cov = 1, T[rc].clr = 0;
		else T[rc].rev ^= 1;
		swap(T[rc].c[0], T[rc].c[1]);

		T[o].rev = 0;
	}

	if (T[o].cov) {
		T[lc].rev = T[lc].clr = 0, T[lc].cov = 1;
		T[lc].c[1] = (mid - l + 1), T[lc].c[0] = 0;

		T[rc].rev = T[rc].clr = 0, T[rc].cov = 1;
		T[rc].c[1] = r - mid, T[rc].c[0] = 0;

		T[o].cov = 0;
	}
	if (T[o].clr) {
		T[lc].rev = T[lc].cov = 0, T[lc].clr = 1;
		T[lc].c[0] = (mid - l + 1), T[lc].c[1] = 0;

		T[rc].rev = T[rc].cov = 0, T[rc].clr = 1;
		T[rc].c[0] = r - mid, T[rc].c[1] = 0;

		T[o].clr = 0;
	}
}

int ask(node *T, int o, int l, int r, int s, int t) {
	if (s <= l && r <= t) return T[o].c[1];
	pushdown(T, o, l, r);
	int res = 0;
	if (s <= mid) res += ask(T, lc, l, mid, s, t);
	if (mid <  t) res += ask(T, rc, mid + 1, r, s, t);
	return res;
}

void change2(node *T, int o, int l, int r, int s, int t) {
	if (l != r) pushdown(T, o, l, r);
	if (s <= l && r <= t) {
		T[o].rev = 1;
		swap(T[o].c[0], T[o].c[1]);
		return;
	}
	if (s <= mid) change2(T, lc, l, mid, s, t);
	if (mid <  t) change2(T, rc, mid + 1, r, s, t);
	pushup(T, o);
}

void change3(node *T, int o, int l, int r, int s, int t) {
	if (l != r) pushdown(T, o, l, r);
	if (s <= l && r <= t) {
		T[o].cov = 1;
		T[o].c[1] = r - l + 1;
		T[o].c[0] = 0;
		return;
	}
	if (s <= mid) change3(T, lc, l, mid, s, t);
	if (mid <  t) change3(T, rc, mid + 1, r, s, t);
	pushup(T, o);
}

void change4(node *T, int o, int l, int r, int s, int t) {
	if (l != r) pushdown(T, o, l, r);
	if (s <= l && r <= t) {
		T[o].clr = 1;
		T[o].c[0] = r - l + 1;
		T[o].c[1] = 0;
		return;
	}
	if (s <= mid) change4(T, lc, l, mid, s, t);
	if (mid <  t) change4(T, rc, mid + 1, r, s, t);
	pushup(T, o);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; ll ans;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 0; i < B; i ++)
		build(tr[i], 1, 1, n, i);
	cin >> m;
	for (int op, l, r, x; m --; ) {
		cin >> op >> l >> r;
		if (op == 1) {
			ans = 0;
			for (int i = 0; i < B; i ++)
				ans += (1ll << i) * ask(tr[i], 1, 1, n, l, r);
			printf("%lld\n", ans);
		}
		else if (op == 2) {
			cin >> x;
			for (int i = 0; i < B; i ++, x >>= 1)
				if (x & 1) change2(tr[i], 1, 1, n, l, r);
		}
		else if (op == 3) {
			cin >> x;
			for (int i = 0; i < B; i ++, x >>= 1)
				if (x & 1) change3(tr[i], 1, 1, n, l, r);
		}
		else if (op == 4) {
			cin >> x;
			for (int i = 0; i < B; i ++, x >>= 1)
				if (!(x & 1)) change4(tr[i], 1, 1, n, l, r);
		}
	}
	return 0;
}