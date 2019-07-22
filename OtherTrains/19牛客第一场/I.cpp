#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
typedef long long ll;
 
struct point {
    int x, y, a, b;
}p[N];
 
int y[N];
 
int n, m;
 
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)
struct node {
    ll maxv, lazy;
}tr[N << 2];
 
void pushup(int o) {
    tr[o].maxv = max(tr[lc].maxv, tr[rc].maxv);
}
 
void pushdown(int o) {
    if (!tr[o].lazy) return;
    tr[lc].lazy += tr[o].lazy;
    tr[lc].maxv += tr[o].lazy;
    tr[rc].lazy += tr[o].lazy;
    tr[rc].maxv += tr[o].lazy;
    tr[o].lazy = 0;
}
 
void build(int o, int l, int r) {
    tr[o].maxv = tr[o].lazy = 0;
    if (l == r) return;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}
 
ll ask(int o, int l, int r, int s, int t) {
    if (s <= l && r <= t) return tr[o].maxv;
    ll res = 0; pushdown(o);
    if (s <= mid) res = max(res, ask(lc, l, mid, s, t));
    if (mid <  t) res = max(res, ask(rc, mid + 1, r, s, t));
    return res;
}
 
void update(int o, int l, int r, int pos, ll v) {
    if (l == r) {
        tr[o].maxv = v;
        tr[o].lazy = 0;
        return;
    }
    pushdown(o);
    if (pos <= mid) update(lc, l, mid, pos, v);
    if (pos >  mid) update(rc, mid + 1, r, pos, v);
    pushup(o);
}  
 
void add(int o, int l, int r, int s, int t, int v) {
    if (s <= l && r <= t) {
        tr[o].lazy += v;
        tr[o].maxv += v;
        return;
    }
    pushdown(o);
    if (s <= mid) add(lc, l, mid, s, t, v);
    if (mid <  t) add(rc, mid + 1, r, s, t, v);
    pushup(o);
}
 
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i ++) {
            cin >> p[i].x >> p[i].y;
            cin >> p[i].a >> p[i].b;
            y[i] = p[i].y;
        }
        sort (y, y + n);
        m = unique(y, y + n) - y;
        for (int i = 0; i < n; i ++) {
            p[i].y = lower_bound(y, y + m,
                p[i].y) - y + 1 + 1;
        }
        m ++;
        sort (p, p + n, [&](point a, point b) {
            if (a.x != b.x) return a.x < b.x;
            return a.y > b.y;
        });
        build(1, 1, m); ll tmp;
        for (int i = 0; i < n; i ++) {
            tmp = ask(1, 1, m, 1, p[i].y);
            update(1, 1, m, p[i].y, tmp + p[i].b);
            if (1 <= p[i].y - 1) add(1, 1, m, 1, p[i].y - 1, p[i].a);
            if (p[i].y + 1 <= m) add(1, 1, m, p[i].y + 1, m, p[i].b);
        }
        printf("%lld\n", tr[1].maxv);
    }
    return 0;
}