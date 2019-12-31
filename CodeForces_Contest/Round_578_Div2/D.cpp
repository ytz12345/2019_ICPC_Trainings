#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2019;

int n, k;

char s[N][N];

int r[N][N], c[N][N];

int d[N][3], f[N];

int ans, tmp;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			r[i][j] = r[i][j - 1] + (s[i][j] == 'B'); 
			c[i][j] = c[i - 1][j] + (s[i][j] == 'B');
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (r[i][j - 1] == 0 && r[i][j + k - 1] == r[i][n]) {
				d[i][0] = 1;
				d[i][1] = d[i][2] = j;
				while (1) {
					j ++;
					if (j + k - 1 > n || !(r[i][j - 1] == 0 && r[i][j + k - 1] == r[i][n])) break;
					d[i][2] = j;
				}
				break;
			}
		}
	}
	for (int i = 1; i + k - 1 <= n; i ++) {
		tmp = 0;
		for (int j = 1; j <= n; j ++) { // for row
			if (i <= j && j <= i + k - 1);// tmp += r[j][k] == r[j][n];
			else tmp += r[j][n] == 0; 
		}
		for (int j = 1; j <= n; j ++) { // for column
			if (j <= k) tmp += c[i - 1][j] == 0 && c[i + k - 1][j] == c[n][j];
			else tmp += c[n][j] == 0;
		}
		for (int j = 1; j <= n; j ++) f[j] = 0;
		for (int j = i; j <= i + k - 1; j ++) 
			if (d[j][0])
				f[d[j][1]] ++, f[d[j][2] + 1] --;
		for (int j = 1; j + k - 1 <= n; j ++)
			f[j] += f[j - 1];
		ans = max(ans, tmp + f[1]);
		for (int j = 2; j + k - 1 <= n; j ++) {
			tmp -= c[n][j + k - 1] == 0;
			tmp += c[i - 1][j + k - 1] == 0 && c[i + k - 1][j + k - 1] == c[n][j + k - 1];
			tmp -= c[i - 1][j - 1] == 0 && c[i + k - 1][j - 1] == c[n][j - 1]; 
			tmp += c[n][j - 1] == 0;
			ans = max(ans, tmp + f[j]);
		} 
	}
	cout << ans << endl;
	return 0;
}