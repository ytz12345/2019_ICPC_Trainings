#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a[2020];

ll ans, s;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort (a, a + n);
    for (int i = n - 1; i >= 0; i --) {
        ans += s * a[i];
        s += a[i];
    }
    cout << ans << endl;
}