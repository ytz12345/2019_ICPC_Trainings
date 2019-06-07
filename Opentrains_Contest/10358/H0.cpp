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

int f[1000100], ad[2][1010][10101];

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
	//cout << clock() << endl;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			f[p[i][j]] = p[i][j];
	for (int len = n & 1 ? n : (n - 1); len > 0; len -= 2) {
		for (int i = len / 2 + 1; i + len / 2 <= n; i ++)
			for (int j = len / 2 + 1; j + len / 2 <= n; j ++)  {
				if ((b[i][j] = calc(i, j, len))) continue;
				if (!ad[0][i][j] && i != len / 2 + 1 && !b[i - 1][j]) ad[0][i][j] = 1, un(p[i][j], p[i - 1][j]);
				if (!ad[1][i][j] && j != len / 2 + 1 && !b[i][j - 1]) ad[1][i][j] = 1, un(p[i][j], p[i][j - 1]); 
			}
		for (int i = 0; i < m; i ++) {
			if (a[i].ans != 0) continue;
			if (fa(p[a[i].x[0]][a[i].y[0]]) == fa(p[a[i].x[1]][a[i].y[1]])) 
				a[i].ans = len;
		}
	}
	for (int i = 0; i < m; i ++)
		cout << a[i].ans << '\n';
	//cout << clock();
	return 0;
}