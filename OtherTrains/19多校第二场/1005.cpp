#include <bits/stdc++.h>

using namespace std;

int n;

long long ans;

const int p = 998244353;

long long sqr(long long x) {
	return x * x;
}

long long calc(long long x, int k = p - 2) {
	long long res = 1;
	for (x %= p; k > 0; k >>= 1, x = x * x % p)
		if (k & 1) res = res * x % p;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			ans += sqr(i);
			ans -= i;
			ans %= p;
		}
		ans = ans % p * 332748118 % p;
		cout << (ans * calc(n) % p + p) % p << '\n'; 
	}
	return 0;
}