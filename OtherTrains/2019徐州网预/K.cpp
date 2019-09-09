#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;

const int N = 1010;

int n, m;

point a[N], b[N * N], c[N * N];

int d[N * N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			b[m] = c[m] = point(a[i].first + a[j].first, a[i].second + a[j].second), m ++;
	sort (b, b + m);
	m = unique(b, b + m) - b;
	for (int k = 0, i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
			d[lower_bound(b, b + m, c[k ++]) - b] += j == i ? 1 : 2;
	int ans = 0;
	for (int i = 0; i < m; i ++)
		ans = max(ans, d[i]);
	cout << n - ans << '\n';
	return 0;
}