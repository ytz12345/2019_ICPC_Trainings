#include <bits/stdc++.h>

const int max_N = 1000 + 21;

int n, x[max_N], y[max_N], Q[max_N];

long double angle[max_N];

int siz[max_N], p[max_N];

std::vector<int> vec[max_N];

void dfs(int u) {
    siz[u] = 1;
    for (auto &v : vec[u]) {
        if (v == p[u]) continue;
        p[v] = u;
        dfs(v);
        siz[u] += siz[v];
    }
}

void solve(int u, int l, int r) {
    if (siz[u] == 1) return;
    int p = Q[l];
    for (int i = l + 1; i <= r; ++i) {
        int q = Q[i];
        angle[q] = atan2(y[q] - y[p], x[q] - x[p]);
    }
    std::sort(Q + l + 1, Q + r + 1, [&](int a, int b) {
        return 1ll * (x[a] - x[p]) * (y[b] - y[p]) - 1ll * (y[a] - y[p]) * (x[b] - x[p]) > 0;
    });
    int cur = l;
    for (auto &v : vec[u]) {
        if (v == ::p[u]) continue;
        printf("%d %d\n", p - 1, Q[cur + 1] - 1);
        solve(v, cur + 1, cur + siz[v]);
        cur += siz[v];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        ++u, ++v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", x + i, y + i);
        ++x[i], ++y[i];
        angle[i] = atan2(y[i], x[i]);
        Q[i] = i;
    }
    std::sort(Q + 1, Q + 1 + n, [&](int a, int b) {
        return angle[a] < angle[b];
    });
    solve(1, 1, n);
}
/*

 5
 0 1
 1 2
 2 3
 3 4
 0 0
 9 9
 2 3
 3 2
 7 8

 3
 1 2
 0 2
 0 0
 1 1
 2 3
 */