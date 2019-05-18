#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i) 
typedef long long ll;
ll m[10], a[10];
void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (!b)  {
		d = a; x = 1; y = 0;
	}
	else {
		exgcd(b, a % b, d, y, x); y -= (a / b) * x;
	}
}
ll inv(ll a, ll p) {
	ll d, x, y;
	exgcd(a, p, d, x, y); return (x % p + p) % p;
}
ll CRT(ll *a, ll *m, int n) {
	ll M = 1, ret = 0;
	rep(i, 1, n) M = M / __gcd(M, m[i]) * m[i]; 
	rep(i, 1, n) {
		ll w = M / m[i];
		ret = (ret + a[i] * w % M * inv(w, m[i]) % M) % M;
	}
	return ret;
}
ll qpow(ll a, ll b, ll p) {
	ll c = 1;
	while (b) {
		if (b & 1) c = c * a % p;
		a = a * a % p; b >>= 1; 
	}
	return c;
}
ll nextp(ll x) {
	if (x == 5) return 4;
	if (x == 4) return 2;
	return 1;
}
ll dfs(int a, int b, int p) {
	if (a == b) {
		if (a < p) {
			return a;
		}
		return a % p + p;
	}
	if (p == 1) {
		return 1;
	}
	return qpow(a, dfs(a + 1, b, nextp(p)), p);
}
int main() {
	ll x, y;
	cin >> x >> y;
	m[1] = 2; m[2] = 5;
	a[1] = (x % 2 == 1)? 1: 0;
	a[2] = dfs(x, y, 5);
	ll ans = CRT(a, m, 2);
	cout << ans << endl;
}