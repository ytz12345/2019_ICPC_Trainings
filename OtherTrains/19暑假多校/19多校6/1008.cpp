#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, k, m, c;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> k >> m;
		int cnt = 0;
		ll ans = -1;
		for (c = m; c <= 4000; c ++) {
			n = c ^ k; cnt = 0;
			if (__gcd(c, n) != 1) continue;
			for (ll i = 1; i <= c; i ++) {
				cnt += __gcd(i, n) == 1;
				if (cnt > m) break;
				if (cnt + c - i < m) break;
			}
			if (cnt == m) {
				if (ans == -1 || ans > n)
					ans = n;
			}
		}
		if (ans == -1) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}