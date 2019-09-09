#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int maxv[N << 2];

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)

int n, m, w[N];

void build(int o, int l, int r) {
	if (l == r) {
		maxv[o] = w[r];
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	maxv[o] = max(maxv[lc], maxv[rc]);
}

int ask(int o, int l, int r, int s, int x) {
	if (maxv[o] < x) return -1;
	if (l == r) return r;
	int res = ask(rc, mid + 1, r, s, x);
	if (res != -1) return res;
	if (s <= mid) return ask(lc, l, mid, s, x);
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> w[i];
	build(1, 1, n);
	for (int j, i = 1; i <= n; i ++) {
		if (i != n) j = ask(1, 1, n, i + 1, w[i] + m);
		else j = -1;
		if (j == -1) printf("%d%c", -1, i == n ? '\n' : ' ');
		else printf("%d%c", j - i - 1, i == n ? '\n' : ' ');
	}
	return 0;
}