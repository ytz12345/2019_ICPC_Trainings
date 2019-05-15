#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};

const int dy[] = {0, -1, 0, 1};

const char *dir = "ULDR";

char s[10][10];

char ans[50];

int dd, len;
/*
int vis[20][4][4], pre[20][4][4];

void work() {
	memset (vis, 0, sizeof vis);
	queue <int> qk, qx, qy;
	qk.push(0), qx.push(0), qy.push(0), vis[0][0][0] = 1;
	while (!qk.empty()) {
		int x = qx.front(), y = qy.front(), k = qk.front();
		qx.pop(), qy.pop(), qz.pop();
		for (int i = 0; i < 4; i ++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (ok(xx, yy)) qx.push(xx), qy.push(yy), vis[xx][yy] = 1;
		}
	}
}
*/

int vis[5][5];

int ok(int x, int y) {
	if (x < 0 || y < 0 || x > 3 || y > 3 || s[x][y] == '#' || vis[x][y]) return 0;
	return 1;
}

int dis() {
	memset (vis, 0, sizeof vis);
	queue <int> qx, qy, qz;
	qx.push(0), qy.push(0), qz.push(0), vis[0][0] = 1;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front(), z = qz.front();
		if (x == 3 && y == 3) return z;
		qx.pop(), qy.pop(), qz.pop();
		for (int i = 0; i < 4; i ++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (ok(xx, yy)) qx.push(xx), qy.push(yy), qz.push(z + 1), vis[xx][yy] = 1;
		}
	}
	return -1;
}

int dfs(int x, int y, int d) {
	vis[x][y] = 1;
	if (x == 3 && y == 3) {
		vis[x][y] = 0;
		if (d > dd) {
			len = d;
			return 1;
		}
		return 0;
	}
	for (int i = 0; i < 4; i ++) {
		if (ok(x + dx[i], y + dy[i])) {
			if (dfs(x + dx[i], y + dy[i], d + 1)) {
				ans[d] = dir[i];
				//printf(" %d %d\n", x, y);
				vis[x][y] = 0;
				return 1;
			}
		}
	}
	vis[x][y] = 0;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int cnt = 0;
	while (1) {
		for (int i = 0; i < 4; i ++)
			scanf("%s", s[i]);
		dd = dis(); 
		memset (vis, 0, sizeof vis);
		if (dfs(0, 0, 0)) {
			ans[len] = 0;
			puts(ans);
		}
		else puts("-1");
		//cnt += d != -1;
		if (scanf("%s", s[0]) == EOF) {
		//	cout << cnt << endl;
			return 0;
		}
	}
}