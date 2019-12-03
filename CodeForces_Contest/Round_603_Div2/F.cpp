#include <bits/stdc++.h>

using namespace std;

const int N = 2019;

int k, f[N][N];

struct tree {
    vector <int> e[N];
    int n, sum[N], id[N];
    int fa[N], son[N], siz[N], dep[N], top[N];

    void dfs1(int u) {
        siz[u] = 1;
        for (int v  : e[u]) {
            fa[v] = u, dep[v] = dep[u] + 1;
            dfs1(v), siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
    }

    void dfs2(int u, int tp) {
        top[u] = tp;
        if (son[u]) dfs2(son[u], tp);
        for (int v : e[u])
            if (son[u] != v)
                dfs2(v, v);
    }

    int lca(int u, int v) {
        for (int fu = top[u], fv = top[v]; fu != fv; fu = top[u = fa[fu]])
            if (dep[fu] < dep[fv]) swap(fu, fv), swap(u, v);
        return dep[u] < dep[v] ? u : v;
    }

    void init() {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            e[i].clear();
            son[i] = 0;
        }

        for (int p, i = 2; i <= n; i ++) {
            cin >> p;
            e[p].push_back(i); 
        }

        for (int i = 1; i <= k; i ++) {
            cin >> id[i];
        }
        dep[1] = 0;
        dfs1(1), dfs2(1, 1);

        sum[1] = 0;
        for (int i = 2; i <= k; i ++)
            sum[i] = sum[i - 1] + dep[id[i]] - dep[lca(id[i - 1], id[i])];
    }

    int ask(int l, int r) {
        return dep[id[l]] + sum[r] - sum[l];
    }

    int dis(int x, int y) {
        x = id[x], y = id[y];
        return x == 0 ? dep[y] : dep[y] - dep[lca(x, y)];
    }
}t1, t2;

inline void upd(int &x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> k;
    t1.init(); t2.init();
    memset (f, 0x3f, sizeof f); f[0][0] = 0;
    for (int x, i = 0; i < k; i ++) 
        for (int j = 0; j < k; j ++) {
            x = max(i, j) + 1;
            upd(f[x][j], f[i][j] + t1.dis(i, x));
            upd(f[i][x], f[i][j] + t2.dis(j, x));
        }
    int ans = 1e9;
    for (int i = 0; i < k; i ++)
        ans = min(ans, min(f[i][k], f[k][i]));
    cout << t1.n + t2.n - 2 - ans << endl;
    return 0;
}