#include <cstdio>

int a[233333];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n); a[0] = 0;
        for (int i = 1, last; i <= n; i = last + 1) {
            last = n / (n / i);
            a[++ a[0]] = n / i;
        }
        a[++ a[0]] = 0;
        printf("%d\n", a[0]);
        for (int i = a[0]; i > 0; i --)
            printf("%d%c", a[i], i == 1 ? '\n' : ' ');
    }
    return 0;
}