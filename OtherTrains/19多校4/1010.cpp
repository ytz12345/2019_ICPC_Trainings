#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
#define dwn(i, j, k) for (int i = int(j); i >= int(k); -- i)
using namespace std;
typedef long long ll;
const int N = 5000;
bool isp[N];
int pr[N];
void sieve() {
    memset(isp, 1, sizeof(isp));
    isp[1] = 0;
    rep(i, 2, N - 1) {
        if (isp[i]) pr[++ pr[0]] = i;
        rep(j, 1, pr[0]) {
            if (1ll * i * pr[j] >= N) break;
            isp[i * pr[j]] = 0;
            if (i % pr[j] == 0) break;
        }
    }
}
ll gcd(ll a, ll b) {
    if (!b) return a; return gcd(b, a % b);
}
ll mul(ll x, ll y, ll p) {
    x %= p; y %= p;
    ll ret = x * y - (ll)((long double)x * y / p + 0.5) * p;
    return ret < 0 ? ret + p : ret;
}
ll qpow(ll x, ll k, ll p) {
    ll ret = 1 % p;
    for( ; k > 0; k >>= 1, x = mul(x, x, p))
        (k & 1) && (ret = mul(ret, x, p));
    return ret;
}
bool miller_rabin(ll n) {
    if(n == 2) return 1;
    if(n < 2 || !(n & 1)) return 0;
    ll s = 0, r = n - 1;
    for( ; !(r & 1); r >>= 1, ++s);
    for(int i = 1; pr[i] < n && pr[i] < 25; ++i) {
        ll cur = qpow(pr[i], r, n), nxt;
        for(int j = 0; j < s; ++j) {
            nxt = mul(cur, cur, n);
            if(nxt == 1 && cur != 1 && cur != n - 1) return 0;
            cur = nxt;
        }
        if(cur != 1) return 0;
    }
    return 1;
}
ll polardRho(ll n) {
    ll i = 1, x = rand() % n;
    ll y = x, k = 2, d = 1;
    do {
        d = gcd(x - y + n, n);
        if (d != 1 && d != n) return d;
        if (++ i == k) y = x, k <<= 1;
        x = (mul(x, x, n) - 1 + n) % n; 
    } while (y != x);
    return n;
}
vector<ll> fac; // 保存素因子, O(1/4)
void find(ll n) {
    if (n < 2) return;
    if (miller_rabin(n)) {
        fac.push_back(n);
        return;
    }
    ll x = polardRho(n);
    find(x);
    find(n / x);
}
inline ll sqr(ll x) {
    return x * x;
}
inline ll sqr3(ll x) {
    return x * x * x;
}

inline ll sqr4(ll x) {
    return x * x * x * x;
}

int main() {
    ios::sync_with_stdio(0);
    sieve();
    int T;
    ll n;
    cin >> T;
    while (T --) {
        cin >> n;
        if (n == 1) {
            cout << 0 << endl; 
            continue;
        }
        int ans = 100000;
        rep(i, 1, pr[0]) {
            int c = 0;
            while (n % pr[i] == 0) c ++, n /= pr[i];
            if (c) ans = min(ans, c);
        }
            
        if (n == 1) {
            cout << ans << endl; continue;
        }

        ll x = (ll)pow(n + .5, 1. / 4), p = -1;
        for (ll i = x - 5; i <= x + 5; ++ i) 
            if (sqr4(i) == n) {
                p = i; break;
            }
        if (p != -1) {
            ans = min(ans, 4);
            cout << ans << endl; continue;
        }

        x = (ll)pow(n + .5, 1. / 3), p = -1;
        for (ll i = x - 5; i <= x + 5; ++ i) 
            if (sqr3(i) == n) {
                p = i; break;
            }
        if (p != -1) {
            ans = min(ans, 3);
            cout << ans << endl; continue;
        }
        
        x = (ll)pow(n + .5, .5), p = -1;
        for (ll i = x - 5; i <= x + 5; ++ i) 
            if (sqr(i) == n) {
                p = i; break;
            }
        if (p != -1) {
            ans = min(ans, 2); cout << ans << endl; continue;
        }

        ans = min(ans, 1);
        cout << ans << endl;
    }
    //cout << clock() << endl;
}