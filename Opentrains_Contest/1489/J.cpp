#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7;

const int N = 110;

int n, m, k, d[N];

int dp[N][1100][40];

int add[1100];

int f(int x){
	int res = 0, pre = -1;
	for(int i = 0; i <k;i++){
		if((x&1) != pre) res++;
		pre = (x&1); x >>= 1;
	}
	return res-1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	int up = 1 << k;
	for (int i = 1; i < n; i ++)
		cin >> d[i];
	dp[0][0][0] = 1;
	for (int i = 0; i < up; i ++) {
		for (int j = 0; j < k; j ++) {
			if (j != 0) add[i] += (i >> j & 1) ^ (i >> (j - 1) & 1);
			if (j + 1 != k) add[i] += (i >> j & 1) ^ (i >> (j + 1) & 1);
		}
		add[i] >>= 1;
	}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < up; j ++)
			for (int t = 0; t < m; t ++) {
				int nex = (t + add[j] * d[i]) % m;
				(dp[i + 1][j][nex] += dp[i][j][t]) %= Mod;
				for (int p = 0; p < k; p ++) {
					if (j >> p & 1) continue;
					(dp[i + 1][j | (1 << p)][nex] += dp[i][j][t]) %= Mod;
				}
			}

	cout << (dp[n][up - 1][0] % Mod + Mod) % Mod << '\n';
	return 0;
}