#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int t, n;

int s, f[N], a[N];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n; s = 0;
		for (int i = 2; i <= n; i ++) {
			int x = i, j = 0; f[i] = 0;
			for (; x > 0; j ++) {
				if (x & 1) x >>= 1;
				else {
					f[i] = 1 << j;
					break;
				}
			}
			if (!f[i]) {
				if ((1 << j) <= n) f[i] = 1 << j;
				else f[i] = 1;
			}
			s += f[i] & i;
		}
		printf("%d\n", s);
		for (int i = 2; i <= n; i ++)
			printf("%d%c", f[i], i == n ? '\n' : ' ');
	}
	return 0;
}