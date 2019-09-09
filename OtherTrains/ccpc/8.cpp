#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct node {
	ll x, y;
}a[N];

int t, n;

ll k, b[N];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++)
			cin >> a[i].x, a[i].y = a[i].x % k;
		sort (a + 1, a + n + 1, [&](node x, node y){
			return x.y > y.y; 
		});
		ll sum = 0;
		for (int i = n; i > 0; i --)
			sum += a[i].x / k;
		sum = max(n - sum - 1, 0ll);
		ll ans = k;
		for (int i = 1; i <= n; i ++) {
			ans += a[i].x;
			if (sum > 0) sum --, ans += k - a[i].y;
		}
		printf("%lld\n", ans);
	}
}