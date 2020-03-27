#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

const int Mod = 1e9 + 7;

typedef long long ll;

ll n, p[N], pos[N];

int lb(int x) {return x & (-x);}

void add(ll *c, int i, ll x) {while (i <= n) c[i] = (c[i] + x) % Mod, i += lb(i);}

ll ask(ll *c, int i) {ll res = 0; while (i > 0) res = (res + c[i]) % Mod, i -= lb(i); return res;}

ll ask(ll *c, int l, int r) {return (ask(c, r) - ask(c, l - 1) + Mod) % Mod;}

ll pw2[N], ans;

ll v[N], c[2][2][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n; pw2[0] = 1;
    for (int i = 1; i <= n; i ++) pw2[i] = pw2[i - 1] * 2 % Mod;
    for (int i = 1; i <= n; ++ i) {
        cin >> p[i], pos[p[i]] = i, v[i] = 1;
        add(c[1][0], i, pw2[i - 1]);
        add(c[1][1], i, pw2[n - i]);
    }
    for (int now, i = 1; i <= n; i ++) {
        // v[pos[i]] = -1
        now = pos[i];
        if (v[now] == 0) {
            ans = (ans - pw2[n - now] * ask(c[1][0], now - 1) % Mod) % Mod;
            ans = (ans - pw2[now - 1] * ask(c[1][1], now + 1, n) % Mod) % Mod;
            add(c[0][0], now, -pw2[now - 1]);
            add(c[0][1], now, -pw2[n - now]);
        }
        else {
            ans = (ans - pw2[n - now] * ask(c[0][0], now - 1) % Mod) % Mod;
            ans = (ans - pw2[now - 1] * ask(c[0][1], now + 1, n) % Mod) % Mod;
            add(c[1][0], now, -pw2[now - 1]);
            add(c[1][1], now, -pw2[n - now]);
        }
        v[now] = -1;

        // if i > 1: v[pos[i - 1]] = 0
        if (i > 1) {
            now = pos[i - 1];
            ans = (ans + pw2[n - now] * ask(c[1][0], now - 1) % Mod) % Mod;
            ans = (ans + pw2[now - 1] * ask(c[1][1], now + 1, n) % Mod) % Mod;
            add(c[0][0], now, pw2[now - 1]);
            add(c[0][1], now, pw2[n - now]);
            v[now] = 0;
        }
        printf("%lld\n", ans = (ans % Mod + Mod) % Mod);
    }
    return 0;
}