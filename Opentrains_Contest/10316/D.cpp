#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;

double s[N], p[N];

double dp[N];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	double x, sum, mul;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i] >> x >> p[i];
		sum = s[i], mul = 0, dp[i] = 1e18;
		for (int low = max(0, i - 100), j = i - 1; j >= low; j --) {
			dp[i] = min(dp[i], dp[j] + sum + x);
			mul += log(1 + p[j] / 100);
			sum += s[j] * exp(mul);
		}
	}
	printf("%.10f", dp[n]);
	return 0;
}