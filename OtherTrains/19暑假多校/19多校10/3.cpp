#include <bits/stdc++.h>

using namespace std;

int t, n;

double p[10010], ans;

double p0, p1, q0, q1;

int main() {
	for (scanf("%d", &t); t --; ) {
		ans = 0; scanf("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf("%lf", &p[i]);
		sort (p, p + n, [&](double x, double y){
			return x > y;
		});
		ans = p[0];
		p0 = 1 - p[0], p1 = p[0];
		for (int i = 1; i < n; i ++) {
			q0 = p0 * (1 - p[i]);
			q1 = p1 * (1 - p[i]) + p0 * p[i];
			p0 = q0, p1 = q1;
			ans = max(ans, p1);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}