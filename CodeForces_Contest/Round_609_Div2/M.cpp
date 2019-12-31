#include <bits/stdc++.h>

using namespace std;

const int N = 2019;

int n, m, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];
    sort (a, a + n);
    sort (b, b + n);
    for (int i = 0; i < n; i ++) {
        int x, flag = 1;
        for (int j = 0; j < n; j ++) {
            if (j == 0) {
                x = ((b[j] - a[(i + j) % n]) % m + m) % m;
            }            
            else if (x != ((b[j] - a[(i + j) % n]) % m + m) % m) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << x << endl;
            return 0;
        }
    }
}