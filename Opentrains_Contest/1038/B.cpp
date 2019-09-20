#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N], b[N][N];

__int128 x;

int main() {
	cin >> n; x += 1;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	printf("%d\n", n * 2 - 1);
	for (int i = 1; i < n * 2; i ++)
		for (int j = 1; j < n * 2; j ++)
			printf("%d%c", a[(i + j) % n + 1], j + 1 == n * 2 ? '\n' : ' ');
	return 0;
}