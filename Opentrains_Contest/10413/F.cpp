#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PollardRho {
    const int T = 20;
    ll qmul(ll a, ll b, ll p) {
        ll c = 0;
        for (a %= p; b > 0; b >>= 1) {
            if (b & 1) c += a;
            if (c >= p) c -= p;
            a <<= 1;
            if (a >= p) a -= p;
        }
        return c;
    }
    ll qpow(ll x, ll k, ll p) {
        ll res = 1;
        for (x %= p; k > 0; k >>= 1, x = qmul(x, x, p))
            if (k & 1) res = qmul(res, x, p);
        return res;
    }
    bool check(ll a, ll n, ll x, ll t) {
        ll res = qpow(a, x, n), last = res;
        for (int i = 1; i <= t; i ++) {
            res = qmul(res, res, n);
            if (res == 1 && last != 1 && last != n - 1) return 1;
            last = res;
        }
        if (res != 1) return 1;
        return 0;
    }
    bool millerRabin(ll n) {
        if (n < 2) return 1;
        ll x = n - 1, t = 0;
        while (!(x & 1)) x >>= 1, t ++;
        bool flag = 1;
        if (t >= 1 && (x & 1)) {
            for (int k = 0; k < T; k ++) {
                ll a = rand() % (n - 1) + 1;
                if (check(a, n, x, t)) {
                    flag = 1;
                    break;
                }
                flag = 0;
            }
        }
        if (!flag || n == 2) return 0;
        return 1;
    }
    ll pollardRho(ll x, ll c) {
        ll i = 1, x0 = rand() % x, y = x0, k = 2;
        while (1) {
            i ++;
            x0 = qmul(x0, x0, x) + c % x;
            ll d = abs(__gcd(y - x0, x));
            if (d != 1 && d != x) return d;
            if (y == x0) return x;
            if (i == k) y = x0, k <<= 1;
        }
    }
    void findFac(ll n, ll *f) {
        if (!millerRabin(n)) {
            f[++ f[0]] = n;
            return;
        }
        ll p = n;
        while (p >= n) p = pollardRho(p, rand() % (n - 1) + 1);
        findFac(p, f), findFac(n / p, f); 
    }
    void getFac(ll n, ll *f) {
        f[0] = 0;
        if (n <= 1) return;
        findFac(n, f);
    }
}

const int N = 2e5 + 5;
ll ans;
map <ll, int> p;
ll n, k, a[N], b[N], c[N];
ll sum, val[N], fac[N], cnt[N];
void dfs(int i, ll x, int id){
	p[x] = id, val[id] = x;
    if (i > b[0]) return;
    for (int j = 0; j < c[i] + 1; j ++) {
    	dfs(i + 1, x, id);
    	x *= b[i], id += fac[i];
    }
}
ll solve(ll x) {
	PollardRho::getFac(x, b);
	sort (b + 1, b + b[0] + 1);
	b[0] = unique(b + 1, b + b[0] + 1) - b - 1;
	for (ll y = x, i = 1; i <= b[0]; i ++) {
		c[i] = 0; 
		while (y % b[i] == 0) c[i] ++, y /= b[i];
	}
	sum = 1;
	for (int i = b[0]; i > 0; i --)
		fac[i] = sum, sum *= c[i] + 1;
	p.clear(), dfs(1, 1, 0);
	for (int i = 0; i < sum; i ++) cnt[i] = 0;
	for (int i = 1; i <= n; i ++) cnt[p[__gcd(x, a[i])]] ++;
	for (int i = 1; i <= b[0]; i ++)
		for (int j = sum - 1; j >= 0; j --)
			if (j / fac[i] % (c[i] + 1) != c[i])
				cnt[j] += cnt[j + fac[i]];
	ll res = 0;
	for (int i = 0; i < sum; i ++) if (cnt[i] >= n - k) res = max(res, val[i]);
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	cin >> n >> k; ans = 1;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int test = 10; test --; ) {
		int x = rand() % n + 1;
		ans = max(ans, solve(a[x]));
	}
	cout << ans << endl;
}