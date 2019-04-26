#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;

int cnt, dfn[N], low[N], vis[N];

int top, sta[N], in[N];

int sum, bel[N];

int c[N], d[N];

vector <int> e[N];

void tarjan(int u) {
	vis[u] = in[u] = 1;
	sta[++ top] = u, dfn[u] = low[u] = ++ cnt;
	for (int v : e[u])
		if (!vis[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in[v]) low[u] = min(low[u], low[v]);
	if (low[u] == dfn[u]) {
		sum ++; int i;
		while (1) {
			i = sta[top --];
			bel[i] = sum, in[i] = 0;
			if (i == u) break;
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u, v, i = 1; i <= m; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i ++)
		for (int j : e[i]) {
			if (bel[i] == bel[j]) continue;
			c[bel[i]] ++;
			d[bel[j]] ++;
		}
	if (sum != n) puts("0");
	else if (n == 1) puts("-1");
	else if (m == 0) puts("2");
	else puts("1");
	return 0;
}