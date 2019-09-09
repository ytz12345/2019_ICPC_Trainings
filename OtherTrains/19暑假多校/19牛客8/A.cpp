#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n, m, ans;

char s[N][N];

int h[N][N];

int a[N][N];

int q[N], top;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) 
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] == '1') h[i][j] = h[i - 1][j] + 1, a[i][j] = a[i][j - 1] + 1;
			else h[i][j] = a[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		top = 0;
		for (int j = 0; j <= m + 1; j ++) q[j] = 0;
		for (int j = 1; j <= m + 1; j ++) {
			while (top > 0 && h[i][q[top]] > h[i][j]) {
				if (a[i + 1][j - 1] - a[i + 1][q[top] - 1] != (j - 1) - (q[top] - 1)) {
					ans ++;
				}
				top --;
			}
			if (h[i][j]) {
				if (h[i][j] == h[i][q[top]]) continue;
				top ++;
				if (!q[top]) q[top] = j;
				h[i][q[top]] = h[i][j];
			}
		}
 	}
	cout << ans << endl;
	return 0;
}