#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int t, n, m, a[N], b[N], c[N];

int maxv[N << 2];

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)

void update(int o) {
	maxv[o] = max(maxv[lc], maxv[rc]);
}

void build(int o, int l, int r) {
	if (l == r) {maxv[o] = c[r];return;}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	update(o);
}

void change(int o, int l, int r, int p) {
	if (l == r) {maxv[o] = n + 1;return;}
	p <= mid ? change(lc, l, mid, p) : change(rc, mid + 1, r, p);
	update(o);
}

int ask(int o, int l, int r, int s, int t, int x) {
	if (maxv[o] <= x) return 0;
	if (l == r) return r;
	if (s <= mid) {
		int res = ask(lc, l, mid, s, t, x);
		if (res != 0) return res;
	}
	return ask(rc, mid + 1, r, s, t, x);
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m; int lastAns = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i], b[i] = 1;
			c[a[i]] = i;
		}
		c[n + 1] = n + 1;
		build(1, 1, n + 1);
		for (int op, x, y; m --; ) {
			cin >> op >> x;
			if (op == 1) {
				x ^= lastAns;
				if (b[x] == 1) {
					b[x] = 0;
					change(1, 1, n + 1, a[x]);
				}
			}
			else {
				cin >> y;
				x ^= lastAns, y ^= lastAns;
				printf("%d\n", lastAns = ask(1, 1, n + 1, y, n + 1, x));
			}
		}
	}
	return 0;
}