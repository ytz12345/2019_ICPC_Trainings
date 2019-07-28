#include <bit/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, a[N], b[N];

int dp[N][6];

int main() {
	ios::sync_with_stdio(false);

	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = 3; i <= n; i ++)
			cin >> b[i];

		for (int i = 0; i <= n; i ++)
			for (int j = 0; j < 6; j ++)
				dp[i][j] = 0;

		for (int i = 0; i < 6; i ++)
			dp[3][i] = 1;

		for (int i = 4; i <= n; i ++) {

			//0 -> 0
			if (dp[i - 1][0] && b[i - 1] <= b[i]) dp[i][0] = 1; 

			//2 -> 0
			if (dp[i - 1][2] && b[i - 1] <= b[i]) dp[i][0] = 1;

			//4 -> 0
			if (dp[i - 1][4] && b[i - 1] == b[i]) dp[i][0] = 1;

			//0 -> 1
			if (dp[i - 1][0] && b[i - 1] <= b[i]) dp[i][1] = 1;

			//2 -> 1
			if (dp[i - 1][2])                     dp[i][1] = 1;

			//4 -> 1
			if (dp[i - 1][4] && b[i - 1] >= b[i]) dp[i][1] = 1;

			//1 -> 2
			if (dp[i - 1][1] && b[i - 1] <= b[i]) dp[i][1] = 1;
		}
	}
}

/*
 0 123
 1 132
 2 213
 3 231
 4 312
 5 321
 */
