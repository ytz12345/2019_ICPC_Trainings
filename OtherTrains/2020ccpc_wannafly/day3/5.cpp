#include <bits/stdc++.h>

using namespace std;

const int N = 520;

typedef long long ll;

int t, n, m, a[N][N];

char s[N], ch;

int main() {
    ios::sync_with_stdio(false);
    for (cin >> t; t --; ) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> s;
            for (int j = 1; j <= m; ++j) {
                //if (s[j - 1] == '1') a[i][j] = a[i - 1][j] ^ a[i][j - 1] ^ 1;
                //else                 a[i][j] = a[i - 1][j] ^ a[i][j - 1] ^ a[i - 1][j - 1];
            }
            if (i == 1) ch = s[0];
        }
        puts(ch == '0' ? "aoligei" : "call");
    }
    return 0;
}
/*
call
aoligei
aoligei
*/