#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = j; i <= k; i ++)

using namespace std;

typedef pair<int, int> piir;

const int N = 310;

vector <piir> ans;

int n, m;

vector <int> e[N];

int cnt, vis[N], dfn[N], low[N];

int top, in[N], sta[N];

int sum, bel[N];

int f[N][N], ff[N][N];

piir ee[N][N];

void tarjan(int u) {
	vis[u] = in[u] = 1, sta[++ top] = u;
	dfn[u] = low[u] = ++ cnt;
	for (int v : e[u])
		if (!vis[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in[v]) low[u] = min(low[u], low[v]);
	if (dfn[u] == low[u]) {
		sum ++; int last = u;
		for (int i = sta[top --]; ; i = sta[top --]) {
			if (last != i) ans.push_back(piir(i, last));
			bel[i] = sum, in[i] = 0;
			if (i == u) break;
			last = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u, v, i = 0; i < m; i ++) {
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
			if (f[bel[i]][bel[j]]) continue;
			ff[bel[i]][bel[j]] = f[bel[i]][bel[j]] = 1;
			ee[bel[i]][bel[j]] = piir(i, j);
		}

	rep(k, 1, sum) rep(i, 1, sum) rep(j, 1, sum) 
		if (i != j && i != k && j != k)
			f[i][j] |= f[i][k] & f[k][j];

	rep(i, 1, sum)
		rep(j, 1, sum) {
			if (!ff[i][j]) continue;
			int flag = 1;
			rep(k, 1, n)
				if (i != k && j != k && f[i][k] & f[k][j]) 
					flag = 0;
			if (flag) ans.push_back(ee[i][j]);
		}

	cout << n << ' ' << ans.size() << endl;
	for (piir i : ans)
		cout << i.first << ' ' << i.second << endl;
	return 0;
}
