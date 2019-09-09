#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, ll> pr;

const int N = 5e4 + 5;

int t, n, m, k, q;

int a[N];

ll dis[N];

vector <pr> e[N];

struct node {
	int u;
	ll d;
	int fr, i;

	bool operator < (const node &a) const {
		return d > a.d;
	}
};

priority_queue <node> Q; 

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> q; k = 0;
		for (int i = 1; i <= n; i ++) {
			e[i].clear();
		}
		for (int u, v, w; m --; ) {
			cin >> u >> v >> w;
			e[u].push_back(pr(v, w));
		}
		for (int i = 1; i <= q; i ++) {
			cin >> a[i];
			k = max(a[i], k);
		}
		while (!Q.empty()) Q.pop();
		for (int i = 1; i <= n; i ++) {
			sort (e[i].begin(), e[i].end(), [&](pr a, pr b) {
				return a.second < b.second;
			});
			if (e[i].size() == 0) continue;
			Q.push((node){e[i][0].first, e[i][0].second, i, 0});
		}
		node tmp;
		for (int i = 1; i <= k; i ++) {
			tmp = Q.top(); Q.pop();
			dis[i] = tmp.d;
			if (e[tmp.u].size() != 0) {
				Q.push((node){e[tmp.u][0].first, tmp.d + e[tmp.u][0].second, tmp.u, 0});
			}
			if (int(e[tmp.fr].size()) != tmp.i + 1) {
				Q.push((node){e[tmp.fr][tmp.i + 1].first, tmp.d - e[tmp.fr][tmp.i].second
					+ e[tmp.fr][tmp.i + 1].second, tmp.fr, tmp.i + 1});
			}
		}
		for (int i = 1; i <= q; i ++)
			//printf("%d %lld\n", a[i], dis[a[i]]);
			printf("%lld\n", dis[a[i]]);
	}
	return 0;
}