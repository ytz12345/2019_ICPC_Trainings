#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

typedef pair<piir, int> pr;

const int N = 5e5 + 5;

int n, m;

vector <pr> e[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int a, b, c, i = 1; i <= n; i ++) {
		cin >> a >> b >> c;
		e[c].push_back(pr(piir(a, b), i));
	}
	for (int i = 1; i <= m; i ++) {
		int l = 1e9, p, ok = 0;
		if (e[i].size() < 2) {puts("NIE"); continue;}
		for (auto u : e[i])
			if (u.first.second < l) 
				l = u.first.second, p = u.second;
		for (auto u : e[i])
			if (u.first.first > l) {
				printf("TAK %d %d\n", p, u.second);
				ok = 1;
				break;
			}
		if (!ok) puts("NIE");
	}
	return 0;
}