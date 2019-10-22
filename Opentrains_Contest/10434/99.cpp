#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long double eps = 1e-9;

const int N = 3e5 + 5;

ll n, py;

struct seg {
        ll sum, cnt;
}tr[N << 2];

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)

void add(int o, int l, int r, int s, int t, int id) {
        if (s <= l && r <= t) {
                tr[o].sum += id;
                tr[o].cnt ++;
                return;
        }
        if (s <= mid) add(lc, l, mid, s, t, id);
        if (t >  mid) add(rc, mid + 1, r, s, t, id);
}

int ask(int o, int l, int r, int p) {
        py = (py + tr[o].sum) % n;
        if (l == r) return tr[o].cnt;
        return (p <= mid ? ask(lc, l, mid, p) : ask(rc, mid + 1, r, p)) + tr[o].cnt;
}

struct node {
        ll sum;
        long double v;
        node *c[2];
        int r, id, siz;
        void update() {
                siz = c[0] -> siz + c[1] -> siz + 1;
                sum = c[0] -> sum + c[1] -> sum + id;
        }
        void init(long double, int);
};
node *null = new node();
node *lt[N], *rt[N];

void node::init(long double x, int d) {
        v = x, r = rand(), siz = 1, id = sum = d;
        c[0] = c[1] = null;
}

void rot(node *&o, int d) {
        node *tmp = o -> c[!d];
        o -> c[!d] = tmp -> c[d], tmp -> c[d] = o;
        o -> update(), tmp -> update(), o = tmp;
}

void ins(node *&o, long double x, int id) {
        if (o == null) {
                o = new node();
                o -> init(x, id);
                return;
        }
        int d = x < o -> v ? 0 : 1;
        ins(o -> c[d], x, id);
        if (o -> c[d] -> r < o -> r) rot(o, !d);
        o -> update();
}

int ask(node *o, long double x) {
        int res = 0;
        while (o != null) {
                if (o -> v < x) o = o -> c[1];
                else {
                        py = (py + o -> id + o -> c[1] -> sum) % n;
                        res += o -> c[1] -> siz + 1, o = o -> c[0];
                }
        }
        return res;
}

void add(long double l, long double r, int id) {
        l += n, r += n;
        int L = ceil(l) + 0.5, R = floor(r) + 0.5;
        if (L < R) add(1, 1, n * 3, L + 1, R, id);
        ins(lt[L], L - l, id);
        if (r - R > eps) ins(rt[R], r - R, id);
}

int ask(long double x) {
        x += n;
        int X = ceil(x) + 0.5;
        if (fabs(x - X) > eps)
                return ask(1, 1, n * 3, X) +
                        ask(rt[X - 1], x - (X - 1) - eps) +
                        ask(lt[X], X - x - eps);// + flag;
        else
                return ask(1, 1, n * 3, X)
                  + ask(lt[X], 0 - eps);

}

int main() {
        srand(time(NULL));
        ios::sync_with_stdio(false);
        cin >> n; int op; long double c, r;
        for (int i = 0; i <= n * 3; i ++)
                lt[i] = rt[i] = null;
        for (int id = 0, i = 1; i <= n * 2; i ++) {
                cin >> op >> c, c += py;
                while (c >= n) c -= n;
                if (op == 0) {
                        cin >> r;
                        add(c - r, c + r, id ++);
                }
                else {
                        printf("%d\n", ask(c));
                        //printf("py=%lld\n", py);
                }
        }
        return 0;
}