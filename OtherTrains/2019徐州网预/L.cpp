#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;

int d[8][8] = {
	0, 3, 4, 5, 4, 7, 8, 9,
	3, 6, 5, 6, 5, 8, 9, 10,
	4, 5, 4, 5, 6, 7, 8, 9,
	5, 6, 5, 6, 7, 8, 9, 10,
	4, 5, 6, 7, 8, 9, 10, 11,
	7, 8, 7, 8, 9, 12, 11, 12,
	8, 9, 8, 9, 10, 11, 12, 13, 
	9, 10, 9, 10, 11, 12, 13, 14
};

int dis(point a, point b) {
	int x = abs(a.first - b.first), y = abs(a.second - b.second);
	return x - x % 8 + y - y % 8 + d[x % 8][y % 8];
}

struct edge {
	int u, v, w;
}e[2019];

int t, n, m, ans;

int f[30];

int fa(int x) {
	return x == f[x] ? x : (f[x] = fa(f[x]));
}
 
point p[30];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> p[i].first >> p[i].second;
			f[i] = i;
		}
		n ++; 
		f[n] = n;
		p[n] = (point){0, 0};
		m = 0; ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++) {
				e[m ++] = (edge){i, j, dis(p[i], p[j])};
			}
		sort (e, e + m, [&](edge a, edge b) {
			return a.w < b.w;
		});
		for (int i = 0, j = 1; j < n; i ++) {
			if (fa(e[i].u) == fa(e[i].v)) continue;
			j ++; 
			ans += e[i].w;
			f[fa(e[i].u)] = fa(e[i].v);
		}
		cout << ans << '\n';
	}
}