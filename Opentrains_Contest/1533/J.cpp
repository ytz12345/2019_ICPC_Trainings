#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set <int> s[N];

int n, m, c[N];

vector <int> e[N];

int tot, dfn[N], pos[N];

long long ans[N];

int fa[N][20], dep[N];

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int j = 19; j >= 0; j --)
		if (dep[fa[x][j]] >= dep[y])
			x = fa[x][j];
	if (x == y) return x;
	for (int j = 19; j >= 0; j --)
		if (fa[x][j] != fa[y][j])
			x = fa[x][j], y = fa[y][j];
	return fa[x][0];
}

int dis(int x, int y) {
	x = dfn[x], y = dfn[y];
	return dep[y] + dep[x] - dep[lca(x, y)] * 2;
}

void ins(int x, int y) {
	auto r = s[x].upper_bound(y);
	if (r != s[x].end()) ans[x] += dis(y, *r);
	auto l = r; 
	if (l != s[x].begin()) {
		l --, ans[x] += dis(y, *l);
		if (r != s[x].end()) ans[x] -= dis(*l, *r);
	}
	s[x].insert(y);
}

void del(int x, int y) {
	auto r = s[x].upper_bound(y);
	if (r != s[x].end()) ans[x] -= dis(y, *r);
	auto l = r; l --;
	if (l != s[x].begin()) {
		l --, ans[x] -= dis(y, *l);
		if (r != s[x].end()) ans[x] += dis(*l, *r);
	}
	s[x].erase(y);
}

long long getAns(int x) {
	auto l = s[x].begin(), r = s[x].end(); r --;
	return (ans[x] + dis(*l, *r)) / 2;
}

void dfs(int u) {
	dfn[++ tot] = u, pos[u] = tot;
	for (int v : e[u]) {
		if (v == fa[u][0]) continue;
		fa[v][0] = u, dep[v] = dep[u] + 1, dfs(v);
	}
}

char op[5];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int u, v, i = 1; i < n; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++)
		cin >> c[i];
	dfs(1); cin >> m;
	for (int i = 1; i < 20; i ++)
		for (int j = 1; j <= n; j ++)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
	for (int i = 1; i <= n; i ++)
		ins(c[dfn[i]], i);
	for (int x, y; m --; ) {
		cin >> op;
		if (op[0] == 'U') cin >> x >> y, del(c[x], pos[x]), ins(c[x] = y, pos[x]);
		else cin >> x, cout << (s[x].size() != 0 ? getAns(x) : -1) << '\n';
	}
}