#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10010;

ll n, m, a[N];

ll p, q, g;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		sort (a + 1, a + n + 1, [&](ll x, ll y) {
			return x > y;
		});
		ll sum = 0, ss = 0; int pos = n;
		for (int i = 1; i < n; i ++) {
			sum += a[i];
			if (sum - a[i + 1] * i >= m) {
				pos = i;
				break;
			}
		}
		if (pos == n) sum += a[n];
		//printf("? %d %lld\n", pos, sum);
		for (int i = pos + 1; i <= n; i ++)
			ss += a[i] * a[i];
		q = pos * m * m;
		p = (sum - m) * (sum - m) + ss * pos;
		g = __gcd(p, q);
		p /= g, q /= g;
		if (q == 1) printf("%lld\n", p);
		else printf("%lld/%lld\n", p, q);
	}
	return 0;
}