#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
typedef pair<int, int> P;
ll qmul(ll x, ll y, ll p) {
    x %= p; y %= p;
    ll ret = x * y - (ll)((long double)x * y / p + 0.5) * p;
    return ret < 0 ? ret + p : ret;
}
inline ll qpow(ll a, ll b, ll p) {
    ll c = 1;
    while (b) {
        if (b & 1) c = qmul(c, a, p);
        a = qmul(a, a, p);
        b >>= 1;
    }
    return c;
}
// 10 ^ k == 1 (mod 9 * p)
ll calc(ll p) {
    if (p == 3) return 3;
    ll m = 9ll * p;
    ll n = 6ll * (p - 1);
    ll ret = n;
    for (int i = 1; 1ll * i * i <= n; ++ i)
    if (n % i == 0) {
        if (qpow(10, i, m) == 1) ret = min(ret, (ll)i);
        if (i != n / i) {
            if (qpow(10, n / i, m) == 1) ret = min(ret, n / i);
        }
    }
    return ret;
}
vector<P> factorize(ll n) {
    vector<P> v;
    for (int i = 2; 1ll * i * i <= n; ++ i)
    if (n % i == 0) {
        P p(i, 0);
        while (n % i == 0)  n /= i, p.second ++;
        v.push_back(p);
    }
    if (n != 1) v.push_back(P(n, 1));
    return v;
}
ll f[70];
int main() {
    ios::sync_with_stdio(0);
    ll T, n, m, p;
    cin >> T;
    while (T --) {
        cin >> p >> n >> m;
        if (p == 2) {
            cout << 0 << endl; continue;
        }
        ll cyc = calc(p);
        vector<P> v = factorize(cyc);
        memset(f, 0, sizeof(f));
        int maxc = 0;
        for (P pp: v)  maxc = max(maxc, pp.second);
        ll ans = 0, last = 0;
        // cout << cyc << endl;
        // for (P pp: v) cout << pp.first << ' ' << pp.second << endl;
        // cout << maxc << endl;
        // cout << cyc << endl;
        for (int i = 1; i <= maxc; ++ i) {
            ll mul = 1;
            for (P pp: v) {
                mul *= (ll)pow(pp.first, (pp.second + i - 1) / i);
            }
            f[i] = (n / mul) - last;
            last = n / mul;
            ans += max(m - i + 1, 0ll) * f[i];
            // cout << i << ' ' << f[i] << ' ' << (m - i + 1) * f[i] << ' ' << mul << endl;
        }
        cout << ans << endl;
    }   
 
}