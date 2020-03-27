#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

void get_even(int n, vi ans[]) {
    vi a(n);
    for (int i = 0; i < n; i ++)
        a[i] = i + 1;
    for (int i = 1; i <= n / 2; i ++) {
        ans[i].resize(n + 1);
        for (int j = 0; j < n / 2; j ++)
            ans[i][j * 2] = a[j], ans[i][j * 2 + 1] = a[n - 1 - j];
        int t = a[n - 1];
        for (int j = n - 1; j > 0; j --)
            a[j] = a[j - 1];
        a[0] = t;
    }
}

void get_odd(int n, vi ans[]) {
    get_even(n - 1, ans);
    for (int i = 1; i <= n / 2; i ++) {
        for (int j = n - 1; j > 0; j --)
            ans[i][j] = ans[i][j - 1] + 1;
        ans[i][0] = 1;
    }
}

ll calc(ll x) {
    if (x == 1) return 0;
    return x / 2 * x + (x & 1);
}

ll n, m;

vi ans[2020];

int main() {
    cin >> n;
    if (n == 1) {
        puts("1\n1");
        return 0;
    }
    ll l, r, mid;
    l = 1, r = 2e9, m = 1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (calc(mid) <= n) m = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (n > 2e6) {
        printf("%lld\n", m);
    }
    else {
        printf("%lld\n", m);
        if (m & 1) get_odd(m, ans);
        else       get_even(m, ans);
        int cnt = 0;
        for (int i = 1; i <= m / 2; i ++)
            for (int j = 0; j < m; j ++) {
                cnt ++;
                printf("%d%c", ans[i][j], cnt == n ? '\n' : ' ');
            }
        for (int i = m / 2 * m; i < n; i ++)
            printf("%d%c", ans[1][0], i + 1 == n ? '\n' : ' ');
    }
    return 0;
}