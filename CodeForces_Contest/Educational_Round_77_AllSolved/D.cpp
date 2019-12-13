#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int m, n, k, t;

int a[N];

struct trap {int l, r, d;}b[N];

int judge(int mid) {
    int res = n + 1;
    for (int i = 1; i <= k; ) {
        if (b[i].d > a[mid]) {
            int j = i, R = b[i].r;
            while (j <= k && b[j].l <= R) {
                if (b[j].d > a[mid]) R = max(R, b[j].r);
                j ++;
            }
            res += (R - b[i].l + 1) * 2;
            i = j;
        }
        else {
            i ++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    a[0] = 1e9;
    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; i ++)
        cin >> a[i];
    sort (a + 1, a + m + 1, [&](int x, int y) {
        return x > y;
    });
    for (int i = 1; i <= k; i ++)
        cin >> b[i].l >> b[i].r >> b[i].d;
    sort (b + 1, b + k + 1, [&](trap x, trap y){
        return x.l < y.l;
    });
    int l = 0, r = m, mid, ans = 0;
    while (l <= r) {
        mid = l + r >> 1;
        //cout << mid << ' ' << judge(mid) << endl;
        if (judge(mid) <= t) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}