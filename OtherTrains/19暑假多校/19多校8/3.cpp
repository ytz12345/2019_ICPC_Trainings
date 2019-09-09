#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
vector<int> v;
ll pw[20], f[20];
ll a[] = {0, 1, 199981, 199982, 199983, 199984, 199985, 199986, 199987, 199988, 199989, 199990, 200000, 200001, 1599981, 1599982, 1599983, 1599984, 1599985, 1599986, 1599987, 1599988, 1599989, 1599990, 2600000, 2600001, 13199998, 35000000, 35000001, 35199981, 35199982, 35199983, 35199984, 35199985, 35199986, 35199987, 35199988, 35199989, 35199990, 35200000, 35200001, 117463825, 500000000, 500000001, 500199981, 500199982, 500199983, 500199984, 500199985, 500199986, 500199987, 500199988, 500199989, 500199990, 500200000, 500200001, 501599981, 501599982, 501599983, 501599984, 501599985, 501599986, 501599987, 501599988, 501599989, 501599990, 502600000, 502600001, 513199998, 535000000, 535000001, 535199981, 535199982, 535199983, 535199984, 535199985, 535199986, 535199987, 535199988, 535199989, 535199990, 535200000, 535200001, 1111111110};
// f[i] 表示 0 ～ 10^i - 1
void dfs(int crp, ll x, ll sum, int ones) {
    if (crp == -1) {
        // cout << x << ' ' << sum << endl;
        if (x - 1 == sum) v.push_back(x - 1); return;
        return;
    }

    ll nsum = sum;
    rep(i, 0, 9) {
        if (crp == 18 && i > 1) break;

        if (i) {
            nsum += f[crp] + ones * pw[crp];
            if (i == 2) nsum += pw[crp];
        }
        
        if (nsum > x + (i + 1) * pw[crp]) continue;
        dfs(crp - 1, x + i * pw[crp], nsum, ones + (i == 1));
    }
}
int count(ll x) {
    int c = 0;
    while (x) {
        if (x % 10 == 1) c ++; x /= 10;
    }
    return c;
}
void init() {
    pw[0] = 1ll; rep(i, 1, 18) pw[i] = pw[i - 1] * 10ll;

    f[1] = 1; // 0 ~ 9
    rep(i, 2, 18) {
        f[i] = f[i - 1] * 10ll + pw[i - 1];
    }
    dfs(18, 0, 0, 0);
    cout << v.size() << endl;
    for (int i: v) cout << i << ", "; cout << endl;
}

int main() {
    // int nn = 1e7; ll ss = 0;
    // rep(i, 1, nn) {
    //     ss += count(i);
    //     if (i == ss) cout << i << endl;
    // }
    // cout << "*******" << endl;

    // init();
    int _, d, x;
    scanf("%d", &_);
    while (_ --) {
        scanf("%d%d", &d, &x);
        if (d != 1) {
            printf("0\n"); continue;
        }
        else {
            int k = upper_bound(a, a + 84, x) - a - 1;
            printf("%lld\n", a[k]);
        }
    }
}