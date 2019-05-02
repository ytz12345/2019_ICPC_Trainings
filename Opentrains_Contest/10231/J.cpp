#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int n, K, a[N], b[N][100], c[N], d[N];

int work() {
	int cc = 0;
	for (int f, j, i = 0; ; i ++) {
		j = i % n;
		for (int rp = 0; rp < d[i]; rp ++) {
			f = 0;
			for (int t = 0; t < min(c[n], c[j]); t ++) {
				if (b[j][c[j] - t - 1] != b[n][c[n] - t - 1]) {
					f = 1;
					if (b[n][c[n] - t - 1] == 1) b[n][c[n] ++] = 0, b[j][c[j] ++] = 1;
					else b[n][c[n] ++] = 1, b[j][c[j] ++] = 0;
					break;
				}
			}
			if (!f) b[n][c[n] ++] = 1, b[j][c[j] ++] = 0;
			cc ++;
			if (cc == K) break;
		}
		if (cc == K) break;
	}
	int cnt = 0;
	for (int i = 0; i < c[n]; i ++)
		cnt += b[n][i];
	return cnt;
}

int main() {
	freopen("checkers.in","r",stdin);
	freopen("checkers.out","w",stdout);
	cin >> n >> K;
	for (int i = 0; i < n; i ++) {
		char x;
		cin >> x;
		a[i] = x == 'W';
	}
	int ans = 0;
	for (int i = 0, j = 1 << K; i < j; i ++) {
		c[n] = 0;
		for (int k = 0; k < n; k ++)
			c[k] = 1, b[k][0] = (a[k]);
		for (int k = 0; k < K; k ++)
			d[k] = ((i >> k) & 1) + 1;
		ans = max(ans, work());
	}
	cout << ans;
	return 0;
}