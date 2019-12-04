#include <bits/stdc++.h>

#define mid (l + r >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)

using namespace std;

const int N = 1e6 + 5;

struct node {
    int lazy, mx, mi;
}tr[N << 1];

char s[N], t[N];

int n, len, now;

void build(int o, int l, int r) {
    tr[o].lazy = 0;
    tr[o].mx = -1e9;
    tr[o].mi =  1e9;
    if (l == r) return;
    build (lc, l, mid);
    build (rc, mid + 1, r);
}

void pushdown(int o) {
    if (tr[o].lazy == 0) return;

    tr[lc].lazy += tr[o].lazy;
    tr[lc].mx += tr[o].lazy;
    tr[lc].mi += tr[o].lazy;

    tr[rc].lazy += tr[o].lazy;
    tr[rc].mx += tr[o].lazy;
    tr[rc].mi += tr[o].lazy;

    tr[o].lazy = 0;
}

void pushup(int o) {
    tr[o].mx = max(tr[lc].mx, tr[rc].mx);
    tr[o].mi = min(tr[lc].mi, tr[rc].mi);
}

void add(int o, int l, int r, int s, int t, int v) {
    if (l != r) pushdown(o);
    if (s <= l && r <= t) {
        tr[o].lazy += v;
        tr[o].mx += v;
        tr[o].mi += v;
        return;
    }
    if (s <= mid) add(lc, l, mid, s, t, v);
    if (mid <  t) add(rc, mid + 1, r, s, t, v);
    pushup(o);
}

int ask(int o, int l, int r, int p) {
    if (l == r) return tr[o].mx;
    pushdown(o);
    return p <= mid ? ask(lc, l, mid, p) : ask(rc, mid + 1, r, p);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> len >> s; now = 1;
    for (int i = 0; i < len; i ++) {
        if (s[i] == 'L') {
            if (now != 1) {
                now --;
            }
        } else if (s[i] == 'R') {
            now ++;
        }
        n = max(n, now);
    }
    //build (1, 1, n); 
    now = 1;
    for (int i = 0; i < len; i ++) {
        if (s[i] == 'L') {
            if (now != 1) {
                now --;
            }
        } else if (s[i] == 'R') {
            now ++;
        } else {
            if (s[i] == '('){
                if (t[now] == ')') {
                    add(1, 1, n, now, n, 2);
                } else if (t[now] != '(') {
                    add(1, 1, n, now, n, 1);
                }
            } else if (s[i] == ')') {
                if (t[now] == '(') {
                    add(1, 1, n, now, n, -2);
                } else if (t[now] != ')') {
                    add(1, 1, n, now, n, -1);
                }
            } else {
                if (t[now] == '(') {
                    add(1, 1, n, now, n, -1);
                } else if (t[now] == ')') {
                    add(1, 1, n, now, n, 1);
                }
            }
            t[now] = s[i];
        }

        if (ask(1, 1, n, n) == 0 && tr[1].mi >= 0) {
            printf("%d%c", tr[1].mx, i + 1 == len ? '\n' : ' ');
        } else {
            printf("%d%c", -1, i + 1 == len ? '\n' : ' ');
        }
    }
    //for (int i = 1; i <= now; i ++) printf("%c", t[i] == 0 ? ' ' : t[i]);
}