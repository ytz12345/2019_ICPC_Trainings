#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, a, b;

void print(ll m, ll l, ll r) {
	printf("%lld = %lld", m, l);
	for (l ++; l <= r; l ++)
		printf(" + %lld",l);
	puts("");
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	int f;
	while (t --) {
		cin >> n, n *= 2; f = 0;
		for (ll j, i = 2; i * i <= n; i ++) {
			if (n % i != 0) continue;
			j = n / i;
			if (!((j - i) & 1)) continue;
			a = (j - i + 1) / 2, b = a + i - 1;
			print(n / 2, a, b); f = 1; break;
		}
		if (!f) puts("IMPOSSIBLE");
	}
	return 0;
}