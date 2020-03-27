#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

ll n, m, k, a0, b0, ans;

vector<ll> a[2], b[2];

ll calc(ll x) {
    ll res = 0;
    for (int i = 0, j = int(b[0].size()) - 1; i < a[0].size(); i ++) {
        while (j >= 0 && a[0][i] * b[0][j] >= x) j --;
        res += int(b[0].size()) - 1 - j;
    }
    for (int i = 0, j = int(b[1].size()) - 1; i < a[1].size(); i ++) {
        while (j >= 0 && a[1][i] * b[1][j] >= x) j --;
        res += int(b[1].size()) - 1 - j;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int x, i = 0; i < n; i ++) {
        cin >> x;
        if (x == 0) a0 ++;
        else if (x < 0) a[0].push_back(x);
        else a[1].push_back(x);
    }
    for (int x, i = 0; i < m; i ++) {
        cin >> x;
        if (x == 0) b0 ++;
        else if (x < 0) b[0].push_back(x);
        else b[1].push_back(x);
    }
    ll z = 0, f = 0, l = 0;
    z = 1ll * a[0].size() * b[0].size() + 1ll * a[1].size() * b[1].size();
    f = 1ll * a[1].size() * b[0].size() + 1ll * a[0].size() * b[1].size();
    l = n * m - z - f;
    if (k > z && k <= z + l) ans = 0;
    else if (k <= z) {
        for (int i = 0; i < a[0].size(); i ++) a[0][i] = -a[0][i];
        for (int i = 0; i < b[0].size(); i ++) b[0][i] = -b[0][i];
        for (int i = 0; i < 2; i ++) {
            sort (a[i].begin(), a[i].end());
            sort (b[i].begin(), b[i].end());
        }
        ll l = 0, r = 1e12 + 5, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (calc(mid) < k) r = mid - 1;
            else ans = mid, l = mid + 1;
        } 
    }
    else {
        k -= z + l; k = f + 1 - k;
        for (int i = 0; i < a[0].size(); i ++) a[0][i] = -a[0][i];
        for (int i = 0; i < b[0].size(); i ++) b[0][i] = -b[0][i];
        for (int i = 0; i < 2; i ++) {
            sort (a[i].begin(), a[i].end());
            sort (b[i].begin(), b[i].end());
        }
        swap(a[0], a[1]);
        ll l = 0, r = 1e12 + 5, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (calc(mid) < k) r = mid - 1;
            else ans = mid, l = mid + 1;
        } 
        ans = -ans;
    }

    cout << ans << endl;
    return 0;
}