#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

const int lim = 000;

typedef long long ll;

int T;

ll k, L;

double n;

inline ll calc(int i) {
	return (ll)(ceil(n * i) + 0.5) * (ll)(ceil(1.0 * L / i) + 0.5);
} 

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T --; ) {
		cin >> n >> L >> k;
		n = log2(n);
		if (k <= lim) {
			ll tmp, ans = 1e18, pos = 1;
			for (ll i = 1; i <= k; i ++) {
				tmp = calc(i);
				if (tmp < ans) ans = tmp, pos = i;
			}
			printf("%lld %lld\n", ans, pos);
		}
		else {
			ll tmp, ans = calc(k), pos = k;
			ll x;
			for (ll i = 1; i * i <= L && i <= k; i ++) {
				x = i;
				tmp = calc(i);
				if (tmp < ans) ans = tmp, pos = i;
				else if (tmp == ans) pos = min(pos, i);
			}
			for (ll i = 1; ; i ++) {
				ll l = max(L / (i + 1) + (L % (i + 1) == 0 ? 0 : 1), x), r = L / i + (L % i == 0 ? 0 : 1); 
				if (l > k) continue;
				if (l >= r) break;
				tmp = calc(l);
				if (tmp < ans) ans = tmp, pos = l;
			}
			printf("%lld %lld\n", ans, pos);
		}
	}
	return 0;
}