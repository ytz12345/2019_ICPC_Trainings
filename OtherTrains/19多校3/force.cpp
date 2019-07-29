#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int M = (1 << 20) + 2019;
const int B = 2155;

int n, m, pl, pr, cur, a[N], b[N], cnt[M];

int main(){
    int op, x, y;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            b[i] = b[i - 1] ^ a[i];
        }

        
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d %d", &x, &y);
                long long ans = 0;
                for (int i = x - 1; i < y; i ++)
                    for (int j = i + 1; j <= y; j ++)
                        ans += b[i] == b[j];
                printf("%lld\n", ans);
            }
            else {
                scanf("%d", &x);
                b[x] ^= a[x], b[x] ^= a[x + 1];
                swap(a[x], a[x + 1]);
            }
        }
    }
    
    return 0;
}