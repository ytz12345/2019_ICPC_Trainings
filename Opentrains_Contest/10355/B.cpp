#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

typedef pair<int, int> piir;

int n, m, k, c;

int b[110][110];

piir a[N];

char path[N];

int x, y, now;

void r() {
	y ++, c += b[x][y];
	path[now ++] = 'R';
}

void d() {
	x ++, c += b[x][y];
	path[now ++] = 'D';
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i ++) {
		cin >> a[i].first >> a[i].second;
		b[a[i].first][a[i].second] ++;
	}
	x = 1, y = 1, c = b[x][y];
	while (x != n || y != m) {
		if (x == n) r();
		else if (y == m) d();
		else {
			int f1 = 0;
			for (int i = y + 1; i <= m; i ++)
				if (b[x][i]) {
					f1 = 1;
					break;
				}
			if (f1) r();
			else d();
		}
	}
	path[now] = 0;
	if (c == k) puts(path);
	else puts("Impossible");
	return 0;
}