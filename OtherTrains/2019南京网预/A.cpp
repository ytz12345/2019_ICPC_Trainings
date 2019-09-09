#include <bits/stdc++.h>

using namespace std;

#define lb(x) (x&(-x))

typedef long long ll;

const int N = 5e5 + 5;
const int NN = 1e6 + 5;

int t, n, m, p;

struct point {
	int x, y, id;
	ll v;
}a[N];

ll ans[N];

ll c[NN];

ll ask(int i) {
	ll res = 0;
	while (i > 0) res += c[i], i -= lb(i);
	return res;
}

void add(int i, ll x) {
	while (i < NN) c[i] += x, i += lb(i);
}

ll calc(int x, int y, int n) {
	ll level = min(min(n + 1 - x, x), min(n + 1 - y, y));
	ll pre = 4ll * (level - 1) * (n - (level - 1));
	if (x + level == n + 1 && y != level) 
		return pre + (n - level + 1 + 1) - y;
	if (y == level && x != level)
		return pre + (n + 1 - level * 2) * 1 + (n - level + 1 + 1) - x;
	if (x == level && y != n - level + 1)
		return pre + (n + 1 - level * 2) * 2 + y - (level - 1);

	return pre + (n + 1 - level * 2) * 3 + x - (level - 1);
}

ll cal(ll x) {
	ll res = 0;
	while (x > 0) res += x % 10, x /= 10;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> p;
		for (int i = 1; i <= m; i ++) {
			cin >> a[i].x >> a[i].y; 
			a[i].v = cal(calc(a[i].x, a[i].y, n));
			///printf("%d %d %lld\n", a[i].x, a[i].y, a[i].v);
			a[i].id = -1;
		}
		for (int x[2], y[2], i = 0; i < p; i ++) {
			cin >> x[0] >> y[0] >> x[1] >> y[1];
			a[m + i * 4 + 1] = (point){x[0] - 1, y[0] - 1, i, 1};
			a[m + i * 4 + 2] = (point){x[0] - 1, y[1], i, -1};
			a[m + i * 4 + 3] = (point){x[1], y[0] - 1, i, -1};
			a[m + i * 4 + 4] = (point){x[1], y[1], i, 1};
			ans[i] = 0;
		}
		sort (a + 1, a + m + p * 4 + 1, [&](point a, point b) {
			if (a.x != b.x) return a.x < b.x;
			if (a.y != b.y) return a.y < b.y;
			return a.id < b.id;
		});
		for (int i = 0; i < NN; i ++) c[i] = 0;
		for (int i = 1, up = m + p * 4; i <= up; i ++) {
			if (a[i].id == -1) add(a[i].y, a[i].v);
			else ans[a[i].id] += a[i].v * ask(a[i].y);
		}
		for (int i = 0; i < p; i ++)
			printf("%lld\n", ans[i]);
	}	
	return 0;
}