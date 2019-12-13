#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5;

int n, k;

ll a[N], ans;

priority_queue<ll, vector<ll>, greater<ll>> q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] == -1) k = i;
    }
    if (k == n) ans = 0;
    else {
        ans = a[n]; int m = n / 2;
        while (k < m) {
            for (int i = m; i < m * 2; i ++)
                q.push(a[i]);
            ans += q.top();
            q.pop(); m >>= 1;
        }
    }    
    cout << ans << endl;
    return 0;
}