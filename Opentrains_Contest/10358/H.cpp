#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

typedef pair<int, int> piir;

struct node {
	int x[2], y[2], ans;
}a[N];

char s[1010][1010];

int sum[1010][1010];

int b[1010][1010];

int p[1010][1010];

int f[1000100], mx[1010][1010];

vector <piir> e[1010];

int n, m;

int sta[1001000], top;

inline int fa(int x) {
	static int y;
	sta[++ top] = x;
	while (f[sta[top]] != sta[top]) sta[top + 1] = f[sta[top]], top ++;
	y = sta[top];
	while (top) f[sta[top --]] = y;
	return y;
}

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
	for (int x, y, l, r, mid, ps, i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (s[i][j] == '#') continue;
			l = 1, r = min(min(i, n + 1 - i), min(j, n + 1 - j)), ps = 0;
			while (l <= r) {
				mid = l + r >> 1;
				if (calc(i, j, mid * 2 - 1) == 0) ps = mid, l = mid + 1;
				else r = mid - 1;
			}
			mx[i][j] = ps * 2 - 1;
			if (i != 1 && s[i - 1][j] != '#') e[min(mx[i][j], mx[i - 1][j])].push_back(piir(p[i][j], p[i - 1][j]));
			if (j != 1 && s[i][j - 1] != '#') e[min(mx[i][j], mx[i][j - 1])].push_back(piir(p[i][j], p[i][j - 1]));
		}
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			f[p[i][j]] = p[i][j];
	for (int len = n & 1 ? n : (n - 1); len > 0; len -= 2) {
		for (piir i : e[len]) 
			un(i.first, i.second);
		for (int i = 0; i < m; i ++) {
			if (a[i].ans != 0) continue;
			if (fa(p[a[i].x[0]][a[i].y[0]]) == fa(p[a[i].x[1]][a[i].y[1]])) 
				a[i].ans = len;
		}
	}
	for (int i = 0; i < m; i ++)
		cout << a[i].ans << '\n';
	return 0;
}