#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t --) {
        cin >> n;
        if (n == 3) {
            printf("%d\n", 3);
            for (int i = 0; i < 3; i ++) {
                printf("%d %d\n", i, 0);
            }
        }
        else if (n == 4) {
            printf("%d\n%d %d\n", 7, 0, 1);
            for (int i = 1;i < n; i ++) {
                printf("%d %d\n", i, 0);
                printf("%d %d\n", i, 1);
            }
        }
        else {
            printf("%d\n", n * 3);
            for (int i = 0; i < n; i ++) {
                printf("%d %d\n", i, i % (n - 2));
                printf("%d %d\n", i, (i + 1) % (n - 2));
                printf("%d %d\n", i, (i + 2) % (n - 2));
            }
        }
    }
    return 0;
}   