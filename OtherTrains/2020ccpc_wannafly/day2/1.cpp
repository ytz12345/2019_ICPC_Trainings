#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

typedef long long ll;

char s[N];

ll n;

ll pre[N], suc[N], sum[N];

double ans, ans1, ans2;

double c[N], d[N];

const char *yu = "aeiouy";

bool is_yuan(char ch) {
    for (int i = 0; i < 6; i ++)
        if (ch == yu[i])
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++)
        if (is_yuan(s[i]))
            pre[i] = i, suc[i] = n + 1 - i, sum[i] = 1;
    for (int i = 1; i <= n; i ++)
        pre[i] += pre[i - 1], sum[i] += sum[i - 1];
    for (int i = n; i > 0; i --)
        suc[i] += suc[i + 1];
    int i;
    for (i = 1; i <= n + 1 - i; i ++) {
        c[i] += (sum[n + 1 - i] - sum[i - 1]) * i;
        c[i] += pre[i - 1] + suc[n + 2 - i];
    }
    for (; i <= n; i ++)
        c[i] = c[n + 1 - i];
    ll ss = 0;
    for (i = 1; i <= n; i ++)
        d[i] = i, ss += i;
    for (i = 1; i <= n; i ++)
        ans += c[i] / d[i];
    
    //printf("%lld %.0f\n", ans1, ans2);
    printf("%.10f\n", ans / ss);
    return 0;
}