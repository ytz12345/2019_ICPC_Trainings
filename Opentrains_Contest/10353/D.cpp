#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e2 + 5;

int n, k, a[N], b[N];

int p = -1, q = -1;

int main() {
	int tp, tq, bp, bq, flag;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= k; j ++) {
			tp = 1, tq = 1, flag = 1;
			for (int x = 1; x <= n; x ++) {
				if (x == i) continue;
				bp = 1, bq = 1;
				for (int y = 1; y <= k; y ++) {
					if (a[x] * j < a[i] * y) {
						if (y == 1) flag = 0;
						break;
					}
					bp = a[x] * j, bq = a[i] * y;
				}
				if (!flag) break;
				if (bp * tq > tp * bq) tp = bp, tq = bq;
			}
			if (!flag) continue;
			if (p == -1 || tp * q < p * tq) {
				p = tp, q = tq;
				for (int x = 1; x <= n; x ++) {
					for (int y = 1; y <= k; y ++) {
						if (a[x] * j < a[i] * y) break;
						b[x] = y;
					}
				}
			}
		}
	for (int i = 1; i <= n; i ++)
		printf("%d ", b[i]);
	return 0;
}