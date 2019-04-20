#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i < (k); i ++)

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

inline int getchar_() {
    static const int SIZE = 1 << 20;
    static char *S, *T = S, buf[SIZE];
    if (S == T) {
        T = fread(buf, 1, SIZE, stdin) + (S = buf);
        if (T == S) return -1;
    }
    return *S ++;
}

inline void in(int &x) {
    static int ch;
    while (ch = getchar_(), ch < 48)
        if (ch == -1) exit(0);
    x = ch - 48;
    while (ch = getchar_(), ch > 47)
        x = x * 10 + ch - 48;
}

int M, n, m, k, x[2], y[2];

int e[10000000], f[10000000];

inline int g(const int &x, const int &y) {
    if (y < 0 || y >= m || x < 0 || x >= n) return -1;
    return x * m + y;
} 

inline int h(int *a, const int &b) {
    if (b >= M || b < 0) return 0;
    return a[b];
}

int main() {
    ios::sync_with_stdio(false);
    while (1) {
        in(n), in(m), in(k), M = n * m;
        for (int i = 0; i < M; i ++)
            e[i] = f[i] = 0;
        for (int t, i = 0; i < k; i ++) {
            in(x[0]), in(y[0]), in(x[1]), in(y[1]);
            x[0] --, y[0] --, x[1] --, y[1] --;
            e[g(x[0], y[0])] += 1;
            t = g(x[0], y[1] + 1); if (t < M && t != -1) e[t] -= 1;
            t = g(x[1] + 1, y[0]); if (t < M && t != -1) e[t] -= 1;
            t = g(x[1] + 1, y[1] + 1); if (t < M && t != -1) e[t] += 1;
        }
        for (int i = 0; i < n; i ++) 
            for (int j = 0; j < m; j ++) {
                f[g(i, j)] = h(f, g(i - 1, j)) + h(f, g(i, j - 1)) + h(e, g(i, j)) - h(f, g(i - 1, j - 1));
                e[g(i, j)] = h(e, g(i - 1, j)) + h(e, g(i, j - 1)) + (h(f, g(i, j)) != 0) - h(e, g(i - 1, j - 1));
            }
        in(k);
        for (int i = 0; i < k; i ++) {
            in(x[0]), in(y[0]), in(x[1]), in(y[1]);
            x[0] --, y[0] --, x[1] --, y[1] --;
            puts(h(e, g(x[1], y[1])) - h(e, g(x[0] - 1, y[1])) - h(e, g(x[1], y[0] - 1)) + h(e, g(x[0] - 1, y[0] - 1)) == (y[1] - y[0] + 1) * (x[1] - x[0] + 1) ? "YES" : "NO");
        }
    }
    return 0;
}