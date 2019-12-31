#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

ll n, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n; int x = 0, y = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        m += a[i] / 2;
        if (a[i] % 2 == 1) {
            if (i & 1) x ++;
            else y ++;
        }
    }
    cout << m + min(x, y) << endl;
    return 0;
}