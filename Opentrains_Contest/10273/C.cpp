#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

typedef pair<piir, int> pr;

typedef long long ll;

const int N = 70000;

int n, m, a[20];

int dp[101][N][2];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset (dp, -1, sizeof dp);
	for (int i = 0; i <= m; i ++)
		cin >> a[i];
	dp[1][0][0] = 0;
	for (int i = 0, j = 1 << m; i < j; i ++) {
		dp[1][i][1] = a[0];
		for (int k = 0; k < m; k ++)
			if ((i >> k) & 1)
				dp[1][i][1] += a[k + 1];
	}	
	for (int i = 2; i <= n; i ++) {
		for (int j = 0; j <= m; j ++)
			cin >> a[j];
		for (int j = 0; j < (1 << m); j ++) {
			dp[i][j][0] = dp[i - 1][j][1];
			if (dp[i - 1][j][0] != -1 && dp[i - 1][j][0] < dp[i][j][0])
				dp[i][j][0] = dp[i - 1][j][0]; 
			dp[i][j][1] = dp[i][j][0] + a[0];
		} 
		for (int j = 0; j < (1 << m); j ++) {
			for (int k = 0; k < m; k ++)
				if (!((j >> k) & 1)) {
					if (dp[i][j | (1 << k)][1] == -1 || dp[i][j | (1 << k)][1] > dp[i][j][0] + a[k + 1] + a[0])
						dp[i][j | (1 << k)][1] = dp[i][j][0] + a[k + 1] + a[0];
					if (dp[i][j | (1 << k)][1] == -1 || dp[i][j | (1 << k)][1] > dp[i][j][1] + a[k + 1])
						dp[i][j | (1 << k)][1] = dp[i][j][1] + a[k + 1];
				}
		} 
	}
	int ans = dp[n][(1 << m) - 1][1];
	if (dp[n][(1 << m) - 1][0] != -1 && dp[n][(1 << m) - 1][0] < ans) 
		ans = dp[n][(1 << m) - 1][0];
	cout << ans;
	return 0;
}