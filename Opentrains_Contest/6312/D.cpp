#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = j; i <= k; i ++)

using namespace std;

const int N = 510;

char s[N][N], t[N][N];

int n, m, ans;

int main() {
	ios::sync_with_stdio(false);
	scanf("%d %d", &n, &m);
	rep(i, 1, n) scanf("%s", t[i] + 1);
	if (n > m) {
		rep(i, 1, m) rep(j, 1, n) s[i][j] = t[j][i];
		swap(n, m);
	}
	else {
		rep(i, 1, n) rep(j, 1, m) s[i][j] = t[i][j];
	}//n <= m
	if (n == 1) {
		rep(i, 2, m - 1) ans += s[1][i] == '.';
	} 	
	else if (n == 2) {
		rep(i, 2, m - 1) ans += s[1][i] == '.' && s[2][i] == '.';
	}
	else {
		rep(i, 2, n - 1) ans |= s[i][1] == '#' || s[i][m] == '#';
		rep(i, 2, m - 1) ans |= s[1][i] == '#' || s[n][i] == '#';
		ans ^= 1;
		rep(i, 2, n - 1) rep(j, 2, m - 1) ans += s[i][j] == '.';
	}
	cout << ans << '\n';
}