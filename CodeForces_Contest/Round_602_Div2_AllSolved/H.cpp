#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mid (l + r >> 1)

const ll inf = 1ll << 60;
const int Mod = 998244353;
const int inv2 = (Mod + 1) / 2;

struct node {
    static node *null;
    node* c[2];
    bool real;

    node() {
        real = 0;
        c[0] = c[1] = null;
    }

    void ins(ll s, ll t, ll l = 0, ll r = inf - 1) {
        if (s <= l && r <= t) return real = 1, void();
        if (s <= mid) {
            if (c[0] == null) c[0] = new node;
            c[0] -> ins(s, t, l, mid);
        }
        if (t >  mid) {
            if (c[1] == null) c[1] = new node;
            c[1] -> ins(s, t, mid + 1, r);
        }
    }

    void init() {
        int n; ll l, r; cin >> n;
        for (int i = 0; i < n; i ++) {
            cin >> l >> r;
            ins(l, r);
        }
    }
};

typedef pair<node*, node*> pr;
vector <pr> q[70];

ll work(ll pre, ll d) {
    for (pr pt : q[d])
        if (pt.first -> real || pt.second -> real)
            return (pre % Mod + ((1ll << d) - 1) % Mod * inv2 % Mod) % Mod * ((1ll << d) % Mod) % Mod;
    ll res = 0;
    for (ll x = 0; x < 2; x ++) {//由于58行使用了x<<(d-1)所以这里x一定要用ll
        q[d - 1].clear();
        for (pr pt : q[d])
            for (int y = 0; y < 2; y ++) 
                if (pt.first -> c[y] != node::null && pt.second -> c[x ^ y] != node::null) 
                    q[d - 1].push_back(pr(pt.first -> c[y], pt.second -> c[x ^ y]));
        if (q[d - 1].size()) res = (res + work(pre | (x << (d - 1)), d - 1)) % Mod;
    }
    return res;
}

node* node::null = new node;
node *ta = new node;
node *tb = new node;

int main() {
    ios::sync_with_stdio(false);
    ta -> init();
    tb -> init();
    q[60].push_back(pr(ta, tb));
    cout << (work(0, 60) % Mod + Mod) % Mod << endl;
    return 0;
}