#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;

vector <int> e[N];

int f[N];

int tim, vis[N], dis[N], fr[N];

int q[N], head, tail;

int getf(int x) {
	return x == f[x] ? x : (f[x] = getf(f[x]));
}

void solve(int u, int v) {
	static int now;
	tim ++;
	vis[u] = vis[v] = tim;
	dis[u] = dis[v] = 0;
	fr[u] = u, fr[v] = v;
	head = 1, tail = 0;
	q[++ tail] = u;
	q[++ tail] = v;
	while (1) {
		now = q[head ++];
		for (int t : e[now]) {
			if (vis[t] == tim) {
				if (fr[t] == fr[now]) continue;
				printf("%d\n", dis[t] + dis[now] + 1);
				return;
			}
			else {
				vis[t] = tim;
				dis[t] = dis[now] + 1;
				fr[t] = fr[now];
				q[++ tail] = t;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) f[i] = i;
	for (int u, v, i = 0; i < m; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		f[getf(v)] = getf(u);
	}
	cin >> m;
	for (int u, v, i = 0; i < m; i ++) {
		cin >> u >> v;
		if (getf(u) != getf(v)) puts("-1");
		else solve(u, v);
	}
	return 0;
}