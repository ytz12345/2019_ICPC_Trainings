#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100;

ll n, m, a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		m ^= a[i];
	}
	if (m > 0) {
		puts("0");
	}
	else {
		printf("%lld\n", (1ll << n) - 2);
	}
	return 0;
}