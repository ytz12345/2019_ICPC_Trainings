#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

typedef long long ll;

const int N = 410;

const int Mod = 1e9 + 7;

int e[N][N], f[N][N];

int d[N][N];

uint a[N], b[N], c[N];

int n, m, u, k;

char op[2][5];

int p1[N], p2[N];

int c1[N], c2[N];

queue <int> q;

uint calc() {
    uint res = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i != j) res += (d[i][j] != 0) * a[i - 1] * b[j - 1];
    return res;
}

void work(int e1[N][N], int e2[N][N], const int &op, const int &po) {
    memset (c1, 0, sizeof c1);
    memset (c2, 0, sizeof c2);
    p1[0] = 0, p2[0] = 0;
    for (int i = 0; i < k; i ++) {
        cin >> c[i];
        q.push(c[i]), c2[c[i]] = 1;
    }
   while (!q.empty()) {
        int now = q.front(); q.pop();
        p2[++ p2[0]] = now;
        for (int v = 1; v <= n; v ++)
            if (e2[now][v] && !c2[v])
                c2[v] = 1, q.push(v);
    }
    q.push(u); c1[u] = 1;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        p1[++ p1[0]] = now;
        for (int v = 1; v <= n; v ++)
            if (e1[now][v] && !c1[v])
                c1[v] = 1, q.push(v);
    }
    for (int i = 0; i < k; i ++) {
        e2[u][c[i]] ^= 1, e1[c[i]][u] ^= 1;
    }
    memset (c1, 0, sizeof c1);
    memset (c2, 0, sizeof c2);
    if (po > 0) {
        for (int i = 1; i <= p1[0]; i ++)
            (c1[p1[i]] += d[p1[i]][u]) %= Mod;
        for (int j = 1; j <= p2[0]; j ++)
            for (int i = 0; i < k; i ++)
                (c2[p2[j]] += d[c[i]][p2[j]]) %= Mod;
    }
    else {
        for (int i = 1; i <= p1[0]; i ++)
            (c1[p1[i]] += d[u][p1[i]]) %= Mod;
        for (int j = 1; j <= p2[0]; j ++)
            for (int i = 0; i < k; i ++)
                (c2[p2[j]] += d[p2[j]][c[i]]) %= Mod;
    }
    for (int i = 1; i <= p1[0]; i ++)
        for (int j = 1; j <= p2[0]; j ++) {
            if (po > 0) (d[p1[i]][p2[j]] += 1ll * op * c1[p1[i]] * c2[p2[j]] % Mod) %= Mod;
            else (d[p2[j]][p1[i]] += 1ll * op * c1[p1[i]] * c2[p2[j]] % Mod) %= Mod;
        }
}

int main() {
    //#define DEBUG
    #ifndef DEBUG
        freopen("reachability.in","r",stdin);
        freopen("reachability.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin >> n >> m >> a[1] >> b[1]; a[0] = b[0] = 1;
    for (int i = 2; i < n; i ++)
        a[i] = a[i - 1] * a[1], b[i] = b[i - 1] * b[1];
    for (int i = 1; i <= n; i ++)
        d[i][i] = 1;
    while (m --) {
        cin >> op[0] >> op[1] >> u >> k;
        if (op[0][0] == '+') {
            if (op[1][0] == 'o') work(f, e, 1, 1);
            else work(e, f, 1, -1);
        }
        else {
            if (op[1][0] == 'o') work(f, e, -1, 1);
            else work(e, f, -1, -1);
        }
        printf("%u\n", calc());
    }
    return 0;
}