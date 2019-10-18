#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

struct Base {
	const static int B = 64;
	ll a[B], s; vector<ll> c;
	Base(){clear();}
	void clear() {
		c.clear(); s = 0;
		for (int i = 0; i < B; i ++) a[i] = 0;
	}
	void ins(ll x) {
		for (int i = B - 1; ~i; i --)
			if (x >> i & 1)
				if (a[i]) x ^= a[i];
				else {a[i] = x; break;}
	}
	void init() {
		for (int i = 0; i < B; i ++)
			if (a[i])
				for (int j = i - 1; ~j; j --)
					if (a[j] && (a[i] >> j & 1))
						a[i] ^= a[j];
		for (int i = 0; i < B; i ++)
			if (a[i])
				c.push_back(a[i]);
		s = (1ll << (c.size())) - 1;
	}
	Base intersection(const Base &b) {
		Base na(*this), tmp(*this), res;
	    ll cur, d;
	    for (int i = 0; i < B; i ++) if (b.a[i]) {
    		cur = 0, d = b.a[i];
    		for (int j = i; ~j; j --) if (d >> j & 1) {
				if (tmp.a[j]) {
					d ^= tmp.a[j], cur ^= na.a[j];
					if (d) continue;
					res.a[i] = cur; 
				}
				else tmp.a[j] = d, na.a[j] = cur;
				break;
			}
    	}
	    return res;
	}
}a, b, c;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		a.clear(), b.clear(); ll x;
		for (int i = 0; i < n; i ++) cin >> x, a.ins(x);
		for (int i = 0; i < n; i ++) cin >> x, b.ins(x);
		a.init(), b.init(), c = a.intersection(b), c.init();
		printf("%lld\n", 1ll << int(c.c.size()));
	}
}