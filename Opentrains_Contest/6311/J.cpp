#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, m;

struct {int u, v, t, r;}e[N];

struct piir{int first; ll second; int id;};

vector <piir> f[N];

ll dis[N], dr[N], dt[N], pre[N];

int vis[N];

int pt, pr, rp[N];

piir t[N];

vector <int> ans;

struct node {
	ll u, dis;
	bool operator < (const node &a) const {
		return dis > a.dis;
	}
};

inline void getDis() {
	for (int i = 1; i <= n; i ++) dis[i] = 1e18;
	static priority_queue <node> q; node now; 
	q.push((node){n, dis[n] = 0});
	while (!q.empty()) {
		now = q.top(), q.pop();
		if (vis[now.u]) continue;
		vis[now.u] = 1;
		for (auto &v : f[now.u]) {
			if (vis[v.first]) continue;
			if (dis[v.first] > dis[now.u] + v.second)
				q.push((node){v.first, dis[v.first] = dis[now.u] + v.second}), pre[v.first] = v.id;
			else if (dis[v.first] == dis[now.u] + v.second)
				pre[v.first] += v.id;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].t >> e[i].r;
		f[e[i].v].push_back((piir){e[i].u, e[i].r, i});
	}

	getDis();

	cin >> pt;
	for (int i = 1; i <= pt; i ++)
		cin >> t[i].first >> t[i].second;
	t[pt].second = 0;
	for (int i = pt - 1; i >= 0; i --)
		dt[i] = dt[i + 1] + e[t[i + 1].first].t;

	cin >> pr; 
	for (int i = 1; i <= pr; i ++)
		cin >> rp[i];
	for (int i = pr - 1; i >= 0; i --)
		dr[i] = dr[i + 1] + e[rp[i + 1]].r;

	if (dis[1] <= dt[0] && dis[1] < dr[0] && pre[1] != rp[1]) ans.push_back(1);
	ll tim_r = 0, tim_t = 0, tim_tur;
	for (int i = 1, j = 1; i < pr; i ++) {
		int now = e[rp[i]].v;
		tim_r += e[rp[i]].r;
		while (j <= pt && tim_t + e[t[j].first].t + t[j].second <= tim_r)
			tim_t += e[t[j].first].t + t[j].second, j ++;
		if (j > pt) break;
		if (tim_t + e[t[j].first].t > tim_r) tim_tur = tim_t + e[t[j].first].t + dt[j];
		else tim_tur = tim_t + e[t[j].first].t + t[j].second + dt[j];
		if (dis[now] < dr[i] && tim_r + dis[now] <= tim_tur && pre[now] != rp[i + 1])
			ans.push_back(now);
	}

	printf("%d\n", int(ans.size()));
	sort (ans.begin(), ans.end());
	for (int i : ans)
		printf("%d ", i);
}