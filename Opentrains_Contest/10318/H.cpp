#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i) 
typedef long long ll;
const double eps = 1e-8;
double L[100], R[100], c[200];
int p, q, n;
double f(double x) {
	double ret = 1;
	if (R[p] >= x) ret = ret / (R[p] - L[p]) * (R[p] - max(x, L[p])); else return 0;
	if (L[q] <= x && R[q] <= x) ret = 1. / (R[q] - L[q]); else return 0; 
	rep(i, 1, n)
		if (i != p && i != q) {
			if (L[i] <= x) ret = ret / (R[i] - L[i]) * (min(R[i], x) - L[i]); else return 0;
		}
	return ret * x;
}
double simpson(double l, double r) {
	return (f(l) + f(r) + 4 * f(l + r / 2.)) * (r - l) / 6.;
}
double rsimpson(double l, double r) {
	double mid = (l + r) / 2.;
	double t0 = simpson(l, r), t1 = simpson(l, mid), t2 = simpson(mid, r);
	if (fabs(t0 - t1 - t2) < eps) return t1 + t2;
	else return rsimpson(l, mid) + rsimpson(mid, r);
}
double solve(double l, double r) {
	if (R[p] < r) return 0;
	if (R[q] < l) return 0;
	if (L[q] > r) return 0;
	int cnt = 0;
	rep(i, 1, n) if (L[i] > r) cnt ++;
	if (cnt >= 2) return 0;
	return simpson(l, r);
}
int main() {
	int tot = 0;
	cin >> n;
	rep(i, 1, n) {
		cin >> L[i] >> R[i];
		c[++ tot] = L[i]; c[++ tot] = R[i];
	}
	sort(c + 1, c + 1 + tot);
	tot = unique(c + 1, c + 1 + tot) - c - 1;
	//rep(i, 1, tot) cout << c[i] << ' '; cout << endl;
	double ans = 0;
	rep(i, 1, n) rep(j, 1, n) {
		if (i == j) continue;
		p = i;
		q = j;
		rep(k, 1, tot - 1) {
			// cout << i << ' ' << j << ' ' << c[k] << ' ' << c[k + 1] << ' ' << solve(c[k], c[k + 1]) << endl;
			ans += solve(c[k], c[k + 1]);
		}
	}
	printf("%.9f\n", ans);
}
/*
3 
1 0
1 0
-1 0
*/