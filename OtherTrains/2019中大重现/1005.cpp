#include <bits/stdc++.h>

using namespace std;

char s[300010], t[2400010];

int a[600010];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int x, i = 0; i < n; i ++) {
        x = s[i];
        for (int j = 0; j < 8; j ++)
            t[(i) * 8 + j] = x & 1, x >>= 1;
    }
    int s = n * 8 / 6;
    for (int x, i = 0; i < s; i ++) {
        x = 0;
        for (int k = i * 6; k < (i + 1) * 6; k ++)
            x = (x << 1) | t[k];
        a[i] = x;
    }
    for (int i = 0; i < s; i ++) {
        printf("%d", a[i]);
        printf(" ");
    }
    return 0;
}