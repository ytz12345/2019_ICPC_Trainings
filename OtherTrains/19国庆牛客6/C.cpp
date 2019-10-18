#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 7;

int n, m;

int a[N];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i < n; i ++)
			a[i] = inf;
		for (int u, v, w; m --; ) {
			cin >> u >> v >> w;
			if (v != u + 1) continue;
			a[u] = min(a[u], w);
		}
		int flag = 0, ans = 0; 
		for (int i = 1; i < n; i ++) {
			flag |= a[i] == inf;
			ans += a[i];
		}
		printf("%d\n", flag ? -1 : ans);
	}
}