#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, fa[N];

int cnt, st[N], ed[N];

vector <int> e[N];

void dfs(int u) {
    st[u] = ++ cnt;
    for (int v : e[u]) {
        if (v == fa[u]) continue;
        fa[v] = u, dfs(v);
    }
    ed[u] = cnt;
}

int main() {
	ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int u, v, i = 1; i < n; i ++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    for (int k, x, ml, mr; m --; ) {
        for (cin >> k, ml = 1, mr = n; k --; ) {
            cin >> x;
            x = x == 1 ? 1 : fa[x];
            ml = max(ml, st[x]);
            mr = min(mr, ed[x]);
        }
        puts(ml <= mr ? "YES" : "NO");
    }
    return 0;
}