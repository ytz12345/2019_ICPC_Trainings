#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 1;

int c[N];

int main() {
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> x, c[x] ++;
	for (int f, j, i = 1; i < N; i ++) {
		if (c[i] != 1) continue;
		for (f = 1, j = i << 1; j < N; j += i)
			if (c[j] != 0) {
				f = 0;
				break;
			}
		if (f) printf("%d ", i);
	}
	return 0;
}