#pragma GCC optimize(3)
#include <cmath>
#include <cstdio>
#include <random>
#include <cassert>
#include <algorithm>
using namespace std;
typedef unsigned long long uLL;
#define N 100000 + 5
#define M 200000 + 5
#define K 200 + 5
 
int Case, k, e, n, m, q, E[M][2];
bool Flip[K];
uLL Fix[N], Cur[K][N], Sum[K][N];
 
inline void Handle(int id, int j)
{
    int u = E[j][0], v = E[j][1];
    Cur[id][u] ^= Fix[v];
    if (u != v) Cur[id][v] ^= Fix[u];
}
 
int main()
{
    mt19937_64 gen(593119681);
    for (scanf("%d", &Case); Case; Case --)
    {
        scanf("%d%d", &n, &m);
        k = min((int(sqrt(m)) - 1) / 3 + 1, 300), e = (m - 1) / k + 1;
        for (int i = 1; i <= n; i ++)
            Fix[i] = gen();
        for (int t = 1; t <= k; Flip[t] = 0, t ++)
            for (int i = 1; i <= n; i ++)
                Cur[t][i] = Sum[t][i] = 0;
        for (int i = 1, u, v; i <= m; i ++)
        {
            int id = (i - 1) / e + 1;
            scanf("%d%d", &u, &v);
            E[i][0] = u, E[i][1] = v;
            if (u != v)
            {
                Cur[id][u] ^= Fix[v], Cur[id][v] ^= Fix[u];
                Sum[id][u] ^= Fix[v], Sum[id][v] ^= Fix[u];
            }
            else Cur[id][u] ^= Fix[v], Sum[id][u] ^= Fix[v];
        }
        scanf("%d", &q);
        for (int i = 1, op, a, b; i <= q; i ++)
        {
            scanf("%d%d%d", &op, &a, &b);
            if (op == 1)
            {
                int id_a = (a - 1) / e + 1, id_b = (b - 1) / e + 1;
                if (id_a != id_b)
                {
                    int low_a = (id_a - 1) * e + 1, upp_a = min(id_a * e, m);
                    int low_b = (id_b - 1) * e + 1, upp_b = min(id_b * e, m);
                    if (upp_a - a + 1 > (upp_a - low_a + 1) / 2)
                    {
                        Flip[id_a] ^= 1;
                        for (int j = low_a; j < a; j ++)
                            Handle(id_a, j);
                    }
                    else for (int j = a; j <= upp_a; j ++)
                        Handle(id_a, j);
                    if (b - low_b + 1 > (upp_b - low_b + 1) / 2)
                    {
                        Flip[id_b] ^= 1;
                        for (int j = b + 1; j <= upp_b; j ++)
                            Handle(id_b, j);
                    }
                    else for (int j = low_b; j <= b; j ++)
                        Handle(id_b, j);
                    for (int t = id_a + 1; t < id_b; t ++)
                        Flip[t] ^= 1;
                }
                else for (int j = a; j <= b; j ++)
                    Handle(id_a, j);
            }
            else
            {
                uLL x = 0, y = 0;
                for (int t = 1; t <= k; t ++)
                {
                    x ^= Cur[t][a] ^ (Flip[t] ? Sum[t][a] : 0);
                    y ^= Cur[t][b] ^ (Flip[t] ? Sum[t][b] : 0);
                }
                putchar('0' + (x == y));
            }
        }
        puts("");
    }
    return 0;
}