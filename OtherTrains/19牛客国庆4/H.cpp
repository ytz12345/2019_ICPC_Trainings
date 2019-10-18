#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, ll> pr;

const int N = 1e5 + 5;

int n;

vector <pr> e[N];

void bfs(int st, ll *d) {
	static queue <int> q;
	for (int i = 1; i <= n; i ++)
		d[i] = 1e18;
	d[st] = 0; q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto &v : e[u])
			if (d[v.first] > d[u] + v.second) {
				d[v.first] = d[u] + v.second;
				q.push(v.first);
			}
	}
}

ll ans, dis[2][N];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 1; i <= n; i ++)
			e[i].clear();
		for (int u, v, w, i = 1; i < n; i ++) {
			cin >> u >> v >> w;
			e[u].push_back(pr(v, w));
			e[v].push_back(pr(u, w));
		}
		int d1, d2; ll d;
		bfs(1, dis[0]); d = -1;
		for (int i = 1; i <= n; i ++)
			if (dis[0][i] > d)
				d = dis[0][i], d1 = i;
		bfs(d1, dis[0]); d = -1;
		for (int i = 1; i <= n; i ++)
			if (dis[0][i] > d)
				d = dis[0][i], d2 = i;
		ans = -dis[0][d2];
		bfs(d2, dis[1]);
		for (int i = 1; i <= n; i ++)
			ans += max(dis[0][i], dis[1][i]);
		printf("%lld\n", ans);
	} 
}