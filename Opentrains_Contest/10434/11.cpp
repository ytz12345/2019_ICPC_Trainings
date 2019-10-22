#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);

int t;

double a, b, c;

int x, y, z;

int main() {
	//ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		scanf("%lf %lf", &a, &b);
		scanf("%d:%d:%d", &x, &y, &z);
		a = pi * 2 * a / 360, b = pi * 2 * b / 360;
		if (a > b) {
			c = asin(tan(b) / tan(a));
			c /= pi * 2; c *= 24;
		}
		else {
			c = 6;
		}
		z += 3600 * c;
		//printf("%.6f %.6f %.6f %d\n", a, b, c, z);
		y += z / 60, z %= 60;
		x += y / 60, y %= 60;
		x %= 24;
		printf("%02d:%02d:%02d\n", x, y, z);
	}
}