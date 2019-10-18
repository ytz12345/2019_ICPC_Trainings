#include <bits/stdc++.h>

using namespace std;

const int N = 555;
const int M = N * N;
const int inf = 1e9;

int n, m;

int d[N];

int f[N][N];

struct edge{int u, v;}e[M];

bool judge(int k) {
	static edge now;
	static int u, v;
	static queue <edge> q;
	
	memset (f, 0, sizeof f);
	memset (d, 0, sizeof d);
	for (int i = 1; i <= m; i ++) {
		d[e[i].u] ++, d[e[i].v] ++;
		f[e[i].u][e[i].v] = 1;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1 + i; j <= n; j ++)
			if (!f[i][j] && d[i] + d[j] >= k)
				q.push((edge){i, j}), f[i][j] = 1;
	while (!q.empty()) {
		now = q.front(), q.pop(), d[now.u] ++, d[now.v] ++; 
		for (int i = 1; i <= n; i ++) {
			if (i != now.u) {
				u = i, v = now.u; if (u > v) swap(u, v);
				if (!f[u][v] && d[u] + d[v] >= k) q.push((edge){u, v}), f[u][v] = 1;
			}	
			if (i != now.v) {
				u = i, v = now.v; if (u > v) swap(u, v);
				if (!f[u][v] && d[u] + d[v] >= k) q.push((edge){u, v}), f[u][v] = 1;
			}	
		}
	}

	for (int i = 1; i <= n; i ++)
		if (d[i] != n - 1)
			return 0;
	return  1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++)
		cin >> e[i].u >> e[i].v;
	int l = 0, r = n - 2 + n - 2, mid, ans = 0;
	while (l <= r) {
		mid = l + r >> 1;
		if (judge(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
}