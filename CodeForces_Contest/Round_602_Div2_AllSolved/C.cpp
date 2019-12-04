#include <bits/stdc++.h>

using namespace std;

const int N = 2019;

int t, n, k;

char s[N];

int m, a[N], b[N];

inline void reverse(int l, int r) {
    m ++, a[m] = l, b[m] = r;
    for ( ; l < r; l ++ , r --)
        swap(s[l], s[r]);
}

inline void check(int i) {
    if (s[i] == '(') return;
    for (int j = i + 1; ; j ++) {
        if (s[j] == '(') {
            reverse(i, j);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    for (cin >> t; t --; ) {
        cin >> n >> k >> s; m = 0;
        for (int i = 0; i < n / 2; i ++)
            check(i);

        for (int i = 1; i < k; i ++) 
            reverse(i * 2 - 1, n / 2 + i - 1);
        printf("%d\n", m);
        for (int i = 1; i <= m; i ++)
            printf("%d %d\n", a[i] + 1, b[i] + 1);
    }
}