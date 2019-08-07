#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int t, n, m, a[N], b[N], c[N], d[N], f[N], g[N];

int ans[N], pre[N];

int mmax(int x, int y) {
	return f[x] > f[y] ? x : y;
}

int lb(int x) {
	return  x & -x;
}

int ask(int i) {
	int res = 0;
	while (i > 0) {
		res = mmax(res, c[i]);
		i -= lb(i);
	}
	return res;
}

void add(int i, int x) {
	while (i <= n) {
		c[i] = mmax(c[i], x);
		i += lb(i);
 	}
}

void calc(int k) {
	m = 0;
	for (int i = 1; i <= n; i ++)
		c[i] = d[i] = g[i] = 0;
	for (int i = 1; i <= k; i ++)
		d[b[i]] = 1;
	for (int p, i = 1; i <= n; i ++)
		if (d[i]) {
			p = ask(a[i]);
			f[a[i]] = f[p] + 1;
			pre[a[i]] = p;
			add(a[i], a[i]);
			if (f[a[i]] > f[m]) m = a[i];
		}
	for (int i = m; i != 0; i = pre[i])
		g[i] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t; 
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		for (int i = 1; i <= n; i ++) 
			cin >> b[i];
		calc(n);
		for (int i = n; i >= 1; i --) {
			ans[i] = f[m];
			if (g[a[b[i]]]) calc(i - 1);
		}
		for (int i = 1; i <= n; i ++)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}