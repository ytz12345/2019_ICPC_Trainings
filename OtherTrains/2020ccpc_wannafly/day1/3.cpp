#include <bits/stdc++.h>

using namespace std;

const int Mod = 998244353;

typedef long long ll;
typedef __int128 int128;

const int128 one = 1;

inline ll sqr(ll x) {
    return x * (x - 1) / 2;
}

ll p2;

ll calc(ll x, ll k = Mod - 2, ll p = Mod) {
    ll res = 1;
    for (x %= p; k > 0; k >>= 1, x = x * x % p) 
        if (k & 1) res = res * x % p; 
    return (res % p + p) % p;
}

inline ll f(ll n, ll l, ll r) {

    int128 res = sqr(n) % Mod * (r - l + 1) % Mod; 
 
    for (int i = l, last; i <= n; i = last + 1) {
        last = n / (n / i);
        if (last > r) last = r;
        int128 t1 = n % i, t2 = n % last, t4 = one * (t1 + t2) * (last - i + 1) / 2;
        res = (res - sqr(n / i + 1) % Mod * t4 % Mod) % Mod;
        int128 t3 = n * (last - i + 1) - t4 * (n / i + 1);
        t3 /= n / i; t3 %= Mod;
        res = (res - sqr(n / i) % Mod * t3 % Mod) % Mod;

        if (last == r) break;
    }
    return (res % Mod + Mod) % Mod;
}

ll t, n, l, r, ans;

int main() {
    ios::sync_with_stdio(false);
    p2 = calc(2);
    for (cin >> t; t --; ) {
        cin >> n >> l >> r;
        ans = (f(n, l, r) % Mod + Mod) % Mod;
        cout << ans << endl;
    }
    return 0;
}