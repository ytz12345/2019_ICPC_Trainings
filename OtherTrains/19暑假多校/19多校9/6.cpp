#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 233;
const int K1 = 6;
const int K2 = 15;
const int K5 = 6;

int t, n;

ll ans, w[N];

int dp[N];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n; ans = 1e18;
		int flag = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> w[i];
			if (w[i] % 10 != 0) flag = 1;
			w[i] /= 10;
		}
		if (flag) {
			puts("-1");
			continue;
		}
		ll tmp, temp, tmp10;
		for (int i = 0; i <= K1; i ++) {
			for (int j = 0; j <= K2; j ++)
				for (int k = 0; k <= K5; k ++) {
					int up = i * 1 + j * 2 + k * 5;
					for (int p = 1; p <= up; p ++) 
						dp[p] = 0;
					dp[0] = 1;
					for (int p = 1; p <= i; p ++)
						for (int q = up; q >= 1; q --)
							if (dp[q - 1]) dp[q] = 1;

					for (int p = 1; p <= j; p ++)
						for (int q = up; q >= 2; q --)
							if (dp[q - 2]) dp[q] = 1;

					for (int p = 1; p <= k; p ++)
						for (int q = up; q >= 5; q --)
							if (dp[q - 5]) dp[q] = 1;

					flag = 1; tmp = i + j + k, tmp10 = 0;
					for (int ok, p = 1; p <= n; p ++) {
						ok = 0, temp = 1e18;
						for (int q = w[p] % 10; q <= up; q += 10) {
							if (dp[q]) {
								ok = 1;
								temp = min(temp, (w[p] - q) / 10);
							}
						}
						if (!ok) {
							flag = 0;
							break;
						}
						tmp10 = max(tmp10, temp);
					}
					if (flag) {
						ans = min(ans, tmp + tmp10);
						/*printf("%lld %d %d %d\n", ans, i, j, k);
						for (int i = 0; i <= up; i ++)
							printf("%d %d\n", i, dp[i]);*/
					}
					else continue;
				}
		}
		printf("%lld\n", ans);
	}
}