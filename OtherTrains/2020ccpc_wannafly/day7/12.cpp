#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef bitset<20> bs;

const int N = 23;

int n, m, q, len;

int c[N];

int ru[N];

int base;

int vis[1100000], cnt = 0;

vector <int> e[N], g[N];

inline int lb(int x) {return x & (-x);}

inline int calc(int x) {
    int res = 0;
    while (x > 0) res ++, x -= lb(x);
    return res;
}

inline int f(int x) {
    int y = 0;
    for (int i = 0; i < n; i ++) 
        y |= (calc(ru[i] & x) & 1) << i;
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q; int now = 0;
    for (int i = 0; i < n; i ++) cin >> c[i], now |= c[i] << i;
    for (int x, y, i = 0; i < m; i ++) {
        cin >> x >> y;
        x --, y --;
        ru[y] |= 1 << x;
    }
    while (1) {
        if (vis[now]) {
            base = cnt;
            break;
        }
        for (int i = 0; i < n; i ++)
            if (now >> i & 1)
                e[i].push_back(cnt);
        vis[now] = ++ cnt;
        now = f(now);
    }
    memset (vis, 0, sizeof vis); cnt = 0;
    while (1) {
        if (vis[now]) {
            len = cnt - vis[now] + 1;
            break;
        }
        for (int i = 0; i < n; i ++)
            if (now >> i & 1)
                g[i].push_back(cnt);
        vis[now] = ++ cnt;
        now = f(now);
    }
    //cout << len << endl;
    for (ll x, k, ans; q --; ) {
        cin >> x >> k; x --;
        if (k <= 0) puts("0");
        else if (k <= e[x].size()) printf("%d\n", e[x][k - 1]);
        else if (g[x].size() == 0) puts("-1");
        else {
            k -= e[x].size();
            ans = base + k / g[x].size() * len;
            k %= g[x].size();
            if (k == 0) {
                ans -= len - g[x][g[x].size() - 1];
            }
            else {
                ans += g[x][k - 1];
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}