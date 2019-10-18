#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, m, a[N];

short dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int l = 0, i = 1; i <= n; i ++)
		if (i == n || a[i] != a[i + 1])
			m = max(m, i - l), l = i;
	n = unique(a + 1, a + n + 1) - a - 1;
	if (n == 1) m = max(m, 1);
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			int k = lower_bound(a + 1, a + n + 1, a[i] + a[i] - a[j]) - a;
			if (a[k] + a[j] == a[i] + a[i]) dp[i][j] = dp[k][i] + 1;
			else dp[i][j] = 2;
			m = max(m, int(dp[i][j]));
		}
	cout << m << '\n';
}