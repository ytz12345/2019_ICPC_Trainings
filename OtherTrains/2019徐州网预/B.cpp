#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, a[N], b[N], c[N], d[N], f[N];

int fa(int x) {
	return x == f[x] ? x : (f[x] = fa(f[x]));
}

void un(int x, int y) {
	x = fa(x), y = fa(y);
	if (x == y) return;
	if (x > y) f[y] = x;
	else f[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i] >> b[i];
		if (a[i] == 1) {
			c[++ c[0]] = b[i];
		}
	}
	sort (c + 1, c + c[0] + 1);
	c[0] = unique(c + 1, c + c[0] + 1) - c - 1;
	for (int i = 1; i <= c[0]; i ++) 
		f[i] = i, d[i] = 0;
	for (int k, j, i = 1; i <= m; i ++) {
		if (a[i] == 1) {
			j = lower_bound(c + 1, c + c[0] + 1, b[i]) - c;
			if (d[j] == 1) continue;
			d[j] = 1;
			if (j != 1 && d[j - 1] == 1 && c[j - 1] + 1 == c[j]) un(j - 1, j);
			if (j != c[0] && d[j + 1] == 1 && c[j] + 1 == c[j + 1]) un(j, j + 1);  
		}
		else {	
			j = lower_bound(c + 1, c + c[0] + 1, b[i]) - c;
			if (c[j] != b[i] || d[j] == 0) k = b[i];
			else k = c[fa(j)] + 1;
			if (k > n) k = -1;
			printf("%d\n", k);
		}
	}
}