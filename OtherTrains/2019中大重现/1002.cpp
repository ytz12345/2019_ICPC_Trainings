#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
int a[107];
char s[20];
int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n > 60) {
            rep(i, 1, n) scanf("%s", s);
            printf("YES\n");
            continue;
        }
        rep(i, 1, n) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        bool flag = 0;
        rep(i, 3, n) {
            if (a[i - 1] + a[i - 2] > a[i]) { flag = 1; break; }
        }   
        if (flag) printf("YES\n"); else printf("NO\n");
    }
}