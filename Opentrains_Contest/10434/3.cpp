#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> pr;

const int N = 3e5 + 5;
const int M = 1e6 + 5;
const int inf = 0x3f3f3f3f;

int n, m, cnt;

int s, t, len = 1;

int to[M], cap[M], nex[M];

int g[N], p[N], q[N], d[N];

map <pr, int> mp;

int a[210][1010], b[N], c[210][1010];

void add(int x, int y, int v) {
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

int dfs(int x, int y) {
	if (x == t || y == 0) return y;
	int flow = 0;
	for (int &i = p[x]; i; i = nex[i]) {
		if (!cap[i] || d[to[i]] != d[x] + 1) continue;
		int f = dfs(to[i], min(y, cap[i]));
		flow += f, y -= f;
		cap[i] -= f, cap[i ^ 1] += f;
		if (!y) break;
	}
	return flow;
}

int dinic() {
	int maxflow = 0;
	while (bfs()) {
		memcpy(p, g, sizeof g);
		maxflow += dfs(s, inf);
	}
	return maxflow;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; string tmp; cnt = n;
	for (int k, x, i = 1; i <= n; i ++) {
		cin >> tmp >> k;
		while (k --) {
			cin >> x;
			a[i][++ a[i][0]] = mp[pr(tmp, x)] = ++ cnt;
			c[i][a[i][0]] = x;
		}
	}
	cin >> m; s = cnt + m + 1, t = s + 1;
	for (int i = 1; i <= n; i ++) add(s, i, 1);
	for (int k, x, y, i = 1; i <= m; i ++) {
		cin >> k; cnt ++;
		for (int j = 1; j <= k; j ++) {
			cin >> tmp >> x;
			add(y = mp[pr(tmp, x)], cnt, 1);
			b[y] = 1;
		}
		add(cnt, t, 1);
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= a[i][0]; j ++) {
			add(i, a[i][j], 1);
			if (!b[a[i][j]]) add(a[i][j], t, 1);
		}
	int ans = dinic();
	//cout << ans << endl;
	if (ans != n) puts("No");
	else {
		puts("Yes");
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= a[i][0]; j ++) 
				for (int k = g[a[i][j]]; k; k = nex[k]) 
					if (to[k] <= n && cap[k] == 1)
						printf("%d ", c[i][j]);
		puts("");
	}
	return 0;
}