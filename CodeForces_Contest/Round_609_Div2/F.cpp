#include <bits/stdc++.h>

using namespace std;

namespace my_hash {
    const int N = (1 << 19) - 1;
    struct E {
        int v;
        E *nxt;
    }*g[N + 1], pool[N], *cur = pool, *p;
    int vis[N + 1], T;
    void ins(int v) {
        int u = v & N;
        if (vis[u] < T) vis[u] = T, g[u] = NULL;
        for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return;
        p = cur ++; p -> v = v; p -> nxt = g[u]; g[u] = p;
    }
    int ask(int v) {
        int u = v & N;
        if (vis[u] < T) return 0;
        for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return 1;
        return 0;
    }
    void init() {T ++, cur = pool;}
}

const int N = 3e5 + 5;

int n, m, a[N], b[N];

bool cmp(int x, int y) {
    return x > y;
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin >> n; m = (n + 2) / 3;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort (a + 1, a + n + 1, cmp);
    my_hash::init();
    my_hash::ins(a[1]);
    b[++ b[0]] = a[1];
    for (int i = 2; i <= n; i ++) {
        int j = lower_bound(b + 1, b + b[0] + 1, a[i] * 2, cmp) - b;
        //printf("%d %d\n", i, j);
        int ok = 1;
        if (j * n <= 1e8) {
            for (int k = 1; k < j; k ++)
                if (my_hash::ask(b[k] - a[i])) {
                    ok = 0;
                    break;
                }
        }
        else {
            for (int k, tim = 1e8 / n; tim --; ) {
                k = rand() % (j - 1) + 1;
                if (my_hash::ask(b[k] - a[i])) {
                    ok = 0;
                    break;
                }
            }
        }

        if (ok) b[++ b[0]] = a[i], my_hash::ins(a[i]);
    }
    printf("%d\n", m);
    for (int i = 1; i <= m; i ++)
        printf("%d%c", b[i], i == m ? '\n' : ' ');
    return 0; 
}