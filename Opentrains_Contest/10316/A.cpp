#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n;

vector <int> e[N];

int col[N];

int now1, now2;

bool dfs(int u, int c) {
	//cout << u << endl;
	if (col[u]) {
		if (col[u] != c) return 0;
		return 1; 
	}
	col[u] = c;
	for (int v : e[u])
		if (v != now1 && v != now2)
			if (!dfs(v, 3 - c))
				return 0;
	return 1;
}

bool check() {
	memset(col, 0, sizeof col);
	for (int i = 1; i <= n; i ++)
		if (i != now1 && i != now2 && !col[i])
			if (!dfs(i, 1))
				return 0;
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int k, i = 1; i <= n; i ++) {
		cin >> k;
		for (int x, j = 1; j <= k; j ++) {
			cin >> x;
			e[i].push_back(x);
			e[x].push_back(i);
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			now1 = i, now2 = j;
			if (check()) {
				puts("Hurrah!");
				return 0;
			}
		}
	}
	puts("Fired.");
	return 0;
}