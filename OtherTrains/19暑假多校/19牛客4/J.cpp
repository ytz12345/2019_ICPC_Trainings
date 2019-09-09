#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

const int inf = 1e9 + 7;

typedef pair<int, int> piir;

struct node {
	int u, k, w;

	bool operator < (const node &a) const {
		return w > a.w;
	}
};

priority_queue <node> q;

int n, m, s, t, k;

int dp[N][N], vis[N][N];

vector <piir> e[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t >> k;
	for (int u, v, w, i = 0; i < m; i ++) {
		cin >> u >> v >> w;
		e[u].push_back(piir(v, w));
		e[v].push_back(piir(u, w));
	}
	for (int i = 0; i <= n; i ++) 
		for (int j = 0; j <= k; j ++)
			dp[i][j] = inf;
	q.push((node){s, 0, dp[s][0] = 0});
	node tmp;
	while (!q.empty()) {
		tmp = q.top(); q.pop();
		if (tmp.u == t) {
			printf("%d\n", tmp.w);
			return 0;
		}
		if (vis[tmp.u][tmp.k]) continue;
		vis[tmp.u][tmp.k] = 1;
		for (piir v : e[tmp.u]) {
			if (!vis[v.first][tmp.k] && dp[v.first][tmp.k] > tmp.w + v.second) {
				dp[v.first][tmp.k] = tmp.w + v.second;
				q.push((node){v.first, tmp.k, dp[v.first][tmp.k]});
			}
			if (tmp.k < k && !vis[v.first][tmp.k + 1] && dp[v.first][tmp.k + 1] > tmp.w) {
				dp[v.first][tmp.k + 1] = tmp.w;
				q.push((node){v.first, tmp.k + 1, dp[v.first][tmp.k + 1]});
			}
		}
	}

}