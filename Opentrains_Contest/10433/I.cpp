#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Mod = 1ll << 31;

const int N = 1e5 + 5;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = exgcd(b, a % b, x, y), t = x;
	return x = y, y = t - a / b * y, d;
}

ll calc(ll a, ll b, ll n) {
	ll x, y, d = exgcd(a, n, x, y);
	x = (x % n + n) % n;
	return (x * (b / d) % (n / d) % n + n) % n;
}

ll n, a[N], b[N], c[N];

map <ll, int> p;

set <ll> s;

ll qpow(ll x, ll k) {
	ll res = 1;
	for (x %= Mod; k > 0; k >>= 1, x = x * x % Mod)
		if (k & 1) res = res * x % Mod;
	return res;
}

int pr[] = {3, 5, 7, 11, 13, 17, 19};

int main() {
	srand(time(NULL));
	ll x = pr[rand() % 7], ni = calc(x, 1, Mod), y;
	cin >> n; 
	for (int i = 1; i <= n; i ++) {
		do {
			c[i] = rand() % Mod;
			a[i] = qpow(x, c[i]);
		}while (s.find(a[i]) != s.end());
		s.insert(a[i]);
	}

	for (int i = 1; i <= n; i ++)
		printf("%lld%c", a[i], i == n ? '\n' : ' ');
	fflush(stdout);

	for (int i = 1; i <= n / 2; i ++)
		cin >> b[i];

	for (int test = 20; test --; ) {
		int k = rand() % n + 1;
		for (int i = 1; i <= n / 2; i ++)
			p[b[i] * qpow(ni, c[k]) % Mod] ++;
	}

	ll cnt = 0;
	for (auto i : p) 
		if (i.first % 2 == 1 && i.second > cnt)
			 x = i.first, cnt = i.second;

	printf("%lld\n", x);
	fflush(stdout);

	return 0;
}