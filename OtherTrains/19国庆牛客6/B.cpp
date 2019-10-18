#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

long long a, b, c;

ll s[4];

ll fac(ll x) {
	ll y = 1;
	for (int i = 2; i <= x; i ++)
		y *= i;
	return y;
}

void print(ll x, ll y) {
	ll z = __gcd(x, y);
	printf("%lld/%lld ", (long long)(x / z), (long long)(y / z));
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> a >> b >> c) {
		s[0] = s[1] = s[2] = 0;
		for (int i = 0; i < b; i ++)
			for (int j = 0; j < c; j ++)
				s[0] += fac(i + j + a - 1) * fac(b + c - i - j) * fac(b) / fac(i) / fac(b - i) * fac(c) / fac(j) / fac(c - j); 
		s[0] *= a;

		for (int i = 0; i < a; i ++)
			for (int j = 0; j < c; j ++)
				s[1] += fac(i + j + b - 1) * fac(a + c - i - j) * fac(a) / fac(i) / fac(a - i) * fac(c) / fac(j) / fac(c - j);
		s[1] *= b;

		for (int i = 0; i < a; i ++)
			for (int j = 0; j < b; j ++)
				s[2] += fac(i + j + c - 1) * fac(a + b - i - j) * fac(a) / fac(i) / fac(a - i) * fac(b) / fac(j) / fac(b - j);
		s[2] *= c;

		s[3] = s[0] + s[1] + s[2];
		print(s[0], s[3]);
		print(s[1], s[3]);
		print(s[2], s[3]);
		puts("");
	}
}