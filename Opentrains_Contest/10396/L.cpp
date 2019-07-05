#include <bits/stdc++.h>

using namespace std;

const int N = 510;

const int M = N * N;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, cnt, sum;

int a[N][N], bel[N][N];

int vis[N][N], used[M], vised[M];

int rec[N];

vector <int> ans[M];

struct node {
	int l, r, u, d;
	node() {
		l = d = 1e9;
		r = u = -1e9;
	}
}tr[M];

void upd(node &a, int x, int y) {
	a.l = min(a.l, x);
	a.r = max(a.r, x);
	a.u = max(a.u, y);
	a.d = min(a.d, y);
}

void bfs(int x, int y) {
	static int nx, ny, z;  
	upd(tr[++ cnt], x, y); z = a[x][y];
	vis[x][y] = 1; bel[x][y] = cnt;
	static queue <int> qx, qy;
	while (!qx.empty()) qx.pop();
	while (!qy.empty()) qy.pop();
	qx.push(x), qy.push(y);
	while (!qx.empty()) {
		x = qx.front(), y = qy.front();
		qx.pop(), qy.pop();
		for (int i = 0; i < 4; i ++) {
			nx = x + dx[i], ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m || vis[nx][ny] || a[nx][ny] != z) continue;
			qx.push(nx), qy.push(ny), vis[nx][ny] = 1, bel[nx][ny] = cnt, upd(tr[cnt], nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) 
			cin >> a[i][j];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (!vis[i][j]) 
				bfs(i, j);
	for (int i = 1; i <= n; i ++) {
		rec[0] = 0;
		for (int j = 1; j <= m; j ++) {
			if (!used[bel[i][j]]) rec[++ rec[0]] = bel[i][j];
			used[bel[i][j]] = 1;
		}
		for (int j = 1; j <= m; j ++) {
			if (!vised[bel[i][j]]) {
				for (int k = 1; k <= rec[0]; k ++) {
					if (tr[rec[k]].l <= tr[bel[i][j]].l &&
						tr[rec[k]].r >= tr[bel[i][j]].r &&
						tr[rec[k]].d <= tr[bel[i][j]].d &&
						tr[rec[k]].u >= tr[bel[i][j]].u)
						ans[bel[i][j]].push_back(rec[k]);
				}
			}
			vised[bel[i][j]] = 1;
		}
		for (int j = 1; j <= m; j ++) 
			used[bel[i][j]] = 0;
	}
	for (int i = 1; i <= cnt; i ++) {
		sort (ans[i].begin(), ans[i].end());
		sum += unique(ans[i].begin(), ans[i].end()) - ans[i].begin() - 1;
	}
	cout << sum << endl;
	return 0;
}