#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int, int> piir;

typedef pair<piir, int> pr;

typedef long long ll;

const int N = 6e5 + 5;

int n, r, c, a[N], b[N];

piir p[N];

vector <piir> pt[N][2];

vector <piir> e[N];

int dis[N], vis[N];

priority_queue <piir, vector<piir>, greater<piir> > q;

inline void add(int u, int v, int w) {
	e[u].pb(piir(v, w));
	e[v].pb(piir(u, w));
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> p[i].fi >> p[i].se;
	for (int i = 0; i < n; i ++)
		a[i] = p[i].fi;
	sort (a, a + n);
	r = unique(a, a + n) - a;
	for (int i = 0; i < n; i ++) 
		p[i].fi = lower_bound(a, a + r, p[i].fi) - a + 1;
	for (int i = 0; i < n; i ++)
		b[i] = p[i].se;
	sort (b, b + n);
	c = unique(b, b + n) - b;
	for (int i = 0; i < n; i ++)
		p[i].se = lower_bound(b, b + c, p[i].se) - b + 1;
	for (int i = 0; i < n; i ++) {
		pt[p[i].fi][0].pb(piir(p[i].se, i));
		pt[p[i].se][1].pb(piir(p[i].fi, i));
		add(r + c + i + 1, p[i].fi, 0);
		add(r + c + i + 1, r + p[i].se, 0);
	}
	for (int i = 1; i < r; i ++)
		add(i, i + 1, a[i] - a[i - 1]);
	for (int i = 1; i < c; i ++)
		add(r + i, r + i + 1, b[i] - b[i - 1]);
	for (int i = 1; i <= r; i ++) {
		if (pt[i][0].size() == 0) continue;
		sort (pt[i][0].begin(), pt[i][0].end());
		for (int j = 1; j < pt[i][0].size(); j ++) 
			add(r + c + pt[i][0][j].se + 1, r + c + pt[i][0][j - 1].se + 1, 0);
	}
	for (int i = 1; i <= c; i ++) {
		if (pt[i][1].size() == 0) continue;
		sort (pt[i][1].begin(), pt[i][1].end());
		for (int j = 1; j < pt[i][1].size(); j ++) 
			add(r + c + pt[i][1][j].se + 1, r + c + pt[i][1][j - 1].se + 1, 0);
	}
	for (int i = 1; i <= r + c + n; i ++)
		dis[i] = 1e9 + 7;
	piir now;
	q.push(piir(dis[r + c + 1] = 0, r + c + 1));
	while (!q.empty()) {
		now = q.top(), q.pop();
		if (vis[now.se]) continue;
		vis[now.se] = 1;
		for (piir i : e[now.se])
			if (!vis[i.fi] && dis[i.fi] > dis[now.se] + i.se)
				q.push(piir(dis[i.fi] = dis[now.se] + i.se, i.fi));
	}
	cout << dis[r + c + n];
	return 0;
}