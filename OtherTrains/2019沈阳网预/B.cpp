#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, m, k;

vector <int> e[N], g[N];

int f[N], s[N], isMs[N];

int fa(int x) {return x == f[x] ? x : (f[x] = fa(f[x]));}

void un(int x, int y) {
	x = fa(x), y = fa(y);
	if (x == y) return;
	if (x < y) f[y] = x, s[x] += s[y];
	else f[x] = y, s[y] += s[x];
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i ++)
			e[i].clear(), g[i].clear(), f[i] = i, isMs[i] = 0, s[i] = 1;
		for (int u, v, i = 1; i <= m; i ++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int x; k --; ) {
			cin >> x;
			isMs[x] = 1;
		}
		for (int i = 1; i <= n; i ++) {
			if (isMs[i]) continue;
			for (int j : e[i]) {
				if (isMs[j]) continue;
				un(i, j);
			}
		}
		for (int i = 1; i <= n; i ++)
			for (int j : e[i]) {
				if (fa(i) == fa(j)) continue;
				g[fa(i)].push_back(fa(j));
				g[fa(j)].push_back(fa(i));
			}
		double ans = 0;
		for (int i : g[fa(1)]) {
			double sum = 0, cnt = g[i].size();
			for (int j : g[i]) {
				if (j == fa(1) || isMs[j]) continue;
				sum += s[j];
			}
			ans = max(ans, sum / cnt);
		}
		ans += s[fa(1)];
		printf("%.10f\n", ans);
	}
}