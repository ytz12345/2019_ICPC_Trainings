#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int t, n, m, k;

ll a[N], b[N], s[N];

struct node {
	int maxv;
}tr[N << 2];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1)

void pushup(int o) {
	tr[o].maxv = max(tr[lc].maxv, tr[rc].maxv);
}

void build(int o, int l, int r) {
	if (l == r) {
		if (!b[r]) tr[o].maxv = 0;
		else tr[o].maxv = -1;
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(o);
}

int ask(int o, int l, int r, int p) {
	if (p <= l) return tr[o].maxv;
	if (p > mid) return ask(rc, mid + 1, r, p);
	return max(tr[rc].maxv, ask(lc, l, mid, p));
} 

void update(int o, int l, int r, int p, int v) {
	if (l == r) {
		tr[o].maxv = max(tr[o].maxv, v);
		return;
	}
	if (p <= mid) update(lc, l, mid, p, v);
	else update(rc, mid + 1, r, p, v);
	pushup(o);
}

bool judge(ll jg) {
	build(1, 1, m);

	for (int p, j, i = 1; i <= n; i ++) {
		j = lower_bound(b + 1, b + m + 1, s[i] - jg) - b;
		if (j > m) continue;
		p = ask(1, 1, m, j);
		if (p == -1) continue;
		update(1, 1, m, lower_bound(b + 1, b + m + 1, s[i]) - b, p + 1);
	}

	return tr[1].maxv >= k;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
			b[i] = s[i];
		}
		b[n + 1] = 0;
		sort (b + 1, b + n + 2);
		m = unique(b + 1, b + n + 2) - b - 1;
		
		ll l = -2e14 - 5, r = 2e14 + 5, md, ans;

		while (l <= r) {
			md = l + r >> 1;
			if (judge(md)) ans = md, r = md - 1;
			else l = mid + 1;
		}

		printf("%lld\n", ans);
	}

	return 0;
}