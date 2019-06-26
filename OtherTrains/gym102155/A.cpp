#include <bits/stdc++.h>

using namespace std;

const int N = 1050;

const int inf = 1e9 + 7;

int dp[50][N];

int a[50], b[50];

int n, s, c1, c2, c[50], cnt[50];

inline void upd1(int &x, int y) {
	if (x == inf || x < y) x = y;
}

inline void upd2(int &x, int y) {
	if (x == inf || x > y) x = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < 2 * n * (s + 1); i ++)
		cin >> c[i];
	cin >> c1;
	for (int i = 0; i < c1; i ++) cin >> a[i];
	cin >> c2;
	for (int i = 0; i < c2; i ++) cin >> b[i];
	sort (a, a + c1, [&](int x, int y){return x > y;});
	sort (b, b + c2, [&](int x, int y){return x > y;});
	for (int i = 0; i < 50; i ++)
		for (int j = 0; j < N; j ++)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 0; i < 2 * n * (s + 1); i ++) {
		for (int j = 0; j < (1 << (n * 2)); j ++) {
			if (dp[i][j] == inf) continue;
			int t = 0;
			for (int k = 0; k < n * 2; k ++) t += (j >> k) & 1;
			if (c[i] <= n) {
				if (s > (cnt[c[i]] - ((j >> (c[i] - 1)) & 1))) upd1(dp[i + 1][j], dp[i][j] + a[i - t]);
				if (!((j >> (c[i] - 1)) & 1)) upd1(dp[i + 1][j | (1 << (c[i] - 1))], dp[i][j] + b[t]);
			}
			else {
				if (s > (cnt[c[i]] - ((j >> (c[i] - 1)) & 1))) upd2(dp[i + 1][j], dp[i][j] - a[i - t]);
				if (!((j >> (c[i] - 1)) & 1)) upd2(dp[i + 1][j | (1 << (c[i] - 1))], dp[i][j] - b[t]);
			}
		}
		cnt[c[i]] ++;	
	}
	cout << dp[2 * n * (s + 1)][(1 << (n * 2)) - 1] << '\n';
	return 0;
}