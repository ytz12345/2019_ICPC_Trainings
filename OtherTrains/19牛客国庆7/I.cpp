#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, c[N];

struct edge{int u, v;}g[N];

vector <int> e[N];

int fa[N], sum[N], siz[N], son[N];

int ans[N], ans1[N], ans2[N];

int cnt1, cnt2, cnt[N];

void dfs1(int u) {
	sum[c[u]] ++, siz[u] = 1;
	for (int v : e[u]) {
		if (v == fa[u]) continue;
		fa[v] = u, dfs1(v);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void update(int x, int y) {
	if (cnt[x] == 0) cnt1 ++;
	if (cnt[x] == sum[x]) cnt2 --;
	cnt[x] += y;
	if (cnt[x] == 0) cnt1 --;
	if (cnt[x] == sum[x]) cnt2 ++;
}

void dfs3(int u, int val) {
	update(c[u], val);
	for (int v : e[u]) {
		if (v == fa[u]) continue;
		dfs3(v, val);
	}
}

void dfs2(int u) {
	for (int v : e[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v), dfs3(v, -1);
	}
	if (son[u]) dfs2(son[u]);
	for (int v : e[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs3(v, 1);
	}
	update(c[u], 1);
	ans1[u] = cnt1, ans2[u] = cnt2;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 1; i <= n; i ++)
			cin >> c[i], e[i].clear(), sum[i] = cnt[i] = son[i] = 0;
		for (int u, v, i = 1; i < n; i ++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
			g[i] = (edge){u, v};
		}
		cnt1 = cnt2 = 0, dfs1(1), dfs2(1);
		for (int u, i = 1; i < n; i ++) {
			u = g[i].u == fa[g[i].v] ? g[i].v : g[i].u;
			printf("%d\n", ans[i] = ans1[u] - ans2[u]);
		}		
	}
}