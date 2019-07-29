#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2019;

const int M = 500000;

const ll inf = 1e18;

int n, m;

int s, t, len;

ll cap[M];

int to[M], nex[M];

int g[N], p[N], q[N], d[N];

void add(int x, int y, ll v) {
	to[++ len] = y, cap[len] = v, nex[len] = g[x], g[x] = len;
	to[++ len] = x, cap[len] = 0, nex[len] = g[y], g[y] = len;
}

bool bfs() {
	int l = 1, r = 1, x, i;
	memset (d, 0, sizeof d);
	d[s] = 1, q[1] = s;
	while (l <= r) {
		x = q[l ++];
		for (i = g[x]; i; i = nex[i]) 
			if (cap[i] && !d[to[i]])
			d[to[i]] = d[x] + 1, q[++ r] = to[i];
	} 
	return d[t];
}

ll dfs(int x, ll y) {
	if (x == t || y == 0) return y;
	ll flow = 0;
	for (int &i = p[x]; i; i = nex[i]) {
		if (!cap[i] || d[to[i]] != d[x] + 1) continue;
		ll f = dfs(to[i], min(y, cap[i]));
		flow += f, y -= f;
		cap[i] -= f, cap[i ^ 1] += f;
		if (!y) break;
	}
	return flow;
}

ll dinic() {
	ll maxflow = 0;
	while (bfs()) {
		memcpy(p, g, sizeof g);
		maxflow += dfs(s, inf);
	}
	return maxflow;
}

ll sum, ans;

ll c[2][N];

int main() {
	while (cin >> n >> m) {
		s = n * 2 + 1, t = s + 1, len = 1; sum = 0;
		for (int i = 1; i <= n; i ++)
			c[0][i] = c[1][i] = 0;
		for (int i = 0; i <= t; i ++)
			g[i] = 0;
		for (int u, v, a, b, d, i = 1; i <= m; i ++) {
			cin >> u >> v >> a >> b >> d;
			sum += (a + b + d) * 2;
			c[0][u] += a + b;
			c[0][v] += a + b;
			c[1][u] += b + d;
			c[1][v] += b + d;
			add(u, v + n, a + d - b * 2); 
			add(v, u + n, a + d - b * 2); 
		}
		for (int i = 1; i <= n; i ++) {
			add(i, i + n, inf);
			add(s, i, c[0][i]);
			add(i + n, t, c[1][i]);
		}
		ans = sum - dinic();
		//cout << ans << '\n';
		cout << ans / 2 << '\n';
	}
	return 0;
}