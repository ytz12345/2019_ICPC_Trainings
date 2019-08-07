#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int B = 1000;
 
const int N = 2e5 + 10;
 
int s[N], val[N], sum[450][N];
 
int u[N], v[N], tag[N];
 
int k, bel[N];
 
int t, n, m;
 
mt19937 gen(time(NULL));
 
#define in(x) scanf("%d", &x)
 
void init() {
    int x, y;
    in(n), in(m);
    k = (m + B - 1) / B;
    for (int i = 1; i <= n; i ++)
        s[i] = 0;
    for (int i = 1; i <= k; i ++) {
        tag[i] = 1;
        for (int j = 1; j <= n; j ++)
            sum[i][j] = 0;
    }
    for (int i = 1; i <= m; i ++) {
        bel[i] = (i - 1) / B + 1;
        in(x), in(y), u[i] = x, v[i] = y;
        sum[bel[i]][x] ^= val[y];
        sum[bel[i]][y] ^= val[x];
    }
}
 
void modify(int l, int r) {
    for (int i = l, up = min(r, bel[l] * B); i <= up; i ++) {
        s[u[i]] ^= val[v[i]];
        s[v[i]] ^= val[u[i]];
    }
    if (bel[l] != bel[r]) {
        for (int i = (bel[r] - 1) * B + 1; i <= r; i ++) {
            s[u[i]] ^= val[v[i]];
            s[v[i]] ^= val[u[i]];
        }
    }
    for (int i = bel[l] + 1; i < bel[r]; i ++)
            tag[i] ^= 1;
}
 
int main() {
    for (int i = 0; i < N; i ++)
        val[i] = gen() % LONG_MAX;
    for (in(t); t --; ) {
        init();
        in(m);
        for (int op, l, r; m --; ) {
            in(op), in(l), in(r);
            if (op == 1) modify(l, r);
            else {
                int res1 = s[l], res2 = s[r];
                for (int i = 1; i <= k; i ++)
                    if (tag[i]) {
                        res1 ^= sum[i][l];
                        res2 ^= sum[i][r];
                    }
                putchar('0' ^ (res1 == res2));
            }
        }
        puts("");
    }
    //printf("%d\n", clock());
    return 0;
}