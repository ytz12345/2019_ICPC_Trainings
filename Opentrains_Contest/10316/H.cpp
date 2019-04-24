#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> pr;

int n, m, k, p[10010], b[2000010];

pr a[1010];

int ans1, ans2;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> p[i];
	for (int i = 1; i <= m; i ++)
		cin >> a[i].fi >> a[i].se;
	sort (a + 1, a + m + 1);
	k = 1;
	for (int i = 2; i <= m; i ++) {
		if (a[i].fi > a[k].se + 1)
			a[++ k] = a[i];
		else 
			a[k].se = max(a[k].se, a[i].se);
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= k; j ++) {
			b[p[i] - a[j].fi + 1 + 1000001] --;
			b[p[i] - a[j].se + 1000001] ++;
		}
	}
	int c = 0;
	for (int i = 0; i < 2000010; i ++) {
		c += b[i];
		if (c > ans2) ans2 = c, ans1 = abs(i - 1000001);
		else if (c == ans2) ans1 = min(ans1, abs(i - 1000001));
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}