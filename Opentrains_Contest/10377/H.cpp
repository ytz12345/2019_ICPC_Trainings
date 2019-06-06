#include <bits/stdc++.h>

#define debug

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

typedef pair<piir, piir> pr;

const int lim = 1e6;

vector <piir> ans;

vector <piir> prob;

map <pr, bool> p; 

int n, ret;

long long sqr(int x) {
	return 1ll * x * x;
}

void ask(int x, int y, ll r) {
	#ifndef debug
		printf("? %d %d %lld\n", x, y, r);
		fflush(stdout);
		cin >> ret;
	#else
		ret = 0;
		for (piir i : prob) 
			if (sqr(i.first - x) + sqr(i.second - y) <= r)
				ret ++;
		printf("%d %d %lld %d\n", x, y, r, ret);
	#endif 
}

void solve(int lx, int ly, int rx, int ry) {
	if (p[pr(piir(lx, ly), piir(rx, ry))]) return;
	p[pr(piir(lx, ly), piir(rx, ry))] = 1;
	int mx = lx + (rx - lx) / 2, my = ly + (ry - ly) / 2;
	ask(mx, my, (sqr(max(mx - lx, rx - mx)) + sqr(max(ry - my, my - ly)) + 3) / 4);
	if (ret == 0) return;
	if (lx == rx && ly == ry) {ans.push_back(piir(lx, ly)); return;}
	solve(lx, ly, mx, my);
	solve(lx, my + 1, mx, ry);
	solve(mx + 1, ly, rx, my);
	solve(mx + 1, my + 1, rx, ry);
}

int main() {
	ios::sync_with_stdio(false);
	#ifndef debug
		cin >> n;
	#else
		freopen("test.txt", "r", stdin);
		cin >> n;
		for (int x, y, i = 0; i < n; i ++) {
			cin >> x >> y;
			prob.push_back(piir(x, y));
		}
	#endif
	solve(-lim, -lim, lim, lim);
	printf("!");
	sort (ans.begin(), ans.end());
	unique(ans.begin(), ans.end());
	for (piir i : ans)
		printf(" %d %d", i.first, i.second);
	return 0;
}