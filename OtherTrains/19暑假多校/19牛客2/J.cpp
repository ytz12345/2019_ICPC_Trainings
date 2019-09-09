#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 1e6 + 5;

const int inf = 1e9;

const int M = 1e8 + 5;

const int Mid = 5e7;

int n, l[N], r[N];

int pre[N], suf[N];

int val[M], cnt[M];

ll ans, tmp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d %d", &l[i], &r[i]);

    pre[1] = r[1] - l[1] + 1;
    for (int i = 2; i <= n; i ++) 
        pre[i] = r[i] - l[i] + 1 + max(0, pre[i - 1] - (l[i] - r[i - 1] - 1));

    suf[n] = r[n] - l[n] + 1;
    for (int i = n - 1; i >= 1; i --)
        suf[i] = r[i] - l[i] + 1 + max(0, suf[i + 1] - (l[i + 1] - r[i] - 1));

    for (int i = 1, j, lb, ub, now; i <= n; i = j + 1) {
        j = i;
        while (j < n && pre[j] + suf[j + 1] > (l[j + 1] - r[j] - 1)) j ++;

        lb = max(0, l[i] - suf[i]);
        ub = min(inf - 1, r[j] + pre[j]);

        for (int k = i; k <= j; k ++)
            for (int p = l[k]; p <= r[k]; p ++)
                val[p - lb] = 1;
       
        tmp = 0, now = Mid, cnt[now] = 1;
        for (int k = lb; k <= ub; k ++) {
            if (val[k - lb]) tmp += cnt[now ++];
            else tmp -= cnt[-- now];
            cnt[now] ++, ans += tmp;
        }

        now = Mid;
        for (int k = lb; k <= ub; k ++) {
            if (val[k - lb]) now ++, val[k - lb] = 0;
            else now --;
            cnt[now] --;
        }
    }

    cout << ans << endl;
    return 0;
}