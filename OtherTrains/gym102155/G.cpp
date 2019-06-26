#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int k, n, m, num, pos, cnt;

int a[N], b[N];

int getint() {
	if (cnt == 0) {
		num --;
		while (pos > 0 && b[pos] == num) pos --;
		if (pos <= 0) return -1;
		cnt = pos;
	}
	cnt --;
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> n >> m; 
	num = m + 1, pos = k;
	for (int i = 1; i <= k; i ++)
		cin >> b[i];
	if (b[1] == -1) b[1] = 1;
	if (k > n) return puts("-1"), 0;
	for (int i = 2; i <= k; i ++)
		if (b[i - 1] != -1 && b[i] != -1 && b[i] < b[i - 1])
			return puts("-1"), 0;
	for (int i = 2; i <= k; i ++)
		if (b[i] == -1)
			b[i] = b[i - 1];
	for (int i = 1; i <= n - k; i ++) {
		a[i] = getint();
		if (a[i] < 0) return puts("-1"), 0;
	}
	for (int i = 1; i <= k; i ++)
		a[n - k + i] = b[i];
	for (int i = 1; i <= n; i ++)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	return 0;
}