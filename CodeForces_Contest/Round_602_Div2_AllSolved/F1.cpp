#include <bits/stdc++.h>

using namespace std;

const int N = 2019;

const int Mod = 998244353;

typedef long long ll;

int n, m, k;

int a[N], b[N];

ll f[N][N], pw[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k; pw[0] = 1;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i ++) pw[i] = pw[i - 1] * (k - 2) % Mod;
    for (int i = 1; i <= n; i ++) cin >> b[i];
    a[m = 1] = b[1];
    for (int i = 2; i <= n; i ++)
        if (b[i] != a[m])
            a[++ m] = b[i];
    if (m != 1 && a[m] == a[1]) m --;
    for (int i = 0; i <= m; i ++) f[i][0] = 1;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= i; j ++)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % Mod;
    ll ans = 0;
    for (int i = 1; i <= m; i ++)
        for (int j = 0; j < i && i + j <= m; j ++)
            ans = (ans + f[m][i] * f[m - i][j] % Mod * pw[m - i - j] % Mod) % Mod;
    if (m == 1) ans = 0;
    for (int i = m + 1; i <= n; i ++)
        ans = ans * k % Mod;
    cout << (ans % Mod + Mod) % Mod << endl;
    return 0;
}