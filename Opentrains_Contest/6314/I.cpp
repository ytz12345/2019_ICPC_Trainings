#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];

double ans = 1;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		if (a[i] > i) {
			puts("impossible");
			return 0;
		}
		ans = min(ans, 1.0 * a[i] / i);
	}
	printf("%.10f\n", ans);
	return 0;
}