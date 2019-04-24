#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, k;

int b[N];

vector <int> e[N];

void dfs(int u) {
	if (b[u]) return;
	b[u] = 1, k ++;
	for (int v : e[u])
		dfs(v);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> k >> m;
	for (int x, i = 1; i <= k; i ++) {
		cin >> x;
		b[x] = 1;
	}
	for (int u, v, i = 1; i <= m; i ++) {
		cin >> v >> u;
		if (u != v) {
			e[u].push_back(v);
			if (b[u]) dfs(v);
		}
		cout << k << '\n';
	}
	return 0;
}