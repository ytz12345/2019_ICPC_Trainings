#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2019;

int t, n;

ll ans;

struct point {
	int x, y, w;
}p[N];

struct node {
	ll v, s, ls, rs;
}tr[N << 2];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1)

int a[N], m;

void pushup(int o) {
	tr[o].s = tr[lc].s + tr[rc].s;
	tr[o].ls = max(tr[lc].ls, tr[lc].s + tr[rc].ls);
	tr[o].rs = max(tr[rc].rs, tr[rc].s + tr[lc].rs);
	tr[o].v = max(max(tr[lc].v, tr[rc].v), tr[lc].rs + tr[rc].ls);
}

void build(int o, int l, int r) {
	tr[o].s = tr[o].v = tr[o].ls = tr[o].rs = 0;
	if (l == r) return;
	build (lc, l, mid);
	build (rc, mid + 1, r);
}

void change (int o, int l, int r, int p, int w) {
	if (l == r) {
		tr[o].s += w;
		tr[o].v = tr[o].ls = tr[o].rs = max(0ll, tr[o].s);
		return;
	}
	if (p <= mid) change (lc, l, mid, p, w);
	else          change (rc, mid + 1, r, p, w);
	pushup(o);
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> p[i].x >> p[i].y >> p[i].w;
			a[i] = p[i].x;
		}
		sort (a + 1, a + n + 1);
		m = unique(a + 1, a + n + 1) - a - 1;
		for (int i = 1; i <= n; i ++)
			p[i].x = lower_bound(a + 1, a + m + 1, p[i].x) - a;
		sort (p + 1, p + n + 1, [&](point x, point y) {
			return x.y > y.y;
		});
		ans = 0;
		for (int i = 1; i <= n; ) {
			build(1, 1, m);
			for (int j = i; j <= n; ) {
				change(1, 1, m, p[j].x, p[j].w);
				j ++;
				while (j <= n && p[j].y == p[j - 1].y) {
					change(1, 1, m, p[j].x, p[j].w);
					j ++;
				}
				ans = max(ans, tr[1].v);
			}
			i ++;
			while (i <= n && p[i].y == p[i - 1].y) i ++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}