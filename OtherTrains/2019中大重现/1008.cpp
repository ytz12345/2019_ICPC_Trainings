#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i < (k); i ++)

using namespace std;

int n, m, k;

int a[3][100][100];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> k) {
        int cnt = 0;
        rep(i, 0, n) rep(j, 0, m) cin >> a[0][i][j];
        rep(i, 0, m) rep(j, 0, k) cin >> a[1][i][j];
        rep(i, 0, k) rep(j, 0, n) cin >> a[2][i][j];
        rep(i, 0, n) rep(j, 0, m) rep(p, 0, k) {
            if (a[0][i][j] && a[1][j][p] && a[2][p][i])
                cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}