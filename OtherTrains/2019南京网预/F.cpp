#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, k;

int a[N], b[N];

int tr[N << 2], M, ans[N];

int ask(int s, int t) {
	s = max(s, 1), t = min(t, n);
	//printf("%d %d\n", s, t);
	int res = 0;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = max(res, tr[s ^ 1]);
		if ( t&1) res = max(res, tr[t ^ 1]);
	}
	return res;
}

void change(int i, int x) {
	for (tr[i += M] = x, i >>= 1; i; i >>= 1)
		tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++)
			cin >> a[i], b[i] = i;
		sort (b + 1, b + n + 1, [&](int x, int y) {
			return a[x] < a[y];
		});
		for (M = 1; M < n + 2; M <<= 1);
		for (int i = 1; i <= (M * 2 + 5); i ++) tr[i] = 0;
		for (int j, i = 1; i <= n; i ++) {
			ans[i] = ans[ask(b[i] - k, b[i] + k)] + 1;
			change(b[i], a[b[i]]);
		}
		for (int i = 1; i <= n; i ++)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}