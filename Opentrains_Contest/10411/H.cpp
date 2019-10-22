#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int n, m, k;

int a[N], b[N];

void no() {
	puts("-1");
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> n >> m;
	if (k > n) no();
	for (int i = 1; i <= k; i ++)
		cin >> b[i];
	if (b[1] == -1) b[1] = 1;
	for (int i = 2; i <= k; i ++) {
		if (b[i] == -1) b[i] = b[i - 1];
		else if (b[i] < b[i - 1]) no();
	}
	int i = 0, x = m, j = k, y;
	for ( ; i + k <= n && x > 0; x --) {
		while (j > 0 && b[j] == x) j --;
		for (y = j; y -- && i <= n; ) a[++ i] = x;
	}
	if (i + k < n) no();
	for (int i = 1; i <= k; i ++)
		a[n - k + i] = b[i];
	for (int i = 1; i <= n; i ++)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	return 0;
}