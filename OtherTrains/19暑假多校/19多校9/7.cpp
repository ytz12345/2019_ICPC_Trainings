#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int t, n, rt;

vector <int> e[N];

int g[N], f[N];
//g/h out/in

int bfs() {
	static queue <int> q;
	static int dis[N], vis[N];
	for (int i = 1; i <= n; i ++)
		dis[i] = n + 2019, vis[i] = 0;
	dis[1] = 0, vis[1] = 1, q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	int res = 1;
	for (int i = 1; i <= n; i ++)
		if (dis[i] > dis[res])
			res = i;
	return res;
}

void dfs1(int u, int fr) {
	g[u] = f[u] = 1;
	for (int v : e[u]) {
		if (v == fr) continue;
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = 1; i <= n; i ++)
			e[i].clear();
		for (int u, v, i = 1; i < n; i ++) {
			e[u].push_back(v);
			e[v].push_back(u);
		}
		rt = bfs();
		dfs1(rt, rt);
		cout << ans << '\n';
	}
	return 0;
}