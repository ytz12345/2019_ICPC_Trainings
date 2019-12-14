#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int n, a[N], b[N];

int x, y;

long long ans = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (b[a[i]] && ans > a[i]) ans = a[i], x = b[a[i]], y = i;
        b[a[i]] = i;
    }
    for (int i = 1; i < N; i ++) {
        for (int z = 0, j = i; j < N; j += i) {
            if (!b[j]) continue;
            if (z == 0) z = j;
            else if (ans > 1ll * z / i * j) ans = 1ll * z / i * j, x = b[z], y = b[j];
        }
    }
    if (x > y) swap(x, y);
    cout << x << ' ' << y << endl;
    return 0;
}