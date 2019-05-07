#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

const int d = 3;

vector <int> a[N];

int n, m, q;

char s1[N], s2[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q >> s1 >> s2;
	for (int i = 0; i <= n; i ++) {
		if (i < d) a[i].resize(m + 1, 0);
		else a[i].resize(d, 0);
	}
	for (int i = 1; i <= n; i ++)
		a[i][0] = s1[i - 1] == '1';
	for (int i = 1; i <= m; i ++)
		a[0][i] = s2[i - 1] == '1';
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= (i < d ? m : (d - 1)); j ++)
			a[i][j] = !(a[i][j - 1] & a[i - 1][j]);
	for (int x, y, z, t; q --; ) {
		cin >> x >> y;
		if (x < d || y < d) z = a[x][y];
		else t = min(x, y), z = a[x - t + d - 1][y - t + d - 1];
		puts(z ? "Yes" : "No");
	}
	return 0;
}