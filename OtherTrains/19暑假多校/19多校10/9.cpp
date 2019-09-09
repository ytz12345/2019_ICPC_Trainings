#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int t, n, m, q;

int tim, a[N][N], v[N][N];

bool isStable(int x, int y) {
	int nx, ny, res = 0;
	for (int i = 0; i < 2; i ++) {
		nx = x + dx[i], ny = y + dy[i];
		if (!a[nx][ny]) res |= 1;
	}
	for (int i = 2; i < 4; i ++) {
		nx = x + dx[i], ny = y + dy[i];
		if (!a[nx][ny]) res |= 2;
	}
	return res != 3;
}

void bfs(int x, int y) {
	static queue <int> qx, qy;
	static int nx, ny, cnt;
	while (!qx.empty()) qx.pop();
	while (!qy.empty()) qy.pop();
	
	cnt = 0, qx.push(x), qy.push(y);
	v[x][y] = ++ tim, a[x][y] = 0;
	while (!qx.empty()) {
		x = qx.front(), y = qy.front();
		qx.pop(), qy.pop(); cnt ++;
		for (int i = 0; i < 4; i ++) {
			nx = x + dx[i], ny = y + dy[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m || !a[nx][ny] || v[nx][ny] == tim) continue;
			//printf("%d %d %d\n", nx, ny, isStable(nx, ny));
			if (isStable(nx, ny)) continue;
			a[nx][ny] = 0, v[nx][ny] = tim;
			qx.push(nx), qy.push(ny);
		}
	}
	printf("%d\n", cnt);
}

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &m, &q);
		for (int i = 0; i <= n + 1; i ++)
			for (int j = 0; j <= m + 1; j ++)
				a[i][j] = 1;
		for (int x, y; q --; ) {
			scanf("%d %d", &x, &y);
			if (!a[x][y]) puts("0");
			else bfs(x, y);
		}
	}
}	