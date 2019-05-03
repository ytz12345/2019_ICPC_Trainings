#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

const double eps = 1e-9;

typedef pair<int, double> pr;

int n, m, d[N];

vector <pr> e[N], E[N];

int tim[N], vis[N];

queue <int> q;

double dis[N];

bool spfa(int u) {
	while (!q.empty()) q.pop();

	q.push(u), dis[u] = 0;
	tim[u] = 1;

	while (!q.empty()) {
		int now = q.front(); 
		q.pop(); vis[now] = 0;
		if (tim[now] > n) return false;
		for (pr u : e[now]) {
			if (d[u.first] > d[now] + u.second) {
				d[u.first] = d[now] + u.second;
				if (!vis[u.first]) {
					vis[u.first] = 1;
					tim[u.first] ++;
					q.push(u.first);
				}
			}
		}
	}

	return true;
}

bool judge(double x) {
	memset (tim, 0, sizeof tim);
	memset (vis, 0, sizeof vis);

	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < e[i].size(); j ++)
			e[i][j].second = E[i][j].second - x;
		dis[i] = 1e9;
	}

	for (int i = 1; i <= n; i ++) 
		if (!tim[i])
			if (!spfa(i))
				return 0;

	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u, v, w, i = 0; i < m; i ++) {
		cin >> u >> v >> w;
		E[u].push_back(pr(v, w));
		e[u].push_back(pr(v, w));
	}
	double l = -2e6, r = 2e6, mid, ans = 1e8;
	for (int i = 0; i < 60; i ++) {
		mid = (l + r) / 2;
		if (judge(mid)) ans = mid, l = mid + eps;
		else r = mid - eps;
	} 
	if (ans == 1e8) puts("+inf");
	else {
		printf("%.8f\n", ans);
		for (int i = 1; i <= n; i ++)
			printf("%.8f%c", dis[i], i == n ? '\n' : ' ');
	}
	return 0;
}