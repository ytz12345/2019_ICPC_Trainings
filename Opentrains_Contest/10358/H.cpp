#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct node {
	int x[2], y[2], ans;
}a[N];

char s[1010][1010];

int sum[1010][1010];

int b[1010][1010];

int p[1010][1010], vis[1010][1010];

int f[1000100];//, sz[1000100];

int n, m, tim;

inline int ask_sum(int i, int j) {
	if (i < 0 || j < 0) return 0;
	return sum[i][j];
}

inline int calc(int i, int j, int k) {
	return ask_sum(i + k / 2, j + k / 2) +
		   ask_sum(i - k / 2 - 1, j - k / 2 - 1) -
		   ask_sum(i - k / 2 - 1, j + k / 2) -
		   ask_sum(i + k / 2, j - k / 2 - 1);
}
 
queue <int> qx, qy;

inline void bfs(int x, int y, int flag) {
	int i, j, nx, ny; tim ++;
	qx.push(x), qy.push(y), vis[x][y] = flag;
	while (!qx.empty()) {
		i = qx.front(), j = qy.front();
		qx.pop(), qy.pop();
		f[p[i][j]] = tim;
		for (int t = 0; t < 4; t ++) {
			nx = i + dx[t], ny = j + dy[t];
			if (nx < flag / 2 || ny < flag / 2 || nx + flag / 2 >= n || ny + flag / 2 >= n) continue;
			if (b[nx][ny] || vis[nx][ny] == flag) continue;
			qx.push(nx), qy.push(ny);
			vis[nx][ny] = flag;
		}
	}
}

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

struct node {
	int x[2], y[2], ans;
}a[N];

char s[1010][1010];

int sum[1010][1010];

int b[1010][1010];

int p[1010][1010];

int f[1000100];

int n, m;

inline int fa(int x) {return x == f[x] ? x : (f[x] = fa(f[x]));}

inline void un(int x, int y) {x = fa(x), y = fa(y); if (x != y) f[y] = x;}

inline int calc(int i, int j, int k) {
	return sum[i + k / 2][j + k / 2] +
		   sum[i - k / 2 - 1][j - k / 2 - 1] -
		   sum[i - k / 2 - 1][j + k / 2] -
		   sum[i + k / 2][j - k / 2 - 1];
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; j ++) {
			sum[i][j] = sum[i][j - 1] +
						sum[i - 1][j] -
						sum[i - 1][j - 1] +
						(s[i][j] == '#');
			p[i][j] = (i - 1) * n + j;
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i ++) 
		scanf("%d %d %d %d", &a[i].x[0], &a[i].y[0], &a[i].x[1], &a[i].y[1]);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			f[p[i][j]] = p[i][j];
	for (int len = n & 1 ? n : (n - 1); len > 0; len -= 2) {
		for (int i = len / 2 + 1; i + len / 2 <= n; i ++)
			for (int j = len / 2 + 1; j + len / 2 <= n; j ++)  {
				if ((b[i][j] = calc(i, j, len))) continue;
				if (i != len / 2 + 1 && !b[i - 1][j]) un(p[i][j], p[i - 1][j]);
				if (j != len / 2 + 1 && !b[i][j - 1]) un(p[i][j], p[i][j - 1]); 
			}
		for (int i = 0; i < m; i ++) {
			if (a[i].ans != 0) continue;
			if (fa(p[a[i].x[0]][a[i].y[0]]) == fa(p[a[i].x[1]][a[i].y[1]])) 
				a[i].ans = len;
		}
	}
	for (int i = 0; i < m; i ++)
		cout << a[i].ans << '\n';
	cout << clock();
	return 0;
}