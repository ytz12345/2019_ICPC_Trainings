#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 5;

const ll Mod = 1e9 + 7;

ll n;

ll ans, tmp;

ll sum_w, sum_d_w; // sum_w = sum(wj), sum_d_w = sum(dep[j] * w[j]);

struct interval{ll l, r, len;}c[N];

struct alarm{ll tim, ver, typ;}b[N * 2];

ll w[N]; //w[i] = len[i] ^ (-1)

ll P = 1; //P = multi(c[i].len)

ll calc(ll x, ll k = Mod - 2, ll md = Mod) { // return x ^ k % md
    ll res = 1;
    for (x %= md; k > 0; k >>= 1, x = x * x % md)
        if (k & 1) res = res * x % md;
    return (res % md + md) % md;
}

ll dep[N];

vector <int> e[N];

ll son[N], fa[N], top[N], siz[N];

int cnt, pos[N], dfn[N];

struct node {
    ll sum, lazy;
}tr[N << 2];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1) 

void pushup(int o) {
    tr[o].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int o, int l, int r) {
    if (!tr[o].lazy) return;
    tr[lc].lazy += tr[o].lazy;
    tr[lc].sum += tr[o].lazy * (mid - l + 1);
    tr[rc].lazy += tr[o].lazy;
    tr[rc].sum += tr[o].lazy * (r - mid);
    tr[o].lazy = 0;
}

ll ask(int o, int l, int r, int s, int t) {
    if (s <= l && r <= t) return tr[o].sum;
    pushdown(o, l, r);
    ll res = 0;
    if (s <= mid) res += ask(lc, l, mid, s, t);
    if (t >  mid) res += ask(rc, mid + 1, r, s, t);
    return res;
}

void add(int o, int l, int r, int s, int t, ll v) {
    if (s <= l && r <= t) {
        tr[o].sum += v * (r - l + 1);
        tr[o].lazy += v;
        return;
    }
    pushdown(o, l, r);
    if (s <= mid) add(lc, l, mid, s, t, v);
    if (t >  mid) add(rc, mid + 1, r, s, t, v);
    pushup(o);
}

void dfs1(int u) {
    siz[u] = 1;
    for (ll v : e[u]) {
        if (v == fa[u]) continue;
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v), siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp; pos[u] = ++ cnt, dfn[cnt] = u;
    if (son[u]) dfs2(son[u], tp);
    for (int v : e[u])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}

ll ask(int u) { //查询点u到根的节点权值和
    ll res = 0;
    for (int fu = top[u]; fu; fu = top[u = fa[fu]])
        res = (res + ask(1, 1, n, pos[fu], pos[u])) % Mod;
    return res;
}

void add(int u, ll v) { //点u到根的路径所有点都加v
    for (int fu = top[u]; fu; fu = top[u = fa[fu]])
        add(1, 1, n, pos[fu], pos[u], v);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> c[i].l >> c[i].r;
        c[i].len = c[i].r - c[i].l + 1;
        w[i] = calc(c[i].len);
        P = P * c[i].len % Mod;
        b[i * 2 - 1] = (alarm){c[i].l, i, 1};
        b[i * 2] = (alarm){c[i].r + 1, i, -1};
    }
    sort (b + 1, b + n * 2 + 1, [&](alarm x, alarm y) {
        return x.tim < y.tim;
    });
    for (int u, v, i = 1; i < n; i ++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[1] = 1, dfs1(1), dfs2(1, 1);
    for (int i = 1, j = 1; i < N; i ++) {
        while (j <= n * 2 && b[j].tim == i) {
            ll u = b[j].ver;
            if (b[j].typ == 1) {
                ll temp = (dep[u] * sum_w % Mod + sum_d_w) % Mod;
                temp = (temp - ask(u) * 2) % Mod;
                temp = temp * w[u] % Mod;

                sum_d_w = (sum_d_w + w[u] * dep[u] % Mod) % Mod;
                sum_w = (sum_w + w[u]) % Mod;
                tmp = (tmp + temp) % Mod;
                add(u, w[u]);
            } else {
                sum_d_w = (sum_d_w - w[u] * dep[u] % Mod) % Mod;
                sum_w = (sum_w - w[u]) % Mod;
                add(u, -w[u]);

                ll temp = (dep[u] * sum_w % Mod + sum_d_w) % Mod;
                temp = (temp - ask(u) * 2) % Mod;
                temp = temp * w[u] % Mod;

                tmp = (tmp - temp) % Mod;
            }
            
            j ++;
        }
        ans += tmp, ans %= Mod;
    }
    cout << (ans * P % Mod + Mod) % Mod << endl;
    return 0;
}