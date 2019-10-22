#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const double eps = 1e-15;

ll t, n, m, s;

ll a[N], b[N], c[N];

bool judge(double k) {
	double sum = 0;
	for (int i = 1; i <= n; i ++) 
		sum += max(b[i] * k - a[i], 0.0) * c[i];
	return sum <= s;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> s;
		for (int i = 1; i <= n; i ++)
			b[i] = 0;
		for (int x, i = 1; i <= m; i ++)
			cin >> x, b[x] ++;
		for (int i = 1; i <= n; i ++)
			cin >> a[i] >> c[i];
		
		double l = 0, r = 2e9, mid, ans = 0;
		for (int i = 0; i < 80; i ++) {
			mid = (l + r) / 2;
			if (judge(mid)) ans = mid, l = mid + eps;
			else r = mid - eps;
		} 
		printf("%.12f\n", ans);
	} 
}