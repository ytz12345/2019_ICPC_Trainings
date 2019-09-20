#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//typedef __int128 lll;

typedef pair<double, double> pr;

ll solve(ll n, ll k) {
	ll res = -1;
	for (ll i = 0; i <= n + 1; i ++)
		if (i * (i - 1) / 2 <= k && k <= i * (i - 1) / 2 + (n + 1 - i) * i) {
			if (i == 0 || i == n + 1) res = max(res, n * (n - 1) / 2);
			else {
				res = max(res, max(i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2, 
					(i - 1) * (i - 2) / 2 + (n + 1 - i) * (n - i) / 2));
			}
		}
	return res;
}

int main() {
	ll n, k;
	cin >> n >> k;
	cout << solve(n, k);
	return 0;
}