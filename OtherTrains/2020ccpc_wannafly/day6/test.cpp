#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int t, n;

int dp[N][4], ans;

int a[N], b[N];

int c[4], d[4];

int main() {
    ios::sync_with_stdio(false);
    for (cin >> t; t --; ) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            for (int j = 0; j < 4; ++ j)
                dp[i][j] = 1e9;
        }
        dp[0][0] = dp[0][3] = 0;
        if (a[0] != b[0]) dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i < n; i ++) {
            c[0] = a[i], c[1] = a[i] + 1, c[2] = b[i] - 1, c[3] = b[i];
            d[0] = a[i - 1], d[1] = a[i - 1] + 1, d[2] = b[i - 1] - 1, d[3] = b[i - 1];
            for (int j = 0; j < 4; j ++) {
                if (a[i] == b[i] && (j == 1 || j == 2)) continue;
                for (int k = 0; k < 4; k ++) {
                    if (a[i - 1] == b[i - 1] && (k == 1 || k == 2)) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + (abs(c[j] - d[k]) + 1) / 2);
                }
            }
        }
        ans = min(dp[n - 1][0], dp[n - 1][3]);
        if (a[n - 1] != b[n - 1]) ans = min(ans, min(dp[n - 1][1], dp[n - 1][2]));
        cout << ans << endl; 
    }
    return 0;
}