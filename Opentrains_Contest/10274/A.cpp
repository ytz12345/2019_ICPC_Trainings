#include <bits/stdc++.h>

using namespace std;

const int N = 610;

int t, n;

struct node {
    int l, r, x;
}a[N];

vector <int> b;

int dp[N][N], vis[N][N];

int dfs(int l, int r) {
    if (l > r) return 0;
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = 1; int fg = 0;
    for (int i = 0; i < n; i ++)
        if (l <= a[i].l && a[i].r <= r) 
            fg = max(fg, a[i].x);
    if (!fg) return dp[l][r] = 0; 
    dp[l][r] = 1e18;
    for (int i = l; i <= r; i ++)
        dp[l][r] = min(dp[l][r], dfs(l, i - 1) + dfs(i + 1, r) + fg);
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t --) {
        cin >> n; b.clear();
        for (int i = 0; i < n; i ++) {
             cin >> a[i].l >> a[i].r >> a[i].x;
             b.push_back(a[i].l);
             b.push_back(a[i].r);
        }
        sort (b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        for (int i = 0; i < n; i ++) {
            a[i].l = lower_bound(b.begin(), b.end(), a[i].l) - b.begin();
            a[i].r = lower_bound(b.begin(), b.end(), a[i].r) - b.begin();
        }
        memset (vis, 0, sizeof vis);
        cout << dfs(0, b.size() - 1) << '\n';
    }
    return 0;
}