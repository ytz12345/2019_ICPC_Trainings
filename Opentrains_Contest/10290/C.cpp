#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
#define dwn(i, j, k) for (int i = int(j); i >= int(k); -- i)
const int N = 1e6 + 7;
typedef long long LL;
typedef vector<int> VI;
int n, a[N], b[N];
bool isp[N], ok[N];
int pr[N / 10];
inline void sieve() {
    memset(isp, 1, sizeof(isp));
    rep(i, 2, N - 1) {
        if (isp[i]) pr[++ pr[0]] = i;
        rep(j, 1, pr[0]) {
            if (i * pr[j] >= N) break;
            isp[i * pr[j]] = 0;
            if (i % pr[j] == 0) break;
        }
    }
}
int main() {
    sieve();
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    auto calc = [&](int x) -> int {
        int ret = 1;
        for (int i = 1; 1LL * pr[i] * pr[i] <= x; ++ i)
            if (x % pr[i] == 0) {
                while (x % pr[i] == 0) {
                    x /= pr[i];
                    if (x % pr[i] == 0) {
                        x /= pr[i];
                        ret *= pr[i];
                    }
                }
            }
        return ret;
    };
    rep(i, 1, n) b[i] = calc(a[i]), ok[a[i]] = 1;
    //rep(i, 1, n) cout << b[i] << ' '; cout << '\n';
    LL ans = 0;
    auto check = [&](int x, int q) {
        int t1 = x / q, t2 = x / q / q;
        int lim = min(int(1e6) / t1, int(sqrt(1e6 / t2 + .5))) + 5;
        for (int p = q + 1; p <= lim; ++ p) {
            if (__gcd(p, q) != 1) continue;
            LL x1 = 1ll * t1 * p, x2 = 1ll * t2 * p * p;
            if (x1 > 1000000 || x2 > 1000000) break;
            if (ok[x1] && ok[x2]) {ans ++;
                       // cout << x << ' ' << x1 << ' ' << x2 << endl;
            }
        }
    };
    rep(i, 1, n) {
        for (int q = 1; 1LL * q * q <= b[i]; ++ q)
            if (b[i] % q == 0) {
                check(a[i], q);
                if (q != b[i] / q) {
                    check(a[i], b[i] / q);
                }
            }
    }
    cout << ans << '\n';
}



