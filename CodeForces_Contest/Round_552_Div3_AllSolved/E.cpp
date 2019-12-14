#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k, b[N], c[N];

struct node {
    int l, r;
} a[N];

set <int> s;

int main() {
	ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].l, a[i].r = i;
    sort (a + 1, a + n + 1, [&](node x, node y){
        return x.l > y.l;
    });
    for (int i = 1; i <= n; i ++)
        s.insert(i);
    for (int i = 1, t = 1; i <= n; i ++) {
        if (b[a[i].r]) continue;
        auto it = s.lower_bound(a[i].r);
        auto pre = it, suc = it;
        for (int j = 0; j <= k; j ++) {
            c[*pre] = t; b[*pre] = 1;//cerr<<(*pre)<< ' ';
            if (pre == s.begin() || j == k) break;
            pre --;
        }
        for (int j = 0; j <= k; j ++) {
            c[*suc] = t; b[*suc] = 1;//cerr<<(*suc) <<' ';
            suc ++;
            if (suc == s.end()) break;
        }
        s.erase(pre, suc);
        t = 3 - t;
        //cerr << endl << a[i].r << ' ' << s.size() << endl;
    }
    for (int i = 1; i <= n; i ++)
        cout << c[i];
    cout << endl;
    return 0;
}