#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); i ++)

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const ll inf = 1e18;

int n, a[N], b[N];

ll dp[N][2];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	dp[1][0] = 0, dp[1][1] = a[1] - b[1];  
	rep(i, 2, n) {
		if (a[i - 1] <= b[i] || a[i] <= b[i - 1]) {
			cout << -1;
			return 0;
		}
	}
	rep(i, 2, n) {
		dp[i][0] = dp[i][1] = inf;
		if (b[i - 1] >= b[i]) 
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (a[i - 1] <= a[i]) 
			dp[i][1] = min(dp[i][1], dp[i - 1][1]);
		dp[i][0] = min(dp[i][0], dp[i][1] + a[i] - b[i]);
		dp[i][1] = min(dp[i][1], dp[i][0] + a[i] - b[i]);
	}	
	ll ans = dp[n][0];
	cout << (ans == inf ? -1 : ans);
	return 0;
}