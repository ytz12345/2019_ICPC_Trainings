#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, m, k;

set <int> s[N];

vector <int> ans;

int f[N];

int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}

int main() {
	for (t = 1; t --; ) {
		cin >> n >> k >> m;
		ans.clear();
		for (int i = 1; i <= n; i ++) {
			f[i] = i;
			s[i].clear();
		}
		for (int x, y, i = 1; i <= k; i ++) {
			cin >> x >> y;
			s[x].insert(y);
			s[y].insert(x);
		}
		for (int x, y, i = 1; i <= m; i ++) {
			cin >> x >> y;
			x = fa(x), y = fa(y);
			if (s[x].find(y) != s[x].end() || s[y].find(x) != s[y].end()) continue;
			if (s[x].size() < s[y].size()) swap(x, y);
			for (int j : s[y]) s[x].insert(fa(j));
			f[y] = x, ans.push_back(i);
		}
		printf("%d\n", (int)(ans.size()));
		for (int i : ans)
			printf("%d ", i);
		puts("");
	}
}