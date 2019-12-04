#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, k, a[N], b[N], c[N];

vector <int> e[N];

int lb(int x) {return (x & (-x));}

void add(int i) {while (i <= n) c[i] ++, i += lb(i);}

int ask(int i) {int res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

int num, pos;

struct query {int k, p, i;}q[N];

int ans[N];

void mov() {
    add(e[num][pos]); pos ++;
    while (pos >= e[num].size()) num --, pos = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], b[i] = a[i];
    sort (b + 1, b + n + 1);
    k = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i ++) 
        e[lower_bound(b + 1, b + k + 1, a[i]) - b].push_back(i);
    num = k, pos = 0; cin >> m;
    for (int i = 1; i <= m; i ++) 
        cin >> q[i].k >> q[i].p, q[i].i = i;
    sort (q + 1, q + m + 1, [&](query x, query y){
        return x.k < y.k;
    });
    int l, r, mid;
    for (int i = 1, j = 0; i <= m; i ++) {
        while (j < q[i].k) mov(), j ++;
        l = 1, r = n; ans[q[i].i] = n;
        while (l <= r) {
            mid = l + r >> 1;
            if (ask(mid) >= q[i].p) ans[q[i].i] = mid, r = mid - 1;
            else l = mid + 1;
        }
        //cout << q[i].k << ' ' << q[i].p << ' ' << q[i].i << ' ' << ans[q[i].i] << endl;
    }
    for (int i = 1; i <= m; i ++)
        cout << a[ans[i]] << '\n';
}