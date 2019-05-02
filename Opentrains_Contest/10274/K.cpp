#include <bits/stdc++.h>

using namespace std;

int t;

set <int> ans;

int p[4][3] = {
	1, 2, 3,
	4, 5, 6,
	7, 8, 9, 
	-1, 0, -1
};

void dfs(int x, int y, int s) {
	if (x >= 4 || y >= 3 || p[x][y] == -1 || s > 200) return; 
	ans.insert(s);
	ans.insert(s * 10 + p[x][y]);
	dfs(x + 1, y, s);
	dfs(x + 1, y, s * 10 + p[x][y]);
	dfs(x, y + 1, s);
	dfs(x, y + 1, s * 10 + p[x][y]);
	if (s != 0 || p[x][y] != 0) dfs(x, y, s * 10 + p[x][y]);
}

int main() {
	ios::sync_with_stdio(false);
	dfs(0, 0, 0);
	cin >> t;
	int n, m, dis;
	while (t --) {
		cin >> n;
		dis = 1e9;
		for (int i : ans)
			if (abs(i - n) < dis)
				dis = abs(i - n), m = i;
		cout << m << '\n';
	}
	return 0;
}