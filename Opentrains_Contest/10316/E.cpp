#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7;

int n, m, p;

int dp[55][210];

int dfs(int l, int x) {
	if (dp[l][x] != -1) return dp[l][x];
	dp[l][x] = 0;

	if (l == 1) return dp[l][x] = ((0 <= x && x <= 9) ? 1 : 0);
	if (l == 2) return dp[l][x] = ((10 <= x && x <= 99) ? 1 : 0);
	if (l == 3) dp[l][x] = ((100 <= x && x <= 199) ? 1 : 0);
	
	//右起为数字
	for (int i = 0; i < min(m, 10); i ++) {
		if (l < 3) continue; 
		dp[l][x] = (dp[l][x] + dfs(l - 2, ((x - i) % m + m) % m)) % Mod;//y + i = x 
		dp[l][x] = (dp[l][x] + dfs(l - 2, ((i + x) % m + m) % m)) % Mod;//y - i = x 
	}
	for (int i = 10; i < min(m, 100); i ++) {
		if (l < 4) continue; 
		dp[l][x] = (dp[l][x] + dfs(l - 3, ((x - i) % m + m) % m)) % Mod;
		dp[l][x] = (dp[l][x] + dfs(l - 3, ((i + x) % m + m) % m)) % Mod;
	}
	for (int i = 100; i < min(m, 200); i ++) {
		if (l < 5) continue; 
		dp[l][x] = (dp[l][x] + dfs(l - 4, ((x - i) % m + m) % m)) % Mod;
		dp[l][x] = (dp[l][x] + dfs(l - 4, ((i + x) % m + m) % m)) % Mod;
	}

	//右起为括号
	for (int i = 3; i <= l - 2; i ++) {
		for (int j = 0; j < m; j ++) {
			dp[l][x] = (dp[l][x] + 1ll * dfs(i - 2, j) * dfs(l - i - 1, ((x - j) % m + m) % m) % Mod) % Mod;//y + (j) = x 
			dp[l][x] = (dp[l][x] + 1ll * dfs(i - 2, j) * dfs(l - i - 1, ((j + x) % m + m) % m) % Mod) % Mod;//y - (j) = x 
		}
	}

	//(E)
	dp[l][x] = (dp[l][x] + dp[l - 2][x]) % Mod;

	return dp[l][x];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	memset(dp, -1, sizeof dp);
	cout << dfs(n, p);
	return 0;
}