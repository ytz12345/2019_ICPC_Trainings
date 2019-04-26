#include <bits/stdc++.h>

using namespace std;

const int N = 20000;

const int M = 500000;

const int inf = 0x3f3f3f3f;

int n, m;

int s, t, len = 1;

int to[M], nex[M], cap[M];

int g[N], p[N], q[N], d[N];

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

int a[N], b[123][123];

char ss[123][123];

char sss[] = "LlwW";

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> ss[i];
		for (int j = i + 1; j < n; j ++)
			b[i][j] = b[j][i] = i * n + j;
	}
	s = n * n + n + 1, t = s + 1;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (ss[i][j] == '#') continue;
			else if (ss[i][j] == 'W') a[i] -= 3;
			else if (ss[i][j] == 'w') a[i] -= 2;
			else if (ss[i][j] == 'l') a[i] -= 1;
			else if (ss[i][j] == 'L') a[i] -= 0;
			else if (i < j) add(s, b[i][j], 3), add(b[i][j], i + n * n, 3), add(b[i][j], j + n * n, 3);
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i ++)
		add(i + n * n, t, a[i]), sum += a[i];
	dinic();
	for (int i = n * n; i < s; i ++)
		for (int j = g[i]; j; j = nex[j]) {
			if (to[j] < n * n) {
				int now = i - n * n;
				if (now == to[j] / n) ss[now][to[j] % n] = sss[cap[j]];//, cout << now << ' ' << to[j] % n << ' ' << sss[cap[j]] << endl; 
				else ss[now][to[j] / n] = sss[cap[j]];//, cout << to[j] / n << ' ' << now << ' ' << sss[cap[j]] << endl;
			}
		}
	for (int i = 0; i < n; i ++) {
		cout << ss[i] << '\n';
	}
	return 0;
}