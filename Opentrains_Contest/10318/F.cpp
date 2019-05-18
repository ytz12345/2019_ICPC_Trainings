#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void no() {
	puts("-1");
	exit(0);
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (!b)  {
		d = a; x = 1; y = 0;
	}
	else {
		exgcd(b, a % b, d, y, x); y -= (a / b) * x;
	}
}

int main() {
	ios::sync_with_stdio(false);
	ll p, q;
	// __gcd(0 ,0) = 0
	cin >> p >> q;
	
	int d = __gcd(p, q);
	if (d != 1) no();

	// gcd = 1
	if (p > q) swap(p, q);
	if ((p & 1) && (q & 1)) no();

	// p < q

	ll ans = 0; 
	if (p == 0) ans = 1; 
	else {
		ans = 1e18;
		if (p & 1) swap(p, q);
		// 2 1
		ll x, y, z, tx, ty;
		exgcd(p, q, z, x, y);
		if (x & 1) x -= q, y += p;
		for (int i = 0; i < 10000; i ++) {
			tx = x - q * i * 2;
			ty = y + p * i * 2;
			ans = min(ans, max(abs(tx), p) + max(abs(ty), q));

			tx = x + q * i * 2;
			ty = y - p * i * 2;
			ans = min(ans, max(abs(tx), p) + max(abs(ty), q));
		}
	}
	printf("%lld\n", ans);

	return 0;
}