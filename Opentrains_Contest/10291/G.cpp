#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct clock {
	ll h, m, s;

	ll d;

	bool operator < (const clock &a) const {
		/*if (h != a.h) return h < a.h;
		if (m != a.m) return m < a.m;
		return s < a.s;*/
		return d < a.d;
	}
}a[N];

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	ll tim = 12; tim *= 1000000; tim *= 1000000; 
	__int128 prefs = 0, sum = 0, ans = 1e18; ans *= ans;
	for (int i = 0; i < n; i ++) {
		cin >> a[i].h >> a[i].m >> a[i].s;
		a[i].d = ((a[i].h * 1000000) + a[i].m) * 1000000 + a[i].s; 
		sum += a[i].d;
	}
	sort (a, a + n); 
	for (int i = 0; i < n; i ++) {
		prefs += a[i].d;
		ans = min(ans, a[i].d * (i + 1) - prefs + (a[i].d + tim) * (n - i - 1) - (sum - prefs));
	}
	int z = ans % 1000000;
	ans /= 1000000;
	int y = ans % 1000000;
	ans /= 1000000;
	int x = ans;
	printf("%d %d %d\n", x, y, z);
	return 0;
}