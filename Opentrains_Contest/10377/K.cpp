#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
typedef pair<int, int> P;
typedef vector<P> VII;
const int N = 2e5 + 7;
const ll inf = 1e15;
VII g[N];
int mark[N];
ll dp[N][2];
ll dfs(int u, int fa, int col) {
	if (mark[u] != -1 && mark[u] == 1 - col) return inf;
	ll &ret = dp[u][col];
	if (ret != -1) return ret;
	ret = 0;
	for (P p: g[u]) {
		int v = p.first;
		if (v == fa) continue;
		ret += min(dfs(v, u, col), dfs(v, u, 1 - col) + (ll)p.second);
		ret = min(ret, inf);
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	rep(i, 1, n - 1) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back(P(y, z));
		g[y].push_back(P(x, z));
	}
	memset(mark, -1, sizeof(mark));
	int m, x;
	scanf("%d", &m);
	rep(i, 1, m) {
		scanf("%d", &x);
		mark[x] = 0;
	}
	scanf("%d", &m);
	rep(i, 1, m) {
		scanf("%d", &x);
		mark[x] = 1;
	}
	memset(dp, -1, sizeof(dp));
	cout << min(dfs(1, 0, 0), dfs(1, 0, 1)) << endl;
}