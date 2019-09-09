#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

const int Mod = 1e9 + 7;

int dp[N][N];

int n, m, k;

void upd(int &a, int x, int y) {
	if (x < 0 || y < 0) return;
	a = (a + dp[x][y]) % Mod;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		k = n + m;
		for (int i = 0; i <= k; i ++)
			for (int j = 0; j <= k; j ++)
				dp[i][j] = 0;
		for (int i = 0; i <= k; i ++)
			for (int j = 0; j <= k; j ++) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
					continue;
				}
				if (i - j > n || j - i > m) continue;
				upd(dp[i][j], i, j - 1);
				upd(dp[i][j], i - 1, j);
			}
		cout << dp[k][k] << '\n';
 	}
 	return 0;
}