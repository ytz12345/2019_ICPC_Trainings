#include <bits/stdc++.h>

#define lb(x) (x&(-x))

using namespace std;

const int N = 1e5 + 5;

int n, a[N], c[N];

void add(int i, int x) {while (i < N) c[i] += x, i += lb(i);}

int ask(int i) {int res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

int ask(int l, int r) {return ask(r) - ask(l - 1);}

vector <int> e[N];

long long ans, tmp, l[N], r[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		e[a[i]].push_back(i);
		add(i, 1);
	}
	for (int i = 1; i < N; i ++) {
		if (e[i].size() == 0) continue;
		for (int j : e[i])
			add(j, -1);
		l[0] = r[0] = 0; tmp = 1e18;
		for (int j = 0, up = e[i].size(); j < up; j ++) 
			l[j + 1] = l[j] + ask(1, e[i][j]);
		for (int up = e[i].size(), j = up - 1; j >= 0; j --) 
			r[up - j] = r[up - j - 1] + ask(e[i][j], n);
		for (int j = 0, up = e[i].size(); j <= up; j ++)
			tmp = min(tmp, l[j] + r[up - j]);
		ans += tmp;
	}
	cout << ans << endl;
}