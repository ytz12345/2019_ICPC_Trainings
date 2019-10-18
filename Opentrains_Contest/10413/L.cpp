#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

typedef long long ll;

const int N = 4e5 + 5;

int n, m;

vector <piir> g[N];

vector <int> e[N], f[N], E[N];

struct edge{int u, v, w;}h[N];

int du[N], dep[N], fa[N][20];

int siz[N], ans[N];

struct node {
	int u; ll dis;
	bool operator < (const node &a) const {
		return dis > a.dis;
	}	
};

ll dis[N];

int vis[N];

void add(int v, int u) {
	//printf("%d %d %d\n", v, u, id);
	e[v].push_back(u);
	f[u].push_back(v);
	du[u] ++;
}

inline void dij() {
	static priority_queue <node> q;
	for (int i = 1; i <= n; i ++) dis[i] = 1e18, vis[i] = 0;
	q.push((node){1, dis[1] = 0});
	while (!q.empty()) {
		node now = q.top(); q.pop();
		if (vis[now.u]) continue;
		vis[now.u] = 1;
		for (piir v : g[now.u])
			if (!vis[v.first] && dis[v.first] > now.dis + v.second)
				q.push((node){v.first, dis[v.first] = now.dis + v.second}); 
	}
}

inline int lca(int x, int y) {
	//printf("%d %d\n", x, y);
	if (dep[x] < dep[y]) swap(x, y);
	for (int j = 19; j >= 0; j --)
		if (dep[fa[x][j]] >= dep[y])
			x = fa[x][j];
	//printf("%d %d\n", x, y);
	if (x == y) return x;
	for (int j = 19; j >= 0; j --)
		if (fa[x][j] != fa[y][j])
			x = fa[x][j], y = fa[y][j];
	return fa[x][0];
}

inline void topo() {
	static int q[N * 2], l, r; l = 1, r = 0;
	dep[q[++ r] = 1] = 1;
	while (l <= r) {
		int u = q[l ++];
		for (int v : e[u]) {
			du[v] --;
			if (du[v] == 0) {
				//printf("v=%d\n", v);
				int las = -1;
				for (int w : f[v]) {
					if (las == -1) las = w;
					else las = lca(las, w);
				}
				E[las].push_back(v);
				fa[v][0] = las;
				dep[v] = dep[las] + 1;
				for (int j = 1; j < 20; j ++)
					fa[v][j] = fa[fa[v][j - 1]][j - 1];
				q[++ r] = v;
			}
		}
	}
}

void dfs(int u) {
	siz[u] = u <= n;
	for (int v : E[u]) {
		//printf("%d %d %d\n", u, v.first, v.second);
		dfs(v);
		siz[u] += siz[v];
	}
	if (u > n) ans[u - n] = siz[u];
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i <= n + m; i ++) {
			g[i].clear();
			e[i].clear();
			f[i].clear();
			E[i].clear();
			du[i] = 0;
		}
		for (int i = 1; i <= m; i ++) {
			cin >> h[i].u >> h[i].v >> h[i].w;
			g[h[i].u].push_back(piir(h[i].v, h[i].w));
			g[h[i].v].push_back(piir(h[i].u, h[i].w));
			ans[i] = 0;
		}
		
		dij();

		for (int i = 1; i <= m; i ++) {
			if (dis[h[i].u] + h[i].w == dis[h[i].v]) add(h[i].u, i + n), add(i + n, h[i].v);
			if (dis[h[i].v] + h[i].w == dis[h[i].u]) add(h[i].v, i + n), add(i + n, h[i].u);
		}

		topo();
		dfs(1);

		for (int i = 1; i <= m; i ++)
			printf("%d\n", ans[i]);
	}
}