#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 600;

int n, m;

char s[N][N];

int a[N][N];

void bfs(int x, int y) {
	queue <int> qx, qy;
	qx.push(x), qy.push(y);
	a[x][y] = 1;
	while (!qx.empty()) {
		x = qx.front(), y = qy.front();
		//printf("%d %d\n", x, y);
		qx.pop(), qy.pop();
		if (x + 1 != n && s[x + 1][y] == '.') {
			if (!a[x + 1][y])
				qx.push(x + 1), qy.push(y), a[x + 1][y] = 1;
		}
		else {
			if (y != 0 && s[x][y - 1] == '.') {
				if (!a[x][y - 1])
					qx.push(x), qy.push(y - 1), a[x][y - 1] = 1;
			}
			if (y + 1 != m && s[x][y + 1] == '.') {
				if (!a[x][y + 1])
					qx.push(x), qy.push(y + 1), a[x][y + 1] = 1;
			}
		}
	}
} 

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	for (int i = 0; i < m; i ++) 
		if (s[0][i] == '.') 
			bfs(0, i);
	int f = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] == '.' && !a[i][j]) {
				f = 1;
				s[i][j] = 'X';
				break;
			}
		}
		if (f) break;
	}
	if (f) {
		puts("Yes");
		for (int i = 0; i < n; i ++)
			puts(s[i]);
	}
	else {
		puts("No");
	}
	return 0;
}