#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
const int N = 210;
int n, m;
int a[N], c[N];
ll dp[N][4];
vector<int> g[N];
int main() {
    while (~scanf("%d%d", &n, &m)) {
        rep(i, 1, n) {
            scanf("%d", a + i);
            c[i] = a[i];
        }
        sort(c + 1, c + 1 + n);
        int tt = unique(c + 1, c + 1 + n) - c - 1;
        rep(i, 1, n) a[i] = lower_bound(c + 1, c + 1 + tt, a[i]) - c;
 
        rep(i, 1, tt) g[i].clear();
        rep(i, 1, n) g[a[i]].push_back(i);
 
        int cg = upper_bound(c + 1, c + 1 + tt, m) - c - 1;
        ll f0 = 1ll * (m - cg) * (m - cg) * (m - cg);
        ll f3 = 0;
        memset(dp, 0, sizeof(dp));
        rep(i, 1, cg) dp[g[i][0]][1] = 1;
        rep(i, 1, n) {
            f3 += dp[i][3];
            rep(j, 1, 2) {
                rep(k, 1, cg) {
                    auto it = lower_bound(g[k].begin(), g[k].end(), i + 1);
                    if (it == g[k].end()) continue;
                    else dp[*it][j + 1] += dp[i][j];
                }
            }
        }
 
        ll f1 = 0;
        rep(i, 1, n) {
            if (i != g[a[i]][0]) continue;
            ll tmp = m;
            rep(j, 1, cg) {
                if (g[j].back() > i) tmp --;
            }
            f1 += 1ll * tmp * (tmp - 1) / 2;
        }
        rep(i, 1, n) {
            if (i != g[a[i]].back()) continue;
            ll tmp = m;
            rep(j, 1, cg) {
                if (g[j][0] < i) tmp --;
            }
            f1 += 1ll * tmp * (tmp - 1) / 2;
        }

        ll f2 = 1ll * m * m * m - f0 - f1 - f3;
        printf("%lld %lld %lld %lld\n", f0, f1, f2, f3);
    }
}