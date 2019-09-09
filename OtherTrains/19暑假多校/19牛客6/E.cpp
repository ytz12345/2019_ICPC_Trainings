#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int t, n;

int a[N][N];

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt ++) {
		scanf("%d", &n);
		if (n % 4 > 1) printf("Case #%d: No\n", tt);
		else {
			printf("Case #%d: Yes\n", tt);
			memset (a, 0, sizeof a);
			if (n % 4 == 0) {
				for (int i = 1; i <= n / 2; i ++)
					for (int j = 1; j <= n / 2; j ++)
						if (i != j)
							a[i][j] = 1;
				for (int i = 1; i <= n / 2; i ++) {
					for (int j = 0; j < n / 4; j ++) {
						int k = i + n / 2 + j;
						if (k > n) k -= n / 2;
						a[i][k] = a[k][i] = 1;
					}
				}
				for (int i = 1; i <= n; i ++) {
					for (int j = 1; j <= n; j ++)
						printf("%d", a[i][j]);
					puts("");
				}
				for (int i = 1; i <= n / 2; i ++)
					printf("%d ", i + n / 2);
				for (int i = 1; i < n / 2; i ++)
					printf("%d ", i + 1);
				puts("1");
			}
			else {
				for (int i = 1; i <= n / 2; i ++)
					for (int j = 1; j <= n / 2; j ++)
						if (i != j)
							a[i][j] = 1;
				for (int i = 1; i <= n / 2; i ++) {
					for (int j = 0; j < n / 4; j ++) {
						int k = i + n / 2 + j;
						if (k >= n) k -= n / 2;
						a[i][k] = a[k][i] = 1;
					}
				}
				for (int i = 1; i <= n / 2; i ++) {
					a[n][i] = a[i][n] = 1;
				}
				for (int i = 1; i <= n; i ++) {
					for (int j = 1; j <= n; j ++)
						printf("%d", a[i][j]);
					puts("");
				}
				for (int i = 1; i <= n / 2; i ++)
					printf("%d ", i + n / 2);
				for (int i = 1; i < n / 2; i ++)
					printf("%d ", i + 1);
				if (n != 1) printf("1 %d\n", n);
				else puts("1");
			}
		}
	} 
}