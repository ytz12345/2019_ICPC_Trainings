#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, k;

int a[N], b[N];

struct node {
	int x, y, v, id; 
}c[N * 5], c0[N * 5];

int id, ans[N];

inline void clr(int i) {
	if (i > n || !b[i]) return;
	b[i] = 0, c[++ k] = (node){i, a[i], -1, 0};
}

inline void check(int i) {
	if (i > n || a[i] == a[i - 1]) return;
	b[i] = 1, c[++ k] = (node){i, a[i], 1, 0};
}

template <int N>struct bit {
	int c[N];

	bit() {memset (c, 0, sizeof c);}

	int lb(int x) {return x & (-x);}

	void add(int i, int x) {while (i < N) c[i] += x, i += lb(i);}

	int ask(int i) {int res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}
};

void solve(int l, int r) {
	static bit <N> t;
	if (l >= r) return;
	int sum = 0, mid = l + r >> 1;
	for (int i = l; i <= mid; i ++)
		if (c[i].id == 0)
			c0[++ sum] = c[i];
	for (int i = mid + 1; i <= r; i ++)
		if (c[i].id != 0)
			c0[++ sum] = c[i];
	sort (c0 + 1, c0 + sum + 1, [&](node a, node b) {
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.id < b.id;
	});
	for (int i = 1; i <= sum; i ++) 
		if (c0[i].id == 0) 
			t.add(c0[i].y, c0[i].v);
		else 
			ans[c0[i].id] += t.ask(c0[i].y) * c0[i].v;
	for (int i = 1; i <= sum; i ++) 
		if (c0[i].id == 0) 
			t.add(c0[i].y, -c0[i].v);
	solve(l, mid), solve(mid + 1, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i], check(i);
	for (int op, l, r, x, y, i = 1; i <= m; i ++) {
		cin >> op >> l >> r;
		if (op == 1) {
			if (a[l] == r) continue;
			clr(l), clr(l + 1);
			a[l] = r, check(l), check(l + 1);
		}
		else {
			cin >> x >> y;
			ans[++ id] = (!b[l]) & (x <= a[l] && a[l] <= y);
			c[++ k] = (node){r, y, 1, id};
			c[++ k] = (node){l - 1, y, -1, id};
			c[++ k] = (node){r, x - 1, -1, id};
			c[++ k] = (node){l - 1, x - 1, 1, id};
		}
	}
	solve(1, k);
	for (int i = 1; i <= id; i ++)
		printf("%d\n", ans[i]);
	return 0;
}	
	