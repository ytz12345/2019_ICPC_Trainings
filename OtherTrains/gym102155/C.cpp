#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;

int d[N], dis[N], fr[N];

vector <int> e[N];

int k, a[N][3], b[N], used[N];

void bfs(int st) {
	queue <int> q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (dis[v] > dis[u] + 1)
				dis[v] = dis[u] + 1, q.push(v), fr[v] = u;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u, v, i = 1; i < n; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) {
		memset (dis, 0x3f, sizeof dis);
		dis[i] = 0;
		bfs(i);
		int flag = 1;
		for (int j = 1; j <= n; j ++) {
			if (dis[j] > 2)
				flag = 0;
			b[j] = j;
			used[j] = 0;
		}
		if (!flag) continue;
		sort (b + 1, b + n + 1, [&](int x, int y) {
			if (dis[x] != dis[y]) dis[x] > dis[y];
			return d[x] < d[y];
		});
		k = 0; used[i] = 1;
		for (int j = 1; j <= n; j ++) {
			if (used[b[j]]) continue;
			if (fr[b[j]] == i) a[++ k][0] = 1, a[k][1] = b[j], used[b[j]] = 1;
			else if (used[fr[b[j]]]) {
				flag = 0;
				break;
			}
			else {
				a[++ k][0] = 2;
				a[k][1] = b[j], used[a[k][1]] = 1;
				a[k][2] = fr[b[j]], used[a[k][2]] = 1;
			}
		}
	}
	puts("No");
	return 0;
}