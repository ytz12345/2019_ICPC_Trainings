#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll t, n, k;

vector <int> e[N];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> k;
		if ((1ll * n * (n + 1) / 2) % k != 0) {
			puts("no");
			continue;
		}
		else if (n % 2 == 0) {
			if ((n / 2) % k == 0) {
				puts("yes");
				for (int i = 1, j = 1; i <= k; i ++) {
					int up = (n / 2) / k;
					for (int cnt = 0; cnt < up; cnt ++) {
						printf("%d %lld ", j, n + 1 - j);
						j ++;
					}
					puts("");
				}
			}
			else {
				puts("no");
				continue;
			}
		}
		else {
			if (n == 1) {
				puts("yes\n1");
			}
			else if (n == k) {
				puts("no");
			}
			else if (k == 1){
				puts("yes");
				for (int i = 1; i <= n; i ++)
					printf("%d ", i);
				puts("");
			}
			else {
				ll m = n / k;
				for (int i = 1; i <= k; i ++) e[i].clear();
				e[1].push_back(1);
				e[1].push_back(k);
				for (int i = 3; i <= m; i ++)
					e[1].push_back((k + 1) / 2);
				for (int i = 2; i <= k; i ++) {
					e[i].push_back(e[i - 1][0] + 1);
					e[i].push_back(e[i - 1][1] - 2);
					if (e[i][1] <= 0) e[i][1] += k;
					for (int j = 2; j < m; j ++) {
						if (!(j & 1)) {
							e[i].push_back(e[i - 1][j] + 1);
							if (e[i][j] > k) e[i][j] -= k;
						}
						else {
							e[i].push_back(e[i - 1][j] - 1);
							if (e[i][j] <= 0) e[i][j] += k;
						}

					}
				}
				puts("yes");
				for (int i = 1; i <= k; i ++) {
					for (int j = 0; j < m; j ++)
						printf("%lld ", e[i][j] + j * k);
					puts("");
				}
			}
		}
	}
	return 0;
}