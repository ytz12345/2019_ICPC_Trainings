#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, m, k;

int dp[N][4];

int f3[25][25][25], f2[25][25];

struct pre {
	int i, j, k;
	pre(){}
	pre(int i, int j, int k):i(i), j(j), k(k){}
}g3[25][25][25], g2[25][25];

int a[N];

vector <int> e[N];

void dfs(int u) {
	if (u > m) {
		for (int i = 0; i <= k; i ++)
			dp[u][i] = 1;
		dp[u][a[u]] = 0;
		return;
	}
	for (int v : e[u])
		dfs(v);
	if (k == 3) {
		memset (f3, 0x3f, sizeof f3);
		f3[0][0][0] = 0;
		for (int v, i = 1; i <= e[u].size(); i ++) {
			v = e[u][i - 1];
			for (int s = i; s >= 0; s --)
				for (int i1 = 0; i1 <= i; i1 ++)
					for (int i2 = 0; i1 + i2 <= i; i2 ++) {
						int i3 = s - i1 - i2;
						if (i1 != 0) {
							if (f3[i1][i2][i3] > f3[i1 - 1][i2][i3] + dp[v][1]) {
								f3[i1][i2][i3] = f3[i1 - 1][i2][i3] + dp[v][1];
								g3[i1][i2][i3] = pre(i1 - 1, i2, i3);
							}
						}
						if (i2 != 0) {
							if (f3[i1][i2][i3] > f3[i1][i2 - 1][i3] + dp[v][2]) {
								f3[i1][i2][i3] = f3[i1][i2 - 1][i3] + dp[v][2];
								g3[i1][i2][i3] = pre(i1, i2 - 1, i3);
							}
						}
						if (i3 != 0) {
							if (f3[i1][i2][i3] > f3[i1][i2][i3 - 1] + dp[v][3]) {
								f3[i1][i2][i3] = f3[i1][i2][i3 - 1] + dp[v][3];
								g3[i1][i2][i3] = pre(i1, i2, i3 - 1);
							}
						}
						if (s != i) {
							f3[i1][i2][i3] += dp[v][0];
						}
					}
		}	
	}
	else {
		memset (f2, 0, sizeof f2);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int t, i = 1; i <= m; i ++) {
		cin >> t;
		for (int x, j = 1; j <= t; j ++) {
			cin >> x;
			if (x > 0) e[i].push_back(x + m);
			else e[i].push_back(-x);
		}
	}
	dfs(1);
	return 0;
}