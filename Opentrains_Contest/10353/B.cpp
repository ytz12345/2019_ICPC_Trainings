#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

const int inf = 1e9 + 7;

int dp[2][N];

piir pre[102][N];

int n, a[110];

void dfs(int i, int j) {
	if (i == 0) return;
	dfs(pre[i][j].first, pre[i][j].second);
	//printf("%d %d\n", i, j);
	if (j > pre[i][j].second) printf("%d + %d\n", a[i], 0);
	else printf("%d + %d\n", a[i] - (pre[i][j].second - j), pre[i][j].second - j);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i < N; i ++)
		dp[0][i] = inf;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < N; j ++)
			dp[!(i & 1)][j] = inf;
		for (int t, j = 0; j < N; j ++) {
			if (dp[i & 1][j] >= inf) continue;
			if (dp[!(i & 1)][j + a[i + 1] / 100] > dp[i & 1][j] + a[i + 1]) {
				dp[!(i & 1)][j + a[i + 1] / 100] = dp[i & 1][j] + a[i + 1];
				pre[i + 1][j + a[i + 1] / 100] = piir(i, j);
			}
			t = min(j, a[i + 1]);
			if (dp[!(i & 1)][j - t] > dp[i & 1][j] + a[i + 1] - t) {
				dp[!(i & 1)][j - t] = dp[i & 1][j] + a[i + 1] - t;
				pre[i + 1][j - t] = piir(i, j);
			}
		}
	}
	int ans = inf, p = -1;
	for (int i = 0; i < N; i ++) {
		if (dp[n & 1][i] < ans)
			ans = dp[n & 1][i],  p = i;
	}
	printf("%d\n", ans);
	dfs(n, p);
	return 0;
}