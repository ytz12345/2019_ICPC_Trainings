#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i < (k); i ++)

#define mid ((l + r) >> 1)
#define ls (o << 1)
#define rs (o << 1 | 1)

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

inline int getchar_() {
    static const int SIZE = 1 << 20;
    static char *S, *T = S, buf[SIZE];
    if (S == T) {
        T = fread(buf, 1, SIZE, stdin) + (S = buf);
        if (T == S) return -1;
    }
    return *S ++;
}

inline void in(int &x) {
    static int ch;
    while (ch = getchar_(), ch < 48)
        if (ch == -1) exit(0);
    x = ch - 48;
    while (ch = getchar_(), ch > 47)
        x = x * 10 + ch - 48;
}

int n, m;

struct node {
    ll sum, lazy, mmin;
}tr[N << 2];

void pushup(const int &o){
    tr[o].sum = tr[ls].sum + tr[rs].sum;
    tr[o].mmin = min(tr[ls].mmin, tr[rs].mmin);
}

void pushdown(const int &o, const int &l, const int &r){
    if (tr[o].lazy == 0) return;
    tr[ls].sum = tr[o].lazy * (mid - l + 1);
    tr[rs].sum = tr[o].lazy * (r - mid);
    tr[ls].mmin = tr[ls].lazy = tr[rs].mmin = tr[rs].lazy = tr[o].lazy;
    tr[o].lazy = 0;
}

void build(const int &o, const int &l, const int &r) {
    if (l == r) {
        tr[o].sum = r;
        tr[o].lazy = 0;
        tr[o].mmin = r;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(o);
}

int ask(const int &o, const int &l, const int &r, const int &v) {
    if (l == r) return r;
    pushdown(o, l, r);
    if (tr[rs].mmin <= v) return ask(rs, mid + 1, r, v);
    return ask(ls, l, mid, v);
}


ll sums(const int &o, const int &l, const int &r, const int &s, const int &t) {
    if (s <= l && r <= t) return tr[o].sum;
    pushdown(o, l, r); ll res = 0;
    if (s <= mid) res += sums(ls, l, mid, s, t);
    if (mid <  t) res += sums(rs, mid + 1, r, s, t);
    return res; 
}

void change(const int &o, const int &l, const int &r, const int &s, const int &t, const ll &v) {
    if (s <= l && r <= t) {
        tr[o].sum = v * (r - l + 1);
        tr[o].lazy = tr[o].mmin = v;
        return;
    }
    pushdown(o, l, r); 
    if (s <= mid) change(ls, l, mid, s, t, v);
    if (mid <  t) change(rs, mid + 1, r, s, t, v);
    pushup(o);
}

int main() {
    ios::sync_with_stdio(false);
    while (1) {
        in(n), in(m);
        memset(tr, 0, sizeof tr);
        build(1, 1, n);
        for (int p, l, r, i = 0; i < m; i ++) {
            in(l), in(r);
            p = ask(1, 1, n, l);
            if (p >= r) puts("0");
            else printf("%lld\n", sums(1, 1, n, p + 1, r) - 1ll * (r - p) * l);
            if (p < r) change(1, 1, n, p + 1, r, l);
        }
    }
    return 0;
}
