#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, m, k;

int dp[N][4];

int f3[25][25][25][25], f2[25][25][25];

struct pre {
	int i, j, k;
	pre(){}
	pre(int i, int j, int k):i(i), j(j), k(k){}
}g3[25][25][25][25], g2[25][25][25], cho[N][4];

int a[N];

vector <int> e[N];

int pr[N][4];

void dfs(int u) {
	if (u > m) {
		for (int i = 0; i <= k; i ++)
			dp[u][i] = 1;
		dp[u][a[u - m]] = 0;
		return;
	}
	for (int v : e[u])
		dfs(v);
	if (k == 3) {
		memset (f3, 0x3f, sizeof f3);
		f3[0][0][0][0] = 0;
		for (int v, i = 1; i <= e[u].size(); i ++) {
			v = e[u][i - 1];
			for (int s = i; s >= 0; s --)
				for (int i1 = 0; i1 <= s; i1 ++)
					for (int i2 = 0; i1 + i2 <= s; i2 ++) {
						int i3 = s - i1 - i2;
						if (i1 != 0) {
							if (f3[i][i1][i2][i3] > f3[i - 1][i1 - 1][i2][i3] + dp[v][1]) {
								f3[i][i1][i2][i3] = f3[i - 1][i1 - 1][i2][i3] + dp[v][1];
								g3[i][i1][i2][i3] = pre(i1 - 1, i2, i3);
							}
						}
						if (i2 != 0) {
							if (f3[i][i1][i2][i3] > f3[i - 1][i1][i2 - 1][i3] + dp[v][2]) {
								f3[i][i1][i2][i3] = f3[i - 1][i1][i2 - 1][i3] + dp[v][2];
								g3[i][i1][i2][i3] = pre(i1, i2 - 1, i3);
							}
						}
						if (i3 != 0) {
							if (f3[i][i1][i2][i3] > f3[i - 1][i1][i2][i3 - 1] + dp[v][3]) {
								f3[i][i1][i2][i3] = f3[i - 1][i1][i2][i3 - 1] + dp[v][3];
								g3[i][i1][i2][i3] = pre(i1, i2, i3 - 1);
							}
						}
						if (s != i) {
							if (f3[i][i1][i2][i3] > f3[i - 1][i1][i2][i3] + dp[v][0]) {
								f3[i][i1][i2][i3] = f3[i - 1][i1][i2][i3] + dp[v][0];
								g3[i][i1][i2][i3] = pre(i1, i2, i3);
							}
						}
					}
		}	
		dp[u][0] = dp[u][1] = dp[u][2] = dp[u][3] = 1e9;
		int s = e[u].size();
		for (int i1 = 0; i1 <= s; i1 ++)
			for (int i2 = 0; i1 + i2 <= s; i2 ++)
				for (int i3 = 0; i1 + i2 + i3 <= s; i3 ++) {
					int mmax = 0, maxi;
					if (i1 > mmax) mmax = i1, maxi = 1;
					if (i2 > mmax) mmax = i2, maxi = 2;
					if (i3 > mmax) mmax = i3, maxi = 3;
					int cnt = (i1 == mmax) + (i2 == mmax) + (i3 == mmax);
					if (cnt != 1) {
						if (dp[u][0] > f3[s][i1][i2][i3]) {
							dp[u][0] = f3[s][i1][i2][i3];
							cho[u][0] = pre(i1, i2, i3);
						}
					}
					else {
						if (dp[u][maxi] > f3[s][i1][i2][i3]) {
							dp[u][maxi] = f3[s][i1][i2][i3];
							cho[u][maxi] = pre(i1, i2, i3);
						}
					}
				}
		for (int j = 0; j <= k; j ++) {
			pre now = cho[u][j];
			for (int v, i = (int)e[u].size(); i > 0; i --) {
				v = e[u][i - 1];
				int vv = 0;
				if (g3[i][now.i][now.j][now.k].i != now.i) vv = 1;
				if (g3[i][now.i][now.j][now.k].i != now.j) vv = 2;
				if (g3[i][now.i][now.j][now.k].i != now.k) vv = 3;
				print3(v, vv);
				now = g3[i][now.i][now.j][now.k];
			}
		}
		
		/*for (int i = 0; i < 4; i ++) {
			printf("%d %d %d\n", u, i, dp[u][i]);
		}*/
	}
	else {
		memset (f2, 0, sizeof f2);
		f2[0][0][0] = 0;
		for (int v, i = 1; i <= e[u].size(); i ++) {
			v = e[u][i - 1];
			for (int s = i; s >= 0; s --)
				for (int i1 = 0; i1 <= s; i1 ++) {
					int i2 = s - i1;
					if (i1 != 0) {
						if (f2[i][i1][i2] > f2[i - 1][i1 - 1][i2] + dp[v][1]) {
							f2[i][i1][i2] = f2[i - 1][i1 - 1][i2] + dp[v][1];
							g2[i][i1][i2] = pre(i1 - 1, i2, 0);
						}
					}
					if (i2 != 0) {
						if (f2[i][i1][i2] > f2[i - 1][i1][i2 - 1] + dp[v][2]) {
							f2[i][i1][i2] = f2[i - 1][i1][i2 - 1] + dp[v][2];
							g2[i][i1][i2] = pre(i1, i2 - 1, 0);
						}
					}
					if (s != i) {
						if (f2[i][i1][i2] > f2[i - 1][i1][i2] + dp[v][0]) {
							f2[i][i1][i2] = f2[i - 1][i1][i2] + dp[v][0];
							g2[i][i1][i2] = pre(i1, i2, 0);
						}
					}
				}
		}	
		dp[u][0] = dp[u][1] = dp[u][2] = 1e9;
		int s = e[u].size();
		for (int i1 = 0; i1 <= s; i1 ++)
			for (int i2 = 0; i1 + i2 <= s; i2 ++) {
				int mmax = 0, maxi;
				if (i1 > mmax) mmax = i1, maxi = 1;
				if (i2 > mmax) mmax = i2, maxi = 2;
				int cnt = (i1 == mmax) + (i2 == mmax);
				if (cnt != 1) {
					if (dp[u][0] > f2[s][i1][i2]) {
						dp[u][0] = f2[s][i1][i2];
						cho[u][0] = pre(i1, i2, 0);
					}
				}
				else {
					if (dp[u][maxi] > f2[s][i1][i2]) {
						dp[u][maxi] = f2[s][i1][i2];
						cho[u][maxi] = pre(i1, i2, 0);
					}
				}
			}
	}
}

void print3(int u, int v) {
	printf("! %d %d\n", u, v);
	if (u > m) {
		if (v != a[u - m]) cout << u - m << ' ' << v << '\n';
		return;
	}
	
}

void print2(int u, int v) {

}

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios::sync_with_stdio(false);
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
	cout << dp[1][1] << endl;
	if (k == 3) print3(1, 1);
	if (k == 2) print2(1, 1);
	return 0;
}