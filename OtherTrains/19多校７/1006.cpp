#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n, m, k, ans;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> k;
		ans = 5e18;
		if (n - k + 1 <= 1000) {
			for (int i = 1; i <= n - k + 1; i ++) {
				ans = min(ans, ((m / i) + 1) * (i + k - 1));
			}
		}
		else {
			ll tmp = sqrt(m * (k  - 1));
			ll l = max(tmp - 5000, 1ll), r = min(tmp + 5000, n - k + 1);
			for (int i = l; i <= r; i ++) {
				ans = min(ans, ((m / i) + 1) * (i + k - 1));
			}
		}
		cout << ans << '\n';
	}
}