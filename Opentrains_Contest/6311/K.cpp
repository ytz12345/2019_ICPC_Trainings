#include <bits/stdc++.h>

#define lb(x) (x&(-x))

using namespace std;

typedef long long ll;

const int N = 4e5 + 5;

int q, n, m, c[N], d[N];

ll ans[N];

struct node {
	int x, y, v, id;
}b[N], g[N];

struct {
	int op, x[2], y[2]; 
}a[N];

void add(int i, int x) {while (i <= m) c[i] += x, i += lb(i);}

ll ask(int i) {ll res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

void solve (int l, int r) {
	if (l == r) return;
	int mid = l + r >> 1, len = 0;
	for (int i = l; i <= mid; i ++)
		if (b[i].id == 0)
			g[len ++] = b[i];
	for (int i = mid + 1; i <= r; i ++)
		if (b[i].id != 0)
			g[len ++] = b[i];
	sort (g, g + len, [&](node a, node b){
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.id < b.id;
	});
	for (int i = 0; i < len; i ++)
		if (g[i].id == 0)
			add(g[i].y, g[i].v);
		else
			ans[g[i].id] += ask(g[i].y) * g[i].v;
	for (int i = 0; i < len; i ++)
		if (g[i].id == 0)
			add(g[i].y, -g[i].v);
	solve(l, mid), solve(mid + 1, r);
}

void solve() {
	for (int i = 1; i <= n; i ++)
		d[i] = b[i].y;
	sort (d + 1, d + n + 1);
	m = unique(d + 1, d + n + 1) - d - 1;
	for (int i = 1; i <= n; i ++)
		b[i].y = lower_bound(d + 1, d + m + 1, b[i].y) - d;
	solve(1, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> q;
	for (int i = 1; i <= q; i ++) {
		cin >> a[i].op >> a[i].x[0] >> a[i].y[0];
		if (a[i].op == 2) cin >> a[i].x[1] >> a[i].y[1];
	}
	n = 0;
	for (int i = 1; i <= q; i ++) {
		if (a[i].op == 1) b[++ n] = (node){a[i].x[0], a[i].y[0], 1, 0};
		else {
			b[++ n] = (node){a[i].x[0] - 1, a[i].y[0] - 1, 1, i};
			b[++ n] = (node){a[i].x[0] - 1, a[i].y[1], -1, i};
			b[++ n] = (node){a[i].x[1], a[i].y[0] - 1, -1, i};
			b[++ n] = (node){a[i].x[1], a[i].y[1], 1, i};
		}
	}
	solve();
	n = 0;
	for (int i = 1; i <= q; i ++) {
		if (a[i].op == 1) b[++ n] = (node){a[i].x[0], a[i].y[0], 1, i};
		else {
			b[++ n] = (node){a[i].x[0], a[i].y[0], 1, 0};
			b[++ n] = (node){a[i].x[0], a[i].y[1] + 1, -1, 0};
			b[++ n] = (node){a[i].x[1] + 1, a[i].y[0], -1, 0};
			b[++ n] = (node){a[i].x[1] + 1, a[i].y[1] + 1, 1, 0};
		}
	}
	solve(); 
	for (int i = 1; i <= q; i ++)
		ans[i] += ans[i - 1], printf("%lld\n", ans[i]);
}