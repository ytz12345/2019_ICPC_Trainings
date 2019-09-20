#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

ll n, m;

ll a[N], sum;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		sum = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			sum += a[i];
		}
		sort (a + 1, a + n + 1);
		if (sum % n == 0) {
			ll d = 0, b = sum / n;
			for (int i = 1; i <= n; i ++)
				d += max(0ll, a[i] - b);
			if (m >= d) puts("0");
			else {
				ll minv = a[1], maxv = a[n], ds = m;
				for (int i = 2; i <= n; i ++) {
					if (ds >= (a[i] - a[i - 1]) * (i - 1)) {
						ds -= (a[i] - a[i - 1]) * (i - 1);
					}
					else {
						minv = a[i - 1] + ds / (i - 1);
						break;
					}
				}
				ds = m;
				for (int i = n - 1; i >= 1; i --) {
					if (ds >= (a[i + 1] - a[i]) * (n - i)) {
						ds -= (a[i + 1] - a[i]) * (n - i);
					}
					else {
						maxv = a[i + 1] - ds / (n - i);
						break;
					}
				}
				printf("%lld\n", maxv - minv);
			}
		}
		else {
			ll d = 0, b = sum / n, c = sum % n;
			for (int i = 1; i <= n; i ++)
				d += max(0ll, a[i] - (i + c <= n ? b : (b + 1)));
			if (m >= d) puts("1");
			else {
				ll minv = a[1], maxv = a[n], ds = m;
				for (int i = 2; i <= n; i ++) {
					if (ds >= (a[i] - a[i - 1]) * (i - 1)) {
						ds -= (a[i] - a[i - 1]) * (i - 1);
					}
					else {
						minv = a[i - 1] + ds / (i - 1);
						break;
					}
				}
				ds = m;
				for (int i = n - 1; i >= 1; i --) {
					if (ds >= (a[i + 1] - a[i]) * (n - i)) {
						ds -= (a[i + 1] - a[i]) * (n - i);
					}
					else {
						maxv = a[i + 1] - ds / (n - i);
						break;
					}
				}
				printf("%lld\n", maxv - minv);
			}
		}
	}
}