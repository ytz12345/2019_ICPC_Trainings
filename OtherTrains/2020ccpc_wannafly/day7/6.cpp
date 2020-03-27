#include <bits/stdc++.h>

using namespace std;

const int Mod = 998244353;

typedef long long ll;

ll t, n, m, x, y, k, ans;

int main() {
    ios::sync_with_stdio(false);
    for (cin >> t; t --; ) {
        cin >> n >> m >> x >> y >> k;
        if (n % 2 == 0 || m % 2 == 0) {
            ll t = min(n * m, k) % Mod; k -= t;
            ans = (1 + t) * t / 2 % Mod;
            ans = (ans + k % Mod * t % Mod) % Mod;
        }
        else {
            
        }
        printf("%lld\n", (ans % Mod + Mod) % Mod);
    }
}