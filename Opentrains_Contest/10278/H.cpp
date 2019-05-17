#include <bits/stdc++.h>

using namespace std;

const int N = 700, M = 5e5, inf = 0x3f3f3f3f;

int s, t, len;

int T, n, m;

int head[N],vis[N];

struct edge {
	int to, next, cap;
	double cost;
}e[M];

void add(int u, int v, int w, double c) {
	e[++ len] = (edge){v, head[u], w, c}, head[u] = len;
	e[++ len] = (edge){u, head[v], 0, -c}, head[v] = len;
}

int dfs(int x, int y) {
	if (x == t || y == 0) return y;
	vis[x] = 1; int flow = 0;
	for (int i = head[x]; i; i = e[i].next) {
		if (e[i].cap && !e[i].cost && !vis[e[i].to]) {
			int f = dfs(e[i].to, min(y, e[i].cap));
			e[i].cap -= f, e[i ^ 1].cap += f;
			flow += f, y -= f;
			if (!y) break;
		}
	}
	return flow;
}

int modlabel() {
	double d = inf;
	for (int i = 1; i <= t; i ++) if (vis[i])
		for (int j = head[i]; j; j = e[j].next)
			if (e[j].cap && !vis[e[j].to] && e[j].cost < d)
				d = e[j].cost;
	if (d >= 1e8) return 0;
	for (int i = 1; i <= t; i ++) if (vis[i]) 
		for (int j = head[i]; j; j = e[j].next)
			e[j].cost -= d, e[j ^ 1].cost += d;
	return 1;
}

vector <int> ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m; char st[N];
	s = n + m + 1, t = s + 1, len = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			add(s, i, 1, j * 2 - 1);
	for (int i = 1; i <= m; i ++)
		add(i + n, t, 1, -2.0 * m / n);
	for (int i = 1; i <= n; i ++) {
		cin >> st;
		for (int j = 1; j <= m; j ++)
			if (st[j - 1] == '1')
				add(i, j + n, 1, 0);
	}
	do {
		do {
			memset (vis, 0, sizeof vis);
		}while (dfs(s, inf));
	}while (modlabel());
	for (int i = 1; i <= n; i ++)
		for (int j = head[i]; j; j = e[j].next) {
			if (n < e[j].to && e[j].to <= n + m && e[j].cap == 0) 
				ans[i].push_back(e[j].to - n);
		}

	for (int i = 1; i <= n; i ++) {
		cout << ans[i].size();
		for (int j : ans[i])
			cout << ' ' << j;
		cout << '\n';
	}

	return 0;
}