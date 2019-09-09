#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, m, k, ans;

ll calc(ll x) {
	ll y = m / (x + 1) + 1;
	y = max(y, 1ll);
	y = min(y, n - k + 1);
	return (m / y + 1) * (k + y - 1);
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> k;
		ans = (m + 1) * k;
		if (m != 0) {
			ll l = m / (n - k + 1), r = m, mid1, mid2, res1, res2;
			while (r - l > 10) {
				mid1 = l + (r - l) / 3;
				mid2 = r - (r - l) / 3;
				res1 = calc(mid1);
				res2 = calc(mid2);
				if (res1 > res2) l = mid1;
				else r = mid2;
			}
			for (int i = l; i <= r; i ++) {
				cout << i << ' ' << calc(i) << endl;
				ans = min(ans, calc(i));
			}	
		}
		cout << ans << '\n';
	}

	return 0;
}