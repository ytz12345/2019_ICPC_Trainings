#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

int t, n;

multiset <ll> s;

struct node {
	ll x, y;
}a[N];

ll ans;

int main() {
	for (scanf("%d", &t); t --; ) {
		scanf("%d", &n); ans = 2e18;
		for (int i = 1; i <= n; i ++) 
			scanf("%lld %lld", &a[i].x, &a[i].y);
		sort (a + 1, a + n + 1, [&](node x, node y) {
			return x.x > y.x;
		});
		s.clear();	
		for (int i = 1; i <= n; i ++)
			s.insert(a[i].y);
		ll rmax = -1;
		for (int i = 1; i <= n; i ++) {
			s.erase(s.find(a[i].y));
			if (rmax >= a[i].x) {
				ans = min(ans, rmax - a[i].x);
			}
			else {
				auto it = s.lower_bound(a[i].x);
				if (it != s.end()) ans = min(ans, (*it) - a[i].x);
				if (it != s.begin()) {
					it --;
					ans = min(ans, a[i].x - max(rmax, *it));
				}
				if (rmax != -1) ans = min(ans, a[i].x - rmax);
			}
			rmax = max(rmax, a[i].y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}	