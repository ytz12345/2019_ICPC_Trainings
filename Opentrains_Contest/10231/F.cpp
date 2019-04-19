#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, l, m;

long double fac[N];

int main() {
	freopen("intset.in","r",stdin);
	freopen("intset.out","w",stdout);
	cin >> n >> l >> m;
	for (int i = 1; i <= n; ++ i) fac[i] = fac[i - 1] + log(i);
	long double sum = 0;
	auto comb = [&](int n, int m) -> long double {
		double r = fac[n] - fac[m] - fac[n - m];
		return r;
	};
	for (int i = min(l, m); i; -- i) {
		sum += exp(comb(n, i) + comb(n - i, l - i) + comb(n - l, m - i) - comb(n, l) - comb(n, m));		
		if (sum >= 0.5) {
			cout << i;
			return 0;
		}
	}
	cout << 1;
}