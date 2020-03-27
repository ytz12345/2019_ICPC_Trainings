#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
const int N = 1e5 + 7;
const double PI = acos(-1.);
double a[N], b[N]; int n;
double calc(double x) {
	double ret = 0;
	rep(i, 0, n - 1) ret += fabs(a[i] - b[i]); return ret;
}
int main() {
	scanf("%d", &n);
	rep(i, 0, n - 1) scanf("%lf", &a[i]);
	sort(a, a + n);
	double ang = 360. / n;
	rep(i, 0, n - 1) b[i] = ang * i;
	double L = -ang / 2, R = ang / 2;
	rep(t, 1, 50) {
		double mid1 = (L + L + R) / 3.;
		double mid2 = (L + R + R) / 3.;
		if (calc(mid1) < calc(mid2)) R = mid2;
		else L = mid1;
	}
	double ans = calc((L + R) / 2.) / 180. * PI;
	printf("%.11f\n", ans);
}