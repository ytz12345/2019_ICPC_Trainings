#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int t, n, m;

int a[21], b[21];

vector <int> e[N];

deque <int> q;

int vis[N], d[N];

int d1[21][N], d2[21][N];

ll a1, a2, a3;

void bfs(int st) {
	memset (vis, 0, sizeof vis);
	q.push_back(st), vis[st] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (int v : e[u]) 
			if (!vis[v]) {
				if (d[v] <= d[u]) q.push_front(v);
				else d[v] = d[u] + 1, q.push_back(v);
				vis[v] = 1;
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	for (int tt = 1; tt <= t; tt ++) {
		cin >> n >> m; a1 = a2 = 0;
		for (int i = 1; i <= n; i ++)
			e[i].clear();
		for (int u, v, i = 1; i <= m; i ++) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cin >> a[0];
		for (int i = 1; i <= a[0]; i ++)
			cin >> a[i];
		cin >> b[0];
		for (int i = 1; i <= b[0]; i ++)
			cin >> b[i];
		for (int i = 1; i <= a[0]; i ++) {
			memset (d, 0x3f, sizeof d);
			d[a[i]] = 0, bfs(a[i]);
			for (int j = 1; j <= n; j ++)
				d1[i][j] = d[j];
		}
		for (int i = 1; i <= b[0]; i ++) {
			memset (d, 0x3f, sizeof d);
			d[b[i]] = 0, bfs(b[i]);
			for (int j = 1; j <= n; j ++)
				d2[i][j] = d[j];
		}
		for (int i = 1; i <= a[0]; i ++)
			for (int j = 1; j <= b[0]; j ++) {
				for (int k = 1; k <= n; k ++)
					d[k] = d1[i][k] + d2[j][k];
				bfs(a[i]);
				for (int k = 1; k <= n; k ++)
					a1 += d[k];		
			}
		a2 = 1ll * a[0] * b[0] * n;
		a3 = __gcd(a1, a2);
		a1 /= a3, a2 /= a3;
		printf("Case #%d: ", tt);
		if (a1 != 1) printf("%lld/%lld\n", a1, a2);
		else printf("%lld\n", a1);
	}	
	return 0;
}