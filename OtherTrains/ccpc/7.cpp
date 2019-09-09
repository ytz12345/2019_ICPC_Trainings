#include <bits/stdc++.h>

using namespace std;

char a[1100][1100];

int t, n;

void dfs(int x) {
	if (x == 2) {
		a[1][1] = a[1][2] = a[2][2] = 'C';
		a[2][1] = 'P';
		return;
	}
	int y = x >> 1;
	dfs(y);
	for (int i = 1; i <= y; i ++)
		for (int j = 1; j <= y; j ++) {
			a[i + y][j + y] = a[i][j + y] = a[i][j];
			a[i + y][j] = a[i][j] == 'P'? 'C':'P';
		}
}

int main() {
	for (cin >> t; t --; ) {
		cin >> n;
		dfs(n = 1 << n);
		for (int i = 1; i <= n; i ++) {
			a[i][n + 1] = 0;
			puts(a[i] + 1);
		}
	}
}