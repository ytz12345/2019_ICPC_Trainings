#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pr;

const int Mod = 998244353;

ll t, n, k;

ll dp[55];

vector <int> f;
vector <pr> w;

ll fac[55];

ll calc(ll x, ll k = Mod - 2, ll p = Mod) {
    ll res = 1;
    for (x %= p; k > 0; k >>= 1, x = x * x % p)
        if (k & 1) res = res * x % p;
    return res;
}

ll c(ll x, ll y) {
    return fac[x] * calc(fac[y]) % Mod * calc(fac[x - y]) % Mod;
}

int main() {
    ios::sync_with_stdio(false);
    fac[0] = 1;
    for (int i = 1; i <= 50; i ++)
        fac[i] = fac[i - 1] * i % Mod;
    for (cin >> t; t --; ) {
        memset (dp, 0, sizeof dp);
        dp[0] = 1; f.clear(); w.clear();
        cin >> n >> k;
        for (int i = 2; i <= n; i ++) 
            if (k % i == 0)
                f.push_back(i);
        for (int v : f) {
            w.push_back(pr(v, fac[v - 1]));
            ll last = 1;
            for (int i = v * 2; i <= n; i += v) {
                last *= c(i, v); last %= Mod;
                w.push_back(pr(i, calc(fac[v - 1], i / v) * last % Mod));
            }
        }
        for (auto v : w) {
            for (int i = n; i >= v.first; i --)
                dp[i] = (dp[i] + dp[i - v.first] * v.second % Mod * c(n - (i - v.first), v.first) % Mod) % Mod;
            //cout << dp[n] << endl;
        }
        int ans = 0;
        for (int i = 0; i <= n; i ++)
            ans = (ans + dp[i]) % Mod, cout <<i << ' ' << dp[i] << endl;
        cout << (ans % Mod + Mod) % Mod << endl;
    }
    return 0;
}