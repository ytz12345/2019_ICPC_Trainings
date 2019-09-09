#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = N * 20;

int t, n, q, m;

int a[N], b[N];

struct {
	int siz, l, r;
}tr[M];

#define l(x) tr[x].l
#define r(x) tr[x].r
#define s(x) tr[x].siz
#define mid (l + r >> 1)

int tot, root[N];

int build(int l, int r) {
	int x = ++ tot;
	s(x) = 0;
	if (l < r) {
		l(x) = build(l, mid);
		r(x) = build(mid + 1, r);
	}
	return x;
}

int change(int o, int l, int r, int p) {
	int x = ++ tot;
	s(x) = s(o) + 1, l(x) = l(o), r(x) = r(o);
	if (l < r) {
		if (p <= mid) l(x) = change(l(o), l, mid, p);
		else r(x) = change(r(o), mid + 1, r, p);
	}
	return x;
}

int ask(int o1, int o2, int l, int r, int s, int t) {
	//if (s(o1) == s(o2)) return 0;
	if (s <= l && r <= t) return s(o2) - s(o1);
	int res = 0;
	if (s <= mid) res += ask(l(o1), l(o2), l, mid, s, t);
	if (mid <  t) res += ask(r(o1), r(o2), mid + 1, r, s, t);
	return res; 
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> q; 
		tot = 0;
		memset (tr, 0, sizeof tr);
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort (b + 1, b + n + 1);
		m = unique(b + 1, b + n + 1) - b - 1;
		for (int i = 1; i <= n; i ++) {
			a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
		}
		root[0] = build(1, m);
		for (int i = 1; i <= n; i ++)
			root[i] = change(root[i - 1], 1, m, a[i]);
		for (int l, r, p, k, L, R, Mid, ans = 0, ll, rr; q --; ) {
			cin >> l >> r >> p >> k;
			l ^= ans, r ^= ans, p ^= ans, k ^= ans;
			if (l > r) swap(l, r);
			L = 0, R = 1e6;
			while (L <= R) {
				Mid = L + R >> 1;
				ll = lower_bound(b + 1, b + m + 1, p - Mid) - b;
				rr = upper_bound(b + 1, b + m + 1, p + Mid) - b - 1;
				if (ll <= rr && ask(root[l - 1], root[r], 1, m, ll, rr) >= k) ans = Mid, R = Mid - 1;
				else L = Mid + 1;
			}
			printf("%d\n", ans);
		}
	}
	//printf("%d\n", clock());
	return 0;
}