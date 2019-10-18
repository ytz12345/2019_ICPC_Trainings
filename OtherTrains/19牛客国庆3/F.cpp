#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

int n, m, q;

int a[11][N];

int tot, bel[N], vis[N], len[N];

int b[N], d[N], dis[N];

int ans[N];

vector <piir> c[10];

piir nd[N];

void dfs(int x) {
    int l = 0; tot ++;
    for (int i = x; !vis[i]; i = a[m][i]) 
        vis[i] = 1, dis[i] = l ++, b[l] = i;
    for (int i = 1; i <= l; i ++)
        len[b[i]] = l, bel[b[i]] = tot;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> q) {
        tot = 0;
        for (int i = 1; i <= n; i ++)
            a[0][i] = i, vis[i] = 0;
        for (int x, y, i = 1; i <= m; i ++) {
            cin >> x >> y; c[i - 1].clear();
            while (x < y) swap(a[0][x ++], a[0][y --]);
            for (int j = 1; j <= n; j ++)
                a[i][j] = a[0][j];
        }
        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) dfs(i);
            nd[i] = piir(len[i], i);
            a[0][i] = i;
        }
        sort (nd + 1, nd + n + 1);
        for (int x, i = 1; i <= q; i ++) {
            cin >> x; ans[i] = 0;
            c[x % m].push_back(piir(x / m, i));
        }
        for (int k, i = 0; i < m; i ++) {
            if (c[i].size() == 0) continue;
            for (int j = 1; j <= n; j ++) b[a[i][j]] = j;
            for (int last = 1, j = 1; j <= n; j ++) {
                k = b[nd[j].second];
                if (bel[k] == bel[nd[j].second])
                    d[(dis[k] - dis[nd[j].second] + len[k]) % len[k]] ++;
                if (j == n || nd[j + 1].first != nd[j].first) {
                    for (auto &p : c[i])
                        ans[p.second] += d[p.first % nd[j].first];
                    for (; last <= j; last ++) {
                        k = b[nd[last].second];
                        if (bel[k] == bel[nd[last].second])
                            d[(dis[k] - dis[nd[last].second] + len[k]) % len[k]] --;
                    }
                }
            } 
        }
        for (int i = 1; i <= q; i ++)
            printf("%d\n", ans[i]);
    }
}