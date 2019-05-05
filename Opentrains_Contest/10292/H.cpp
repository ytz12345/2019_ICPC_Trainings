#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const int inf = 1e9;

int n;

ll ans;

struct {int f, p, m, s;} a[N];

int jin[N][2];

vector <int> e[N];

int cnt, dfn[N], low[N], vis[N];

int top, sta[N], ins[N];

vector <int> cycle;

void tarjan(int u) {
	low[u] = dfn[u] = ++ cnt, vis[u] = 1;
	sta[++ top] = u, ins[u] = 1;
	for (auto v : e[u])
		if (!vis[v])
			tarjan(v), low[u] = min(low[u], low[v]);
		else if (ins[v])
			low[u] = min(low[u], low[v]);
	if (low[u] == dfn[u]) {
		if (sta[top] == u)
			ins[sta[top --]] = 0;
		else {
			cycle.clear(); int now;
			while (1) {
				now = sta[top --];
				cycle.push_back(now);
				ins[now] = 0;
				if (now == u) break;
			}
			int siz = cycle.size();
			cycle.push_back(cycle[0]);
			int flag = 1;
			for (int i = 0; i < siz; i ++) {
				if (a[cycle[i + 1]].p != jin[cycle[i]][0]) {
					flag = 0;
					break;
				}
			}
			if (!flag) return;
			int tmp = inf;
			for (int i = 1; i <= siz; i ++) {
				tmp = min(jin[cycle[i]][1] - jin[cycle[i]][0], tmp);
			}
			ans -= tmp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		ans = 0; cnt = 0;
		for (int i = 1; i <= n; i ++) {
			e[i].clear();
			vis[i] = 0;
		}
		for (int i = 1; i <= n; i ++) {
			cin >> a[i].f >> a[i].p >> a[i].m >> a[i].s;
			jin[i][0] = jin[i][1] = a[i].m;
		}
		for (int i = 1; i <= n; i ++) {
			if (a[i].p < jin[a[i].f][0]) jin[a[i].f][1] = jin[a[i].f][0], jin[a[i].f][0] = a[i].p;
			else if (a[i].p < jin[a[i].f][1]) jin[a[i].f][1] = a[i].p;
		}
		for (int i = 1; i <= n; i ++) {
			//printf("%d %d\n", i, jin[i][0]);
			ans += 1ll * (a[i].m - jin[i][0]) * a[i].s;
		}
		for (int i = 1; i <= n; i ++) {
			if (a[a[i].f].m > a[i].p) 
				e[i].push_back(a[i].f);
		}
		for (int i = 1; i <= n; i ++) {
			if (!vis[i])
				tarjan(i);
		}
		cout << ans << '\n';
	}
	return 0;
}