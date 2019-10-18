#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int c[2019], p[2019];

ll calc(int *a, int n, int *b, int m) {
	ll res = 0;
	for (int i = 0; i <= 1005; i ++)
		p[i] = lower_bound(b + 1, b + m + 1, c[i]) - b;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= 1005; j ++) {
			if (p[j - 1] > m) break;
			while (p[j] <= m && b[p[j]] < a[i] + c[j]) p[j] ++;
			if (j != 0) res += 1ll * (j - 1) * (p[j] - p[j - 1]);
		}
	}
	//cout << ' ' << n << ' ' << m << ' ' << res << endl;
	return res;
}

int n, m, a[N], b[N];

int main() {
	for (int i = 1; i <= 1005; i ++) c[i] = i * i;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= m; i ++) cin >> b[i];
		sort (a + 1, a + n + 1);
		sort (b + 1, b + m + 1);
		cout << calc(a, n, b, m) + calc(b, m, a, n) << '\n';
	}
}