#include <bits/stdc++.h>

using namespace std;

namespace IO {
    static const int SIZE = 1 << 20;

    inline int get_char() {
        static char *S, *T = S, buf[SIZE];
        if (S == T) {
            T = fread(buf, 1, SIZE, stdin) + (S = buf);
            if (S == T) return -1;
        }
        return *S ++;
    }

    inline void in(int &x) {//for int
        static int ch;
        while (ch = get_char(), ch < 48);x = ch ^ 48;
        while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
    }

    char buffer[SIZE];
    char *s = buffer;
    
    void flush() {
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    
    inline void print(const char ch) {
        if(s - buffer > SIZE - 2) flush();
        *s++ = ch;
    }

    inline void print(char *str) {
        while(*str != 0) 
            print(char(*str ++));
    }

    inline void print(int x) {
        static char buf[25];
        static char *p = buf;
        if (x <  0) print('-'), x = -x;
        if (x == 0) print('0');
        while(x) *(++ p) = x % 10, x /= 10;
        while(p != buf) print(char(*(p --) ^ 48));
    }
};

struct node {
    static node null;

    node* par;
    node* c[2];
    bool  flip;
    int   wei;
    node* best;

    node(): par(&null), c{&null, &null}, flip(0), wei(0), best(this) {}
    node(node const &) = delete;//禁止使用该函数

    void unflip() {//pushdown
        if (!flip) return;
        c[0] -> flip ^= 1;
        c[1] -> flip ^= 1;
        swap(c[0], c[1]);
        flip = 0;
    }

    void setchild(int d, node *newchild) {
        c[d] = newchild;
        newchild -> par = this;
        best = this;
        for (int d = 0; d < 2; d ++)
            if (c[d] -> best -> wei > best -> wei)
                best = c[d] -> best;
    }

    int rotate(node *&parent) {
        parent = this -> par;
        parent -> unflip();
        this -> unflip();
        for (int d = 0; d < 2; d ++) {
            if (parent -> c[d] == this) {
                node *grand = parent -> par;
                parent -> setchild(d, this -> c[!d]);
                this -> setchild(1 - d, parent);
                for (int dd = 0; dd < 2; dd ++) 
                    if (grand -> c[dd] == parent)
                        grand -> c[dd] = this;
                this -> par = grand;
                return d;
            }
        }
        return -1;
    }

    void splay() {
        int lastd = -1;
        node *lastp;
        node *curp;
        while (1) {
            int d = rotate(curp);
            if (d < 0) break;
            if (d == lastd) {
                lastp -> rotate(lastp);
                lastd = -1;
            }
            else
                lastd = d;
            lastp = curp; 
        }
    }

    void access(node *newchild = &null) {
        splay();
        setchild(1, newchild);
        if (par != &null)
            par -> access(this);
    }

    void evert() {//makeroot
        access();
        splay();
        flip = 1;
        access();
    }
};

node node::null;

struct edge:node {
    node *u;
    node *v;
};

#define fi first
#define se second

struct vft {
    vector <vector<pair<int, int>>> data;

    vft(int m): data(m, vector<pair<int, int>>(1, make_pair(-1, 0))) {}

    static int lb(int i) {return (i & (-i));}

    void update(int t, int i, int v) {
        for (; i < (int)data.size(); i |= i + 1) {
            int w = data[i].back().se + v;
            if (data[i].back().fi == t)
                data[i].back().se = w;
            else
                data[i].emplace_back(t, w);
        }
    }

    int prefsum(int t, int i) const {
        int sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) 
            sum += (lower_bound(data[i].begin(), data[i].end(), make_pair(t + 1, 0)) - 1) -> se;
        return sum;
    }
};

void testcase() {
    static node *nul = &node::null;

    int n, m;
    IO::in(n), IO::in(m);
    vector <pair<int, pair<int, int>>> I(m);
    for (int i = 0; i < m; i ++)
        IO::in(I[i].se.fi), IO::in(I[i].se.se), IO::in(I[i].fi);
    sort (I.begin(), I.end(), greater<pair<int,pair<int,int>>>());
    node V[n];
    edge E[m];
    vft T(m);
    for (int i = 0; i < m; i ++) {
        edge *e = &E[i];
        e -> wei = I[i].fi;
        e -> u = &V[I[i].se.fi - 1];
        e -> v = &V[I[i].se.se - 1];
        e -> u -> evert();
        e -> v -> evert();
        if (e -> u -> par != nul) {
            e -> u -> access();
            edge *f = (edge *) e -> v -> best;
            f -> evert();
            f -> u -> evert();
            f -> par = nul;
            f -> v -> evert();
            f -> par = nul;
            T.update(i, f - E, -f -> wei);
        }
        e -> u -> evert();
        e -> u -> par = e;
        e -> v -> evert();
        e -> v -> par = e;
        T.update(i, e - E, +e -> wei);
    }

    int q, l, h;
    int t = 0;
    for (IO::in(q); q --; ) {
        IO::in(l), IO::in(h);
        l -= t, h -= t;
        l = upper_bound(I.begin(), I.end(), make_pair(l, make_pair(0, 0)), greater<pair<int,pair<int,int>>>()) - I.begin();
        h = upper_bound(I.begin(), I.end(), make_pair(h + 1, make_pair(0, 0)), greater<pair<int,pair<int,int>>>()) - I.begin();
        t = T.prefsum(l - 1, m - 1) - T.prefsum(l - 1, h - 1);
        IO::print(t), IO::print('\n');
    }
    IO::flush();
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    for (IO::in(t); t --; )
        testcase();
    return 0;
}