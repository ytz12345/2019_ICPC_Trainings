#include <bits/stdc++.h>

using namespace std;

int a[1100][1100];

void dfs(int n) {
	if (n == 1) {
		a[0][0] = 1;
		return;
	}
	dfs(n >> 1);
	int x = n >> 1;
	int y = n;
	for (int i = x; i < y; i ++)
		for (int j = 0; j < x; j ++)
			a[i][j] = a[i - x][j];
	for (int i = 0; i < x; i ++)
		for (int j = x; j < y; j ++)
			a[i][j] = a[i][j - x];
	for (int i = x; i < y; i ++)
		for (int j = x; j < y; j ++)
			a[i][j] = -a[i - x][j - x];
}

int main() {
	int n;
	cin >> n;
	dfs(n);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			printf("%d%c", a[i][j], j + 1 == n ? '\n' : ' ');
	return 0;
}