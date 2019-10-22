#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int M = 10010;

int n, m;

struct {int u, v;}e[M];

int a[N], b[N], c[N], d[N];

vector <int> E[N];

int tim, vis[N], pre[N];

bool dfs(int u) {
	if (vis[u] == tim) return 0;
	vis[u] = tim;
	for (int v : E[u])
		if (!pre[v] || dfs(pre[v]))
			return pre[v] = u, 1;
	return 0;
} 

void judge(int k) {
	for (int i = 1; i <= n; i ++) {
		pre[i] = vis[i] = 0;
		b[i] = c[i] = d[i] = 0;
		E[i].clear();
	}

	a[0] = 0; b[k] = 1;
	for (int i = 1; i <= m; i ++)
		if (e[i].u == k || e[i].v == k)
			a[++ a[0]] = e[i].u + e[i].v - k, b[a[a[0]]] = 1;
	if (a[0] * 2 + 1 < n) return;

	for (int i = 1; i <= m; i ++) {
		if (b[e[i].u] && !b[e[i].v]) E[e[i].v].push_back(e[i].u);
		if (!b[e[i].u] && b[e[i].v]) E[e[i].u].push_back(e[i].v);
	}
	for (tim = 1; tim <= n; tim ++)
		if (!b[tim]) 
			if (!dfs(tim))
				return;
	for (int i = 1; i <= a[0]; i ++)
		if (pre[a[i]])
			d[pre[a[i]]] = a[i];
	puts("Yes");
	printf("%d %d\n", k, a[0]);
	for (int i = 1; i <= n; i ++)
		if (!b[i])
			printf("%d %d\n", i, d[i]), c[d[i]] = 1;
	for (int i = 1; i <= a[0]; i ++)
		if (!c[a[i]])
			printf("%d -1\n", a[i]);
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
		cin >> e[i].u >> e[i].v;
	for (int i = 1; i <= n; i ++)
		judge(i);
	puts("No");
	return 0;
}