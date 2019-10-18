#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

int n, m;

vector <piir> path[N];

vector <int> e[N], ans;

int fa[N], dep[N], son[N], siz[N], top[N];

int cnt, dfn[N], pos[N];

int M, tr[N << 2];

void dfs1(int u) {
	siz[u] = 1;
	for (int v : e[u]) {
		if (v == fa[u]) continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v), siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int tp) {
	dfn[++ cnt] = u, pos[u] = cnt, top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int v : e[u])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}

int ask(int s, int t) {
	if (s > t) return 0;
	int res = 0;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res += tr[s ^ 1];
		if ( t&1) res += tr[t ^ 1];
 	}
 	return res;
}

int lca(int u, int v) {
	for (int fu = top[u], fv = top[v]; fu != fv; fu = top[u = fa[fu]])
		if (dep[fu] < dep[fv])
			swap(fu, fv), swap(u, v);
	return dep[u] < dep[v] ? u : v;
}

int query(int u, int v) {
	int res = 0;
	for (int fu = top[u], fv = top[v]; fu != fv; fu = top[u = fa[fu]]) {
		if (dep[fu] < dep[fv]) swap(fu, fv), swap(u, v);
		res += ask(pos[fu], pos[u]);
	}
	if (dep[u] > dep[v]) swap(u, v);
	return res + ask(pos[u], pos[v]);
}

void update(int i) {
	for (tr[i += M] = 1, i >>= 1; i; i >>= 1) tr[i] ++;
}

void dfs3(int u) {
	for (int v : e[u]) 
		if (v != fa[u])
			 dfs3(v);
	for (piir p : path[u]) 
		if (query(u, p.first) + query(u, p.second) == 0) 
			return ans.push_back(u), update(pos[u]), void(0);
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		cnt = 0, ans.clear();
		for (int i = 1; i <= n; i ++) {
			fa[i] = son[i] = 0;
			e[i].clear(), path[i].clear();
		}
		for (int u, v, i = 1; i < n; i ++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1), dfs2(1, 1);
		for (M = 1; M < n + 2; M <<= 1);
		for (int i = 1; i <= M * 2 + 1; i ++) tr[i] = 0;

		cin >> m;
		for (int u, v, i = 0; i < m; i ++) {
			cin >> u >> v;
			path[lca(u, v)].push_back(piir(u, v));
		}
		dfs3(1);
		printf("%d\n", (int)(ans.size()));
		for (int u : ans)
			printf("%d ", u);
		puts("");
	}
}