#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, m, ans, l, r;

ll s, a[N], sum[N], b[N], c[N], d[N];

bool cmp(ll x, ll y) {return x > y;}

int lb(int x) {return x & (-x);}

void add(int i, ll x) {while (i <= m) c[i] = min(c[i], x), i += lb(i);}

int ask(int i) {ll res = n + 1; while (i > 0) res = min(res, c[i]), i -= lb(i); return res;}

int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], sum[i] = a[i] + sum[i - 1], b[i] = sum[i];
	b[n + 1] = 0;
	sort (b + 1, b + n + 2, cmp);
	m = unique(b + 1, b + n + 2) - b - 1;
	for (int i = 1; i <= n; i ++)
		c[i] = n + 1;
	add(lower_bound(b + 1, b + m + 1, 0, cmp) - b, 0);
	for (int t, k, j, i = 1; i <= n; i ++) {
		j = lower_bound(b + 1, b + m + 1, sum[i], cmp) - b;
		k = upper_bound(b + 1, b + m + 1, sum[i] - s, cmp) - b - 1;
		t = ask(k); add(j, i);
		if (t == n + 1) continue;
		if (i - t > ans) ans = i - t, l = t, r = n - i;
	}
	if (ans == 0) puts("-1");
	else printf("%d\n%d %d\n", ans, l, r);
	return 0;
}