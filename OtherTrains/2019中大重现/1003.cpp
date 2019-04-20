#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long LL;
char s[107];
int main() {
    auto f = [&](LL n) -> LL {
        return 1LL * n * (n - 1) / 2;
    };
    auto g = [&](LL n) -> LL {
        return 1LL * n * (n - 1) / 2 * (n - 2) / 3;
    };
    auto h = [&](LL n) -> LL {
        return 1LL * n * (n - 1) * (n - 2) * (n - 3) / 24;
    };
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        rep(i, 1, n) scanf("%s", s);
        LL b = f(n + 1) * f(m + 1);
        LL ans = 1 + b;
        LL d = f(n + 1) * g(m + 1) + g(n + 1) * f(m + 1);
        LL e = f(n + 1) * h(m + 1) + h(n + 1) * f(m + 1);
        LL f = g(n + 1) * g(m + 1) * 2;
        LL h = g(n + 1) * g(m + 1) * 4;
        LL c = b * b - b - 6 * d - 6 * e - 6 * f - 6 * h;
        c /= 2;
        ans += c + e + f + h;
        cout << ans << '\n';
    }
}