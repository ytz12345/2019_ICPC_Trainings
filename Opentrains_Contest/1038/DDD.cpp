#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//typedef __int128 lll;

typedef pair<double, double> pr;

ll solve(ll n, ll k) {
	ll x = -1;
	for (ll i = 0; i <= n + 1; i ++)
		if (i * (i - 1) / 2 <= k && k <= i * (i - 1) / 2 + (n + 1 - i) * i)
			x = i;
	if (x == -1) return -1;
	return x * (x - 1) / 2 + (n - 1 - x) * (n - x) / 2;
}

ll Rand() {
	return rand() * rand();
}

int main() {
	srand(time(NULL));
	//for (int i = 0; i < 10; i ++) cout << rand() << endl; return 0;
	
	ll N = 1e9, M = 1e18;
	cout << Rand() % N + 1 << ' '<< Rand() % M + 1 << endl;
	return 0;
}