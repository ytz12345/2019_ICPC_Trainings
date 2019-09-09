#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 2019;
const int inf = 1e9 + 7;

int t, n, m, k, s, c;

vector <piir> e[N];

int a[N];

int dis[2][N];

int vis[N];

int max_dis[2];

struct node {
	int u, dis;

	bool operator < (const node &a) const {
		return dis > a.dis;
	}
}now;

priority_queue <node> q;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> s >> k >> c;
		for (int i = 1; i <= n; i ++)
			e[i].clear();
		for (int i = 1; i <= k; i ++)
			cin >> a[i];
		for (int u, v, w; m --; ) {
			cin >> u >> v >> w;
			e[u].push_back(piir(v, w));
			e[v].push_back(piir(u, w));
		}

		for (int i = 1; i <= n; i ++)
			vis[i] = 0, dis[0][i] = inf;
		q.push((node){s, 0}), dis[0][s] = 0;
		while (!q.empty()) {
			now = q.top(), q.pop();
			if (vis[now.u]) continue;
			vis[now.u] = 1;
			for (piir v : e[now.u]) {
				if (!vis[v.first] && dis[0][v.first] > dis[0][now.u] + v.second) {
					dis[0][v.first] = dis[0][now.u] + v.second;
					q.push((node){v.first, dis[0][v.first]});
				}
			}
		}
		max_dis[0] = 0;
		for (int i = 1; i <= n; i ++)
			max_dis[0] = max(max_dis[0], dis[0][i]);

		for (int i = 1; i <= n; i ++)
			vis[i] = 0, dis[1][i] = inf;
		for (int i = 1; i <= k; i ++)
			q.push((node){a[i], 0}), dis[1][a[i]] = 0;
		while (!q.empty()) {
			now = q.top(), q.pop();
			if (vis[now.u]) continue;
			vis[now.u] = 1;
			for (piir v : e[now.u]) {
				if (!vis[v.first] && dis[1][v.first] > dis[1][now.u] + v.second) {
					dis[1][v.first] = dis[1][now.u] + v.second;
					q.push((node){v.first, dis[1][v.first]});
				}
			}
		}
		max_dis[1] = 0;
		for (int i = 1; i <= n; i ++)
			max_dis[1] = max(max_dis[1], dis[1][i]);

		printf("%d\n", max_dis[0] <= max_dis[1] * c ? max_dis[0] : max_dis[1]);
	}
	return 0;
}