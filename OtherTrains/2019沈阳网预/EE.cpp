#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 6;

ll t, n, p;

ll ans[N];

ll fac[N], inv[N];

ll qpow(ll x, ll k, ll m) {
	ll res = 1;
	for (x %= m; k > 0; k >>= 1, x = x * x % m)
		if (k & 1) res = res * x % m;
	return (res % m + m) % m;
}

ll C(ll n, ll m) {
	return fac[n] * inv[m] % p * inv[n - m] % p;
}

int main() {
	for (cin >> t; t --; ) {
		cin >> n >> p; p = 5;
		fac[0] = inv[0] = 1; ans[0] = 1;
		for (ll i = 1; i <= n; i ++) fac[i] = fac[i - 1] * i % p;
		for (ll i = 1; i <= n; i ++) inv[i] = qpow(fac[i], p - 2, p);
		for (ll i = 1; i <= n; i ++) {
			ans[i] = 0;
			for (ll j = 0; j < i; j ++)
				ans[i] = (ans[i] + 1ll * C(i - 1, j) * ans[j] % p) % p;
		}
		cout << (ans[n] % p + p) % p << '\n';
	}
	return 0;
}