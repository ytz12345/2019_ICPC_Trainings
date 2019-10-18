#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, ll> pr;

const int N = 2e5 + 5;

int n, m, tot;

struct edge{ll a, b, c, t;}a[N];

vector <int> f[N], g[N];

int len, head[N];

struct eg{int to, cost, next;}E[N * 3];

ll d[N], ans;

int vis[N];

deque <int> q;

void add(int u, int v, int w) {
	E[++ len] = (eg){v, w, head[u]}, head[u] = len;
	E[++ len] = (eg){u, w, head[v]}, head[v] = len;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		tot = 0; len = 0;
		for (int i = 1; i <= n; i ++)
			f[i].clear();
		for (int i = 1; i <= m; i ++) {
			cin >> a[i].a >> a[i].b >> a[i].c >> a[i].t;
			f[a[i].a].push_back(a[i].c);
			f[a[i].b].push_back(a[i].c);
		}
		for (int i = 1; i <= n; i ++) {
			sort (f[i].begin(), f[i].end());
			f[i].resize(unique(f[i].begin(), f[i].end()) - f[i].begin());
			g[i].resize(f[i].size());
			for (int j = 0, up = f[i].size(); j < up; j ++)
				g[i][j] = ++ tot, d[tot] = 1e18, head[tot] = 0;
			for (int j = 1, up = f[i].size(); j < up; j ++) 
				add(g[i][j - 1], g[i][j], f[i][j] - f[i][j - 1]);
		}
		for (int u, v, i = 1; i <= m; i ++) {
			u = lower_bound(f[a[i].a].begin(), f[a[i].a].end(), a[i].c) - f[a[i].a].begin();
			v = lower_bound(f[a[i].b].begin(), f[a[i].b].end(), a[i].c) - f[a[i].b].begin();
			u = g[a[i].a][u], v = g[a[i].b][v];
			add(u, v, a[i].t);
		}
		for (int i : g[1]) q.push_back(i), d[i] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop_front(); vis[u] = 0;
			for (int v, i = head[u]; i; i = E[i].next) {
				v = E[i].to; 
				if (d[v] > d[u] + E[i].cost) {
					d[v] = d[u] + E[i].cost;
					if (!vis[v]) {
						vis[v] = 1;
						if (q.empty() || d[q.front()] > d[v]) q.push_front(v);
						else q.push_back(v);
					}
				}
			}
		}
		ans = 1e18;
		for (int i : g[n]) ans = min(ans, d[i]);
		cout << ans << '\n';
	}
}