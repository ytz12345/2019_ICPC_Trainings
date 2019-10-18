#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const int Mod = 1e9 + 7;

int n, m;

ll a[N], b[N], c[N], d[N], ans;

vector <int> e[N];

queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		ans = 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i] >> b[i], e[i].clear(), c[i] = d[i] = 0;
		for (int u, v, i = 1; i <= m; i ++) {
			cin >> u >> v;
			d[v] ++, e[u].push_back(v);
		}
		for (int i = 1; i <= n; i ++)
			if (d[i] == 0)
				q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			ans = (ans + b[u] * c[u] % Mod) % Mod;
			c[u] = (c[u] + a[u]) % Mod;
			for (int v : e[u]) {
				c[v] = (c[v] + c[u]) % Mod; 
				if ((-- d[v]) == 0) q.push(v);
			}
		}
		cout << (ans % Mod + Mod) % Mod << '\n';
	}		
}