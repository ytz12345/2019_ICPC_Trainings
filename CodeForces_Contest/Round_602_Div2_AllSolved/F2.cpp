#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

const int Mod = 998244353;

typedef long long ll;

int n, m, k;

int a[N], b[N];

ll fac[N], inv[N], pw[N];

ll com(ll n, ll m) {
    return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

ll calc(ll x, ll k) {
    ll res = 1;
    for (x %= Mod; k > 0; k >>= 1, x = x * x % Mod)
        if (k & 1) res = res * x % Mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k; pw[0] = 1, fac[0] = 1, inv[0] = 1, inv[1] = 1;
    for (int i = 1; i <= n; i ++) {
        pw[i] = pw[i - 1] * (k - 2) % Mod;
        fac[i] = fac[i - 1] * i % Mod;
        if (i != 1) inv[i] = inv[Mod % i] * (Mod - Mod / i) % Mod;
    }
    for (int i = 2; i <= n; i ++) 
        inv[i] = inv[i] * inv[i - 1] % Mod;
    for (int i = 1; i <= n; i ++) cin >> b[i];
    a[m = 1] = b[1];
    for (int i = 2; i <= n; i ++)
        if (b[i] != a[m])
            a[++ m] = b[i];
    if (m != 1 && a[m] == a[1]) m --;
    ll ans = 0;
    for (int t = 1; t <= m; t ++) {
        ans += com(m, t) * pw[m - t] % Mod 
            * ((t % 2 == 1 ? calc(2, t): calc(2, t) - com(t, t / 2)) * calc(2, Mod - 2) % Mod) % Mod;
        ans %= Mod;
    }
    if (m == 1 || k == 1) ans = 0;
    for (int i = m + 1; i <= n; i ++)
        ans = ans * k % Mod;
    cout << (ans % Mod + Mod) % Mod << endl;
    return 0;
}