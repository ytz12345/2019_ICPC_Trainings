#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const char *t = "0wrong";

int n;

char s[N];

ll a[N], dp[N][8];

int main() {
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 5; j ++) {
			if (s[i] == t[j + 1]) {
				dp[i][j] = dp[i - 1][j] + a[i];
				if (j != 4) dp[i][j + 1] = dp[i - 1][j];
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	ll ans = dp[n][0];
	for (int i = 1; i < 5; i ++)
		ans = min(ans, dp[n][i]);
	cout << ans << '\n';
	return 0;
}