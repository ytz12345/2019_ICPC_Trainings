#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector <int> e[N], f[N], s[N], t[N];

char str[N];

int n, m;

int ask(vector<int> g[N], int i, int j, int k) {
    int x[2] = {i - k - 1, i + k}, y[2] = {j - k - 1, j + k};
    x[0] = max(x[0], 0), y[0] = max(y[0], 0);
    x[1] = min(x[1], n), y[1] = min(y[1], m);
    return g[x[1]][y[1]] + g[x[0]][y[0]] - g[x[0]][y[1]] - g[x[1]][y[0]]; 
}

void work(int k) {
    int sqr = (k * 2 + 1) * (k * 2 + 1);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            f[i][j] = 0;
    for (int i = 1 + k; i + k <= n; i ++)
        for (int j = 1 + k; j + k <= m; j ++) 
            if (ask(s, i, j, k) == sqr)
                f[i][j] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            t[i][j] = f[i][j] + t[i - 1][j] + t[i][j - 1] - t[i - 1][j - 1];
}

bool judge(int k) {
    work(k);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) 
            if (e[i][j] == 1 && ask(t, i, j, k) == 0)
                return 0; 
    return 1;
}

void print(vector<int> f[N]) {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) 
            printf("%c", f[i][j] ? 'X' : '.');
        puts("");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    e[0].resize(m + 1, 0); 
    f[0].resize(m + 1, 0);
    s[0].resize(m + 1, 0);
    t[0].resize(m + 1, 0);
    for (int i = 1; i <= n; i ++) {
        e[i].resize(m + 1);
        f[i].resize(m + 1);
        s[i].resize(m + 1);
        t[i].resize(m + 1);
        cin >> str;
        for (int j = 1; j <= m; j ++) {
            e[i][j] = str[j - 1] == 'X';
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + e[i][j];
        }
    }
    int l = 0, r = (min(n, m) - 1) / 2, mid, ans = 0;
    while (l <= r) {
        mid = l + r >> 1;
        if (judge(mid)) ans = mid, l = mid + 1;
        else r = mid - 1; 
    } 
    work(ans);
    printf("%d\n", ans);
    print(f);
}