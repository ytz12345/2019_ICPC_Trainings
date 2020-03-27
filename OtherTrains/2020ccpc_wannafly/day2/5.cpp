#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

int n;

ll ans[N], now;

vector <int> e[N];

int siz[N], son[N];

set <ll> s;

ll sqr(ll x) {return x * x;}

void dfs1(int u) {
    siz[u] = 1;
    for (int v : e[u]) {
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void update(int x, int y) {
    if (y == 1) {
        s.insert(x);
        auto it = s.find(x);
        auto pre = it, suc = it;
        if (it != s.begin()) pre --, now += sqr(x - *pre);
        suc ++; if (suc != s.end())  now += sqr(x - *suc);
        if (it != s.begin() && suc != s.end()) now -= sqr(*suc - *pre);
    }
    else {
        auto it = s.find(x);
        auto pre = it, suc = it;
        if (it != s.begin()) pre --, now -= sqr(x - *pre);
        suc ++; if (suc != s.end())  now -= sqr(x - *suc);
        if (it != s.begin() && suc != s.end()) now += sqr(*suc - *pre);
        s.erase(it);
    }
}

void dfs3(int u, int val) {
    update(u, val);
    for (int v : e[u]) 
        dfs3(v, val);
}

void dfs2(int u) {
    for (int v : e[u]) {
        if (v == son[u]) continue;
        dfs2(v), dfs3(v, -1);
    }
    if (son[u]) dfs2(son[u]);
    for (int v : e[u]) {
        if (v == son[u]) continue;
        dfs3(v, 1);
    }
    update(u, 1);
    ans[u] = now;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int p, i = 2; i <= n; i ++) {
        cin >> p;
        e[p].push_back(i);
    }
    dfs1(1); dfs2(1);
    for (int i = 1; i <= n; i ++) 
        cout << ans[i] << endl;
    return 0;
}