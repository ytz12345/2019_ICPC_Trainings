#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, f[2][N], a[N], ans[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	f[0][n] = f[1][n] = 1;
	for (int i = n - 1; i >= 1; i --) {
		if (a[i] <= a[i + 1]) f[0][i] = f[0][i + 1] + 1, f[1][i] = 1;
		else                  f[0][i] = 1, f[1][i] = f[1][i + 1] + 1;
	}
	for (int i = 2; i <= n; i ++) {
		int j = 1, c0 = 0, c1 = 0;
		while (j <= n) {
			if (max(f[0][j], f[1][j]) >= i) j += max(f[0][j], f[1][j]);
			else {
				c1 += min(n + 1 - j, i) - max(f[0][j], f[1][j]);
				j += i;
			}
			c0 ++;
		}
		ans[0][i] = c0, ans[1][i] = c1;;
	}
	cin >> m;
	for (int x; m --; ) {
		cin >> x;
		cout << ans[0][x] << ' ' << ans[1][x] << '\n';
	}
	return 0;
}