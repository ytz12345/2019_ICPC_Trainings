#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int Mod = 998244353;

typedef long long ll;

typedef __int128 int128;

struct node {
    ll l, r, s;
    int id;

    bool operator < (const node &a) const { return s < a.s;}
}a[N];

int n;

ll g[N];

ll calc(ll x, ll k, ll p = Mod) {
    ll res = 1;
    for (x %= p; k > 0; k >>= 1, x = x * x % p) 
        if (k & 1) res = res * x % p; 
    return (res % p + p) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].s = a[i].l + a[i].r;
        a[i].id = i + 1;
    }
    sort (a, a + n);
    
    ll ans0 = 0, ans1 = 1;

    for (int i = 0; i < n; i ++) {
        ans1 *= a[i].r - a[i].l + 1;
        ans1 %= Mod;
        g[i] = calc(a[i].r - a[i].l + 1, Mod - 2);
    }

    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (a[i].r <= a[j].l) continue;
            ll tmp = 0;
            if (a[j].r >= a[i].r) {
                if (a[i].l > a[j].l) {
                    tmp += (a[i].r - a[j].l + a[i].l - a[j].l) * (a[i].r - a[i].l + 1) / 2;
                }
                else {
                    tmp += (a[i].r - a[j].l + 1) * (a[i].r - a[j].l) / 2;
                }
            }
            else {
                if (a[i].l > a[j].l) {
                    tmp += (a[j].r - a[j].l + a[i].l - a[j].l) * (a[j].r - a[i].l + 1) / 2 + (a[i].r - a[j].r) * (a[j].r - a[j].l + 1);
                }
                else {
                    tmp += (a[j].r - a[j].l + 1) * (a[j].r - a[j].l) / 2 + (a[i].r - a[j].r) * (a[j].r - a[j].l + 1);
                }
            }
            tmp = tmp % Mod * g[i] % Mod * g[j] % Mod; 
            ans0 = (ans0 + tmp) % Mod;
        }    
    }
    cout << (ans0 % Mod + Mod) % Mod << endl;
    return 0;
}
