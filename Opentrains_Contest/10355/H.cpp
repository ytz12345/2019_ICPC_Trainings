#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, m;

ll c[N];

ll w[N], len[N];

vector <int> e[N];

inline int lb(int x) {return x & (-x);}

inline void add(int i, ll x) {while (i <= 2 * n + 1) c[i] += x, i += lb(i);}

inline ll ask(int i) {ll res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

int cnt, st[N], en[N], pos[N];

void dfs(int u) {
	st[u] = ++ cnt, pos[cnt] = u;
	for (int v : e[u])
		dfs(v);
	en[u] = cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n + 1; i ++)
		cin >> w[n + i];
	for (int s1, s2, i = 1; i <= n; i ++) {
		cin >> len[i] >> s1 >> s2;
		if (s1 < 0) s1 = -s1 + n;
		if (s2 < 0) s2 = -s2 + n;
		e[i].push_back(s1);
		e[i].push_back(s2);
	}
	dfs(1);
	/*for (int i = 1; i <= 3; i ++)
		printf("%d %d %d\n", st[i], en[i], pos[i]);*/
	for (int i = 1; i <= cnt; i ++)
		if (pos[i] > n)
			add(i, w[pos[i]]);// ,printf("%d %d %d\n", i, pos[i], w[pos[i]]);
	//printf("%lld\n", ask(3));
	for (int op, u, v; m --; ) {
		cin >> op;
		if (op ==1) {
			cin >> u >> v;
			u += n;
			add(st[u], -w[u]);
			add(st[u], w[u] = v);
		}
		else {
			cin >> u;
			long double swl = ask(en[e[u][0]]) - ask(st[e[u][0]] - 1);
			long double swr = ask(en[e[u][1]]) - ask(st[e[u][1]] - 1);
			//printf("%.15Lf %.15Lf\n", swl, swr); 
			printf("%.15Lf\n", len[u] * swr/ (swl + swr)); 
		}
	}
	return 0;
}