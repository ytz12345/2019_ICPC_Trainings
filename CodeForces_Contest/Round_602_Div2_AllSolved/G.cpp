#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N], b[N], c[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++) 
		cin >> a[i], b[i] = i;
	sort (b, b + n, [&](int x, int y){return a[x] > a[y];});
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < a[b[i]]; j ++)
			c[(i + j) %  (n + 1)][b[i]] = 1;
	printf("%d\n", n + 1);
	for (int i = 0; i <= n; i ++, puts(""))
		for (int j = 0; j < n; j ++)
			printf("%d", c[i][j]);
	return 0;
}