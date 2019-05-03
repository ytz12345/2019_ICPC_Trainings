#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int dp[2][N][N];

int nb[N];

int x, a, y, b, l;

bool judge(int k) {
    for (int i = 0; i <= x && (i - 1) * a < k; i ++) {
        nb[i] = (k - i * a + b - 1) / b;
        if (nb[i] > y) nb[i] = -1;
    }
    memset(dp[0], 0, sizeof dp[0]);
    dp[0][x][y] = 1;
    for (int i = 1; i <= l; i ++) {
        for (int j = )
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> x >> a >> y >> b >> l) {
        int l = 0, r = x * a + b * y, mid, ans = 0;
        while (l <= r) {
            mid = l + r >> 1;
            if (judge(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}   