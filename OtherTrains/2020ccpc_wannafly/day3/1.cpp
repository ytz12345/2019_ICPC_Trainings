#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

typedef long long ll;

ll n, a[N][N], b[N];

ll sum, s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 2) {
        puts("1 1");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j], sum += a[i][j];
    // cout << sum << endl;
    sum /= (n - 1) * 2;
    for (int i = 1; i <= n; ++i) {
        s = 0;
        for (int j = 1; j <= n; ++j) 
            s += a[i][j];
        printf("%lld%c", (s - sum) / (n - 2), i == n ? '\n' : ' ');
    }
}