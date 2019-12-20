#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pr;

const int N = 3e5 + 5;

int n, a[N];

vector <int> e[N];

pr b[N];

void dfs(int u) {
	if (e[u].size() == 0) {
		b[u] = pr(1, 1);
		return;
	}
	for (int v, i = 0; i < e[u].size(); i ++) {
		dfs(v = e[u][i]);
		if (i == 0) b[u] = b[v];
		else {
			if (a[u]) b[u] = pr(max(b[u].second + b[v].first, b[v].second + b[u].first), b[u].second + b[v].second);
			else b[u] = pr(b[u].first + b[v].first - 1, b[u].second + b[v].second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int f, i = 2; i <= n; i ++)	
		cin >> f, e[f].push_back(i);
	dfs(1);
	cout << b[1].first;
	return 0; 
}