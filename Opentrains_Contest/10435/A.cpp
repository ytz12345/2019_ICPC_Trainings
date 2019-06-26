#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, k;

int c[N], cnt[N], cot[N];

int fa[N], ch[N][2], cov[N], siz[N];

int sta[N], top;

vector <int> e[N];

bool isroot(int x) {
    return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}

void cover(int x, int y) {
    if (!x) return;
    c[x] = cov[x] = y;
}

void pushdown(int x) {
    if (!cov[x]) return;
    cover(ch[x][0], cov[x]);
    cover(ch[x][1], cov[x]);
    cov[x] = 0;
}

void pushup(int x) {
    siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
}

void rot(int x) {
    int y = fa[x], z = fa[y], d = ch[y][1] == x, c = ch[x][!d];
    fa[x] = z; if (!isroot(y)) ch[z][ch[z][1] == y] = x;
    ch[y][d] = c; if (c) fa[c] = y;
    fa[y] = x, ch[x][!d] = y;
    pushup(y), pushup(x);
}

void splay(int x) {
    int u = x, top = 0, y, z;
    while (!isroot(u)) sta[++ top] = u, u = fa[u];
    sta[++ top] = u;
    while (top) pushdown(sta[top --]);
    while (!isroot(x)) {
        y = fa[x], z = fa[y];
        if (!isroot(y)) {
            if ((ch[z][0] == y) ^ (ch[y][0] == x)) rot(x);
            else rot(y);
        }
        rot(x);
    }
}

void access(int x, int cov) {
    int last_siz = 0, root;
    for (int y = 0; x != 0; y = x, x = fa[x]) {
        splay(x), ch[x][1] = y, pushup(x);
        cot[cnt[c[x]]] --;
        cnt[c[x]] -= siz[x] - last_siz;
        cot[cnt[c[x]]] ++;
        last_siz = siz[x];
        root = x;
    }
    cover(root, cov);
    cot[cnt[cov]] --;
    cnt[cov] += siz[root];
    cot[cnt[cov]] ++;
}

void dfs(int u) {
    for (int v : e[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dfs(v);
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int u, v, i = 1; i < n; i ++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i ++) 
        c[i] = k + 1;
    cnt[k + 1] = n, cot[n] = 1, cot[0] = k;
    for (int x, y, z; m --; ) {
        cin >> x >> y >> z;
        access(x, y);
        access(1, k + 1);
        cout << cot[z] - (cnt[k + 1] == z) << '\n';
    }
    return 0;
}