#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, ll> pr;

const int N = 2019;

const ll inf = 1e18;

int t, n, m;

vector <pr> e[N];

ll spfa(int st, int ed) {
	static deque <int> q;
	static int inq[N];
	static ll dis[N];

	while (!q.empty()) q.pop_back();
	for (int i = 0; i < n; i ++)
		inq[i] = 0, dis[i] = inf;
	dis[st] = 0, q.push_back(st);
	while (!q.empty()) {
		int u = q.front(); q.pop_front(); inq[u] = 0;
		for (auto v : e[u]) { 
			if (dis[v.first] > dis[u] + v.second) {
				dis[v.first] = dis[u] + v.second;
				if (!inq[v.first]) {
					inq[v.first] = 1;
					if (q.empty() || dis[v.first] < dis[q.front()]) q.push_front(v.first);
					else q.push_back(v.first);
				}
			}
		}
	}
	return dis[ed];
}

int main() {
	ios::sync_with_stdio(false);
	int u, v; ll w;
	for (cin >> t; t --; ) {
		cin >> n >> m;
		for (int i = 0; i < n; i ++) {
			e[i].clear();
		}
		for (; m --; ) {
			cin >> u >> v >> w;
			e[u].push_back(pr(v, w));
		}
		for (int i = 0; i < 6; i ++) {
			cin >> u >> v;
			printf("%lld\n", w = -spfa(v, u));
			e[u].push_back(pr(v, w));
		}
	}
	return 0;
}