#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int p = 998244353;
const int X = 473844410;
const int B = 35000;

inline ll qpow(ll x, ll k) {
	ll res = 1;
	for (x %= p; k > 0; k >>= 1, x = x * x % p)
		if (k & 1) res = res * x % p;
	return (res % p + p) % p;
}

ll l, r;

ll Lbig[B], Lsma[B];
ll Rbig[B], Rsma[B];

inline ll qpwl(ll k) {
	return (Lbig[k / B] * Lsma[k % B] % p + p) % p;
}

inline ll qpwr(ll k) {
	return (Rbig[k / B] * Rsma[k % B] % p + p) % p;
}

inline ll calc(ll n) {
	static ll k = (qpow(X, p - 2) % p + p) % p;
	return ((qpwl(n % (p - 1)) - qpwr(n % (p - 1))) % p * k % p + p) % p;
}

int main() {
	ios::sync_with_stdio(false);
	l = (qpow(2, p - 2) * (3 + X) % p + p) % p;
	r = (qpow(2, p - 2) * (3 - X) % p + p) % p;

	Lbig[0] = Lsma[0] = Rbig[0] = Rsma[0] = 1;
	Lbig[1] = qpow(l, B), Rbig[1] = qpow(r, B);
	Lsma[1] = l, Rsma[1] = r;
	for (int i = 2; i < B; i ++) { 
		Lbig[i] = Lbig[i - 1] * Lbig[1] % p;
		Rbig[i] = Rbig[i - 1] * Rbig[1] % p;
		Lsma[i] = Lsma[i - 1] * l % p;
		Rsma[i] = Rsma[i - 1] * r % p;
	}

	ll q, n, m, ans;
	cin >> q >> n;
	ans = m = calc(n);
	for (q --; q --; ) {
		n = n ^ (m * m);
		m = calc(n);
		ans ^= m;
	}
	cout << ans << endl;
	return 0;
}