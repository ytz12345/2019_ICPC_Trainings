#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n, c, a[N];

ll sum, ans[N], inc[N], pre[N];

vector <int> e[N];

void dfs(int u, int f) {
	int last = pre[a[u]];
	inc[u] = c, ans[u] = ans[f] + inc[u];
	if (last) ans[u] -= inc[last];
	else c ++;
	pre[a[u]] = u;
	for (int v : e[u]) dfs(v, u);
	pre[a[u]] = last;
	if (!last) c --;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 1; i <= n; i ++)
			e[i].clear();
		for (int f, i = 2; i <= n; i ++) {
			cin >> f;
			e[f].push_back(i);
		}
		for (int i = 1; i <= n; i ++)
			cin >> a[i], pre[i] = 0;
		sum = 0, dfs(1, 0);
		for (int i = 2; i <= n; i ++)
			printf("%lld\n", ans[i]);
	}
}