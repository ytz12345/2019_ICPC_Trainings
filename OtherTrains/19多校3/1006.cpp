#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, m;

const int times = 20;

int number = 0;

ll myRandom(ll n) {
	return ((double)rand() / RAND_MAX * n + 0.5);
}
 
ll qmul(ll a, ll b, ll mod) {
	ll ans = 0;
	while (b) {
		if(b & 1) {
			b --;
			ans = (ans + a) % mod;
		}
		b /= 2;
		a = (a + a) % mod;
 
	}
	return ans;
}
 
ll qpow(ll a, ll b, ll mod) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = qmul(ans, a, mod);
		}
		b /= 2;
		a = qmul(a, a, mod);
	}
	return ans;
}
 
bool witness(ll a, ll n) {
	ll tem = n - 1;
	int j = 0;
	while (tem % 2 == 0) {
		tem /= 2;
		j ++;
	}
	ll x = qpow(a, tem, n); 
	if (x == 1 || x == n - 1) return true;
	while (j --) {
		x = qmul(x, x, n);
		if(x == n - 1) return true;
	}
	return false;
}
 
bool miller_rabin(ll n) {
	if(n == 2)
		return true;
	if(n < 2 || n % 2 == 0)
		return false;				
 
	for(int i = 1; i <= times; i++) {
		ll a = myRandom(n - 2) + 1; 
		if(!witness(a, n))						
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n;
		ll ans = 1;
		for (m = n - 1; !miller_rabin(m); m --);
		for (ll i = n - 2; i > m; i --) ans = qmul(ans, qpow(i, n - 2, n), n);
		printf("%lld\n", ans);
	}
	return 0;
} 