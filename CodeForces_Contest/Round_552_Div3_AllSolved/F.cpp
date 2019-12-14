#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, m, k, g[N];

ll a[N], s[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) dp[i] = s[i] = s[i - 1] + a[i];
    for (int x, y, i = 1; i <= m; i ++) cin >> x >> y, g[x] = max(g[x], y);
    for (int i = 1; i <= k; i ++)
        for (int j = 1; j <= i; j ++)
            dp[i] = min(dp[i], dp[i - j] + s[i] - s[i - j + g[j]]);
    cout << dp[k] << endl;
    return 0;
}