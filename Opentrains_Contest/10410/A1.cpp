#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll L, R;

struct tree{
        ll t[400007 * 4 * 8];
        ll p[400007 * 4 * 8];

        void push(int v){
                if (p[v] != 0){
                        t[v] += p[v];
                        if (v * 2 + 1 < 400007 * 4 * 8) p[v * 2 + 1] += p[v];
                        if (v * 2 + 2 < 400007 * 4 * 8) p[v * 2 + 2] += p[v];
                        p[v] = 0;
                }
        }

        void up(int v, int vl, int vr, int l, int r, ll val){
                push(v);
                if (r < vl || l > vr) return;
                if (vl >= l && vr <= r){
                        p[v] += val;
                        push(v);
                } else {
                        int vm = (vl + vr) >> 1;
                        up(v * 2 + 1, vl, vm, l, r, val);
                        up(v * 2 + 2, vm + 1, vr, l, r, val);
                        t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
                }
        }

        ll get(){
                push(0);
                return t[0];
        }
} tr;

int main(){
#ifdef LOCAL
        freopen("A_input.txt", "r", stdin);
        //freopen("A_output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin >> n >> L >> R;
        L--;

        vector<pair<pair<ll, ll>, pair<ll, ll> > > t;

        while(n--){
                ll x, y, s;
                cin >> x >> y >> s;
                t.pb(mp(mp(x - 2 * R, s), mp(y - 2 * R, y)));
                t.pb(mp(mp(x + 1, -s), mp(y - 2 * R, y)));
                t.pb(mp(mp(x - L - R, -s), mp(y - L - R, y - (R - L))));
                t.pb(mp(mp(x - (R - L) + 1, s), mp(y - L - R, y - (R - L))));


                t.pb(mp(mp(x - L - R - 1, 0), mp(y - 2 * R, y)));
                t.pb(mp(mp(x, 0), mp(y - 2 * R, y)));
        }

        sort(all(t));

        //for (auto &c : t) cout << c.x.x << ' ' << c.x.y << ' ' << c.y.x << ' ' << c.y.y << endl;

        vector<ll> kek;

        for (auto c : t) kek.pb(c.y.x), kek.pb(c.y.y), kek.pb(c.y.x + 1), kek.pb(c.y.x - 1), kek.pb(c.y.y - 1), kek.pb(c.y.y + 1);

        sort(all(kek));
        kek.resize(unique(all(kek)) - kek.begin());

        for (auto &c : t){
                c.y.x = lower_bound(all(kek), c.y.x) - kek.begin();
                c.y.y = lower_bound(all(kek), c.y.y) - kek.begin();
        }

        ll ans = 0;

        int i = 0;
        sort(all(t));

        while(1){
                if (i == t.size()) break;
                int j = i;

                while(j + 1 < t.size() && t[j + 1].x.x == t[i].x.x) j++;

                for (int s = i; s <= j; s++){
                        auto &c = t[s];
                        tr.up(0, 0, kek.size(), c.y.x, c.y.y, c.x.y);
                }

                ans = max(ans, tr.get());

                i = j + 1;
        }

        cout << ans;
}