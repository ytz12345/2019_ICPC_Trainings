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

int p[1010][1010];

int f[1000100];//, sz[1000100];

int n, m;

inline int fa(int x) {return x == f[x] ? x : (f[x] = fa(f[x]));}

inline void un(int x, int y) {x = fa(x), y = fa(y); f[y] = x;/*if (sz[y] > sz[x]) f[x] = y, sz[y] += sz[x]; else f[y] = x, sz[x] += sz[y];*/}

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

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> s[i];
		for (int j = 0; j < n; j ++) {
			sum[i][j] = (j == 0 ? 0 : sum[i][j - 1]) +
						(i == 0 ? 0 : sum[i - 1][j]) -
						(i != 0 && j != 0 ? sum[i - 1][j - 1] : 0) +
						(s[i][j] == '#');
			p[i][j] = i * n + j + 1;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i ++) {
		cin >> a[i].x[0] >> a[i].y[0] >> a[i].x[1] >> a[i].y[1];
		a[i].x[0] --, a[i].y[0] --;
		a[i].x[1] --, a[i].y[1] --;
	}
	for (int k = n, len = 1; k > 0; k -= 2, len += 2) {
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				f[p[i][j]] = p[i][j];//, sz[p[i][j]] = 1;
		for (int i = len / 2; i + len / 2 < n; i ++)
			for (int j = len / 2; j + len / 2 < n; j ++) 
				b[i][j] = calc(i, j, len);
		for (int i = len / 2; i + len / 2 < n; i ++)
			for (int j = len / 2; j + len / 2 < n; j ++) {
				if (b[i][j]) continue;
				if (i != len / 2 && !b[i - 1][j]) un(p[i][j], p[i - 1][j]);
				if (j != len / 2 && !b[i][j - 1]) un(p[i][j], p[i][j - 1]); 
			}
		for (int i = 0; i < m; i ++) {
			if (fa(p[a[i].x[0]][a[i].y[0]]) == fa(p[a[i].x[1]][a[i].y[1]])) 
				a[i].ans = len;
		}
	}
	for (int i = 0; i < m; i ++)
		cout << a[i].ans << '\n';
	//cout << clock();
	return 0;
}