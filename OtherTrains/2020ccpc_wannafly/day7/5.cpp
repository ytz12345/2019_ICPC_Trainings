#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, p;

ll a[110] = {0, 1, 2, 6};

ll calc(ll x, ll k, ll p) {
    ll res = 1;
    for (x %= p; k > 0; k >>= 1, x = x * x % p)
        if (k & 1) res = res * x % p;
    return res;
}

int main() {
    cin >> n >> p;
    for (int i = 4; i <= n; i ++) {
        a[i] = a[i - 1] * (i * 9 - 8) % p - a[i - 2] * (i * 13 - 23) * 2 % p + a[i - 3] * (i * 2 - 5) * 12 % p; 
        a[i] = a[i] * calc(i, p - 2, p) % p;
        a[i] = (a[i] % p + p) % p;
        //cout << i << ' ' << a[i] << endl;
    }
    cout << a[n] << endl;
    return 0;
}