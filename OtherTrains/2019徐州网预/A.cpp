#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

const int N = 80;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (!b) {
		d = a, x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, d, y, x);
	y -= a / b * x;
}

ll crt(ll *m, ll *a, ll n) {
	ll A = a[1], M = m[1], d, x, y, m2;
	for (int i = 2; i <= n; i ++) {
		exgcd(M, m[i], d, x, y);
		if ((a[i] - A) % d) return -1;
		m2 = M / d * m[i];
		x = (a[i] - A) / d * x % m[i];
		A = (A + x * M % m2) % m2;
		if (A < 0) A += m2;
		M = m2;
	}  
	return A;
}

int k;

ll n, a[N], b[N];

ll f[N] = {0, 1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin >> k; long long x;
	for (int i = 1; i <= k; i ++)
		cin >> x, a[i] = x, cin >> x, b[i] = x;
	n = crt(a, b, k);
	if (n == -1) {
		puts("Tankernb!");
		return 0;
	}
	for (int i = 3; i < N; i ++)
		f[i] = f[i - 2] + f[i - 1];//, cout << i << ' ' << f[i] << endl;; 
	for (int i = 0; i < N; i ++) {
		if (f[i] == n) {
			puts("Lbnb!");
			return 0;
		}
	}
	puts("Zgxnb!");
	return 0;
}