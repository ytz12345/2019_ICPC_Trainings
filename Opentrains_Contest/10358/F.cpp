#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;

int f[2][N];

int son[2][N];

int ans;

int dfs(int x) {
	if (!son[0][x]) {
		if (f[1][x] == f[0][x] && !son[1][x]) return 1;
		else {
			if (f[0][x] != 0) f[0][x] = 0, ans ++;
			return 0;
		}
	}
	else {
		int r = dfs(son[0][x]) & (f[1][x] == f[0][x]);
		if (!r && f[0][x] != 0) ans ++, f[0][x] = 0;
		return r;
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 2; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> f[i][j];
			if (f[i][j]) son[i][f[i][j]] = j; 
		}
	}
	for (int i = 1; i <= n; i ++)
		if (!f[0][i])
			dfs(i);
	for (int i = 1; i <= n; i ++)
		ans += f[0][i] != f[1][i];
	cout << ans << endl;
	return 0;
}