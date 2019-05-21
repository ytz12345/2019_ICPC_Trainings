#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000;

int n, a[N], b[N];

vector <int> e[N];

ll dp[20][N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	for (int i = 0, j = 1 << n; i < j; i ++) {
		int t = 0;
		for (int k = 0; k < n; k ++)
			t += i >> k & 1;
		e[t].push_back(i);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j : e[i]) {
			for (int k = 0; k < n; k ++) {
				if ((j >> k & 1) && a[i - 1] <= b[k])
					dp[i][j] += dp[i - 1][j ^ (1 << k)];
			}
		}
	}
	cout << dp[n][(1 << n) - 1];
	return 0;
}