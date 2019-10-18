#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, b, c, a[N], d[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> c >> b;
	for (int i = 1; i <= b; i ++) {
		cin >> d[i];
		a[d[i]] = -1;
	}
	for (int i = n; i > 1; ) {
		if (a[i] == -1) a[i] = 0, i --;
		else {
			if (c > 1) a[i] = 1, a[-- i] = 0, i --, c -= 2;
			else a[i] = 0, i --;
		}
	}
	if (c > 0) a[1] = 1;
	for (int i = 1; i <= n; i ++)
		printf("%d", a[i]);
	return 0;
}