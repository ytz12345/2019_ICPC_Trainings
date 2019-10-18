#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 21;

int n, q;

struct tree {
    int cnt[N];
    int a[1 << N];

    void set() {
        memset (a, 0, sizeof a);
        for (int i = 0; i < n; i ++)
            cnt[i] = 1 << (n - i - 1);
    }

    void upd(int i) {
        a[i += 1 << n] ^= 1;
        for (int j, k = 0; k < n; k ++, i = j) {
            j = i >> 1;
            cnt[k] -= a[j] < 2;
            if (a[i] == a[i ^ 1]) a[j] = a[i];
            else a[j] = 2;
            cnt[k] += a[j] < 2;
        }
    }
}t[2];

ll calc() {
    ll res = 0;
    for (int i = 0; i < n; i ++)
        res += 1ll * t[0].cnt[i] * t[1].cnt[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q; t[0].set(), t[1].set();
    ll sum = calc();
    for (int op, x; q --; ) {
        cin >> op >> x;
        t[op].upd(x - 1);
        printf("%lld\n", (sum - calc()) * 4 + 1);
    }
}
