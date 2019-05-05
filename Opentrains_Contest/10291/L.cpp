#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 6;

ll a[N], c[N];

ll n, m;

int main() {
	cin >> n; m = -1;
	for (int i = 0; i < n; i ++) {
		cin >> a[i]; c[a[i]] ++;
		m = max(m, a[i]);
	}
	if (!m) cout << "0\n";
	else {
		ll ans = m * c[m];
		for (int i = 0; i < n; i ++) {
			if (a[i] == 0) continue;
			if (i != 0) {
				c[a[i]] --;
				c[a[i] - 1] ++;
				c[a[i - 1]] --;
				c[a[i - 1] + 1] ++;
				if (c[m + 1] != 0) ans = min(ans, (m + 1) * (c[m + 1]));
				else if (c[m] != 0) ans = min(ans, m * c[m]);
				else ans = min(ans, (m - 1) * (c[m - 1]));
				c[a[i]] ++;
				c[a[i] - 1] --;
				c[a[i - 1]] ++;
				c[a[i - 1] + 1] --;
			}
			if (i + 1 != n) {
				c[a[i]] --;
				c[a[i] - 1] ++;
				c[a[i + 1]] --;
				c[a[i + 1] + 1] ++;
 				if (c[m + 1] != 0) ans = min(ans, (m + 1) * (c[m + 1]));
				else if (c[m] != 0) ans = min(ans, m * c[m]);
				else ans = min(ans, (m - 1) * (c[m - 1]));
				c[a[i]] ++;
				c[a[i] - 1] --;
				c[a[i + 1]] ++;
				c[a[i + 1] + 1] --;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 