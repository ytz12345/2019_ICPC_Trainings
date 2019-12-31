#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, k, a[N], b[N], c[N];

ll ans;

int lb(int x) {return x & (-x);}

void add(int i) {while (i <= k) c[i] ++, i += lb(i);}

int ask(int i) {int res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k; int l = n + 1, r = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (1 <= a[i] && a[i] <= k) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    for (int cnt = 0, i = l; i <= r; i ++) {
        if (a[i] > k) {
            ans += min(cnt, k - cnt);
        } else {
            b[++ cnt] = a[i];
        }
    }
    for (int i = 1; i <= k; i ++) {
        ans += ask(k) - ask(b[i]);
        add(b[i]);
    }
    cout << ans << endl;
    return 0;
}