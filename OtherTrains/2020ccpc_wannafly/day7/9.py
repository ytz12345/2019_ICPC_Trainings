from decimal import *
import math
getcontext().prec = 20

n = int(input())
a = list(map(Decimal, input().split()))
a = sorted(a)
ang = Decimal(360) / n
b = [ang * i for i in range(n)]

def calc(x):
    return sum(abs(a[i] - b[i]) for i in range(n))

L, R = -ang / 2, ang / 2
for i in range(50):
    mid1, mid2 = (L + L + R) / 3, (L + R + R) / 3
    if calc(mid1) < calc(mid2):R = mid2
    else:L = mid1
ans = calc((L + R) / 2) / 180 * Decimal(math.pi)
print(ans)

'''
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
'''