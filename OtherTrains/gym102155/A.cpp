#include <bits/stdc++.h>

using namespace std;

const int N = 1050;

const int inf = 1e9 + 7;

int dp[50][N];

int a[50], b[50];

int n, s, c1, c2, c[50], cnt[50], bj[50];

int dfs(int i, int j) {
	if (i >= 2 * n * (s + 1)) return 0;
	if (dp[i][j] != inf) return dp[i][j];
	int t = 0;
	for (int k = 0; k < n * 2; k ++) t += (j >> k) & 1;
	if (c[i] < n) {
		if ((j >> c[i]) & 1) return dp[i][j] = dfs(i + 1, j) + a[i - t];
		else if (bj[i]) return dp[i][j] = dfs(i + 1, j | (1 << c[i])) + b[t];
		else return dp[i][j] = max(dfs(i + 1, j) + a[i - t], dfs(i + 1, j | (1 << c[i])) + b[t]);
	}
	else {
		if ((j >> c[i]) & 1) return dp[i][j] = dfs(i + 1, j) - a[i - t];
		else if (bj[i]) return dp[i][j] = dfs(i + 1, j | (1 << c[i])) - b[t];
		else return dp[i][j] = min(dfs(i + 1, j) - a[i - t], dfs(i + 1, j | (1 << c[i])) - b[t]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < 2 * n * (s + 1); i ++) {
		cin >> c[i], c[i] --;
		cnt[c[i]] ++;
		if (cnt[c[i]] == s + 1) bj[i] = 1;
	}
	cin >> c1;
	for (int i = 0; i < c1; i ++) cin >> a[i];
	cin >> c2;
	for (int i = 0; i < c2; i ++) cin >> b[i];
	sort (a, a + c1, [&](int x, int y){return x > y;});
	sort (b, b + c2, [&](int x, int y){return x > y;});
	for (int i = 0; i < 50; i ++)
		for (int j = 0; j < N; j ++)
			dp[i][j] = inf;
	cout << dfs(0, 0) << '\n';
	return 0;
}