#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;

const int N = 2e5 + 5;

int n;

double a[N];

double calc(double x) {
	double res = 0;
	for (int i = 0; i < n; i ++)
		res += sqrt((a[i] - x) * (a[i] - x) + 1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n, n *= 2;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	sort (a, a + n);
	for (int i = 0; i < n; i ++)
		a[i] -= i;
	double l = -2e6, r = 2e6, mid1, mid2, res1, res2, ans = 1e18;
	int cnt = 60;
	while (r - l > eps && cnt > 0) {
		//printf("%.6f %.6f\n", l, r);
		mid1 = l + (r - l) / 3;
		mid2 = r - (r - l) / 3;
		res1 = calc(mid1);
		res2 = calc(mid2);
		if (res1 > res2) l = mid1;
		else r = mid2;
		ans = min(ans, min(res1, res2));
		cnt --;
	}
	printf("%.18f\n", ans);
	return 0;
}