#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;

vector <int> e[N];

int dp[N];

void dfs(int u) {
	if (e[u].size() == 0) {
		dp[u] = 1;
		return;
	}
	dp[u] = -1;
	for (int v : e[u])
		dfs(v), dp[u] += dp[v];
	dp[u] = max(dp[u], 0);
}

int redfs(int u) {
	if (e[u].size() == 0) return u;
	for (int v : e[u])
		if (dp[v] > 0)
			return redfs(v);
	return redfs(e[u][0]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int j, i = 2; i <= n; i ++) {
		cin >> j;
		e[j].push_back(i);
	}
	dfs(1);
	if (dp[1] > 0) puts("SECOND");
	else {
		puts("FIRST");
		printf("%d\n", redfs(1));
	}
}