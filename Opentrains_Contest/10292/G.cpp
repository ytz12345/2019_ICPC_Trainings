#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 210;

string ans, str, s;

int n, len;

int cnt[26];

int vis[N][N][N], dp[N][N][N];

int dfs(int l, int r, int x) {
        if (l > r) return x == (int)str.size() - 1;
        //if (x == 0) x = (int)str.size();
        //if (x == 0) return (l == r && s[l] == str[0]);
        if (x == 0) return dp[l][r][x] = (s[r] ==  str[0] && dfs(l, r - 1, str.size() - 1) == 1);
        if (vis[l][r][x]) return dp[l][r][x];
        vis[l][r][x] = 1;
        for (int k = r - 1; k >= l; k -= (int)str.size())
                if (s[r] == str[x] && dfs(l, k, x - 1) && dfs(k + 1, r - 1, (int)str.size() - 1))
                        return dp[l][r][x] = 1;
        return dp[l][r][x] = 0;
}

bool check() {
        static int c[26];
        //cout << str << endl;
        int k = n / str.size();
        memset (c, 0, sizeof c);
        for (int i = 0; i < str.size(); i ++)
                c[str[i] - 'a'] ++;
        for (int i = 0; i < 26; i ++) {
                if (cnt[i] == 0) continue;
                if (c[i] == 0) return 0;
                if (cnt[i] % c[i] != 0 || cnt[i] / c[i] != k) return 0;
        }
        memset(vis, 0, sizeof(vis));
        return dfs(0, n - 1, str.size() - 1);
}

void judge(int x) {
        if (x >= len) return;
        for (int i = 0; i + x <= n; i ++) {
                str = s.substr(i, x);
                if (check()) {
                        len = x;
                        ans = s.substr(i, x);
                        return;
                }
        }
}

int main() {
        ios::sync_with_stdio(false);
        while (cin >> s) {
                ans = s, len = n = s.size();
                memset (cnt, 0, sizeof cnt);
                for (int i = 0; i < n; i ++)
                        cnt[s[i] - 'a'] ++;
                for (int i = 1; i * i <= n; i ++) {
                        if (n % i == 0) {
                                judge(i);
                                judge(n / i);
                        }
                }
                cout << ans << '\n';
        }
        return 0;
}