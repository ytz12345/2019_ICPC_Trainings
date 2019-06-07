#include <bits/stdc++.h>

using namespace std;

const double s3 = sqrt(3.0);
const double pi = acos(-1.0);

int n;

char s[2019];

// s c t
struct point {
	double x, y;

	point():x(0), y(0){}
	point(double x, double y):x(x), y(y){}

	point operator -(const point &a) const {return point(x - a.x, y - a.y);}
	point operator +(const point &a) const {return point(x + a.x, y + a.y);}
	double operator *(const point &a) const {return x * a.x + y * a.y;}
	void print() {printf("%.6f %.6f\n", x, y);}
};

struct circle {
	point c;
	double r;
	circle():c(0, 0), r(0){}
	circle(double x, double y, double r):c(x, y), r(r){}
};

double sqr(double x) {return x * x;}

double dis(point x, point y) {return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y));}

point calc(const circle &u, const point &p) {
	point v = p - u.c;
	double r = u.r / sqrt(v * v - u.r * u.r);
	return point((v.x * r * r - v.y * r) / (1 + r * r), (v.y * r * r + v.x * r) / (1 + r * r)) + u.c;
}

int main() {
	scanf("%d%s", &n, s + 1);
	int l = 1, r = n;
	while (l <= n && s[l] == 'T') l ++;
	double ans = 0;
	if (l > n) ans = n * 2 + 1;
	else {
		while (r > 0 && s[r] == 'T') r --;
		
		if (s[1] != 'T') {
			if (s[n] != 'T') {
				ans = (n - 1) * 2;
				ans += pi / 2 * ((s[1] == 'C') + (s[n] == 'C')) + 2 * ((s[1] == 'S') + (s[n] == 'S'));
			}
			else {
				ans = n - 0.5 + (s[1] == 'C' ? (pi / 2) : (2)) + r - 1 + 1;
				if (s[r] == 'S') ans += 0.5 + sqrt(sqr(1 - (s3 / 2)) + sqr(n - r - 0.5));
				else {
					point p = calc(circle(0.5, 0.5, 0.5), point(n - r + 0.5, s3 / 2));
					ans += dis(p, point(n - r + 0.5, s3 / 2)) +
						acos((0.25 + 0.25 - sqr(dis(p, point(0.5, 1)))) / (2 * 0.5 * 0.5)) * 0.5;
				}
			}
		}
		else {
			if (s[n] != 'T') {
				ans = n - 0.5 + (s[n] == 'C' ? (pi / 2) : (2)) + n - l + 1;
				if (s[l] == 'S') ans += 0.5 + sqrt(sqr(1 - (s3 / 2)) + sqr(l - 1 - 0.5));
				else {
					point p = calc(circle(0.5, 0.5, 0.5), point(l - 1 + 0.5, s3 / 2));
					ans += dis(p, point(l - 1 + 0.5, s3 / 2)) +
						acos((0.25 + 0.25 - sqr(dis(p, point(0.5, 1)))) / (2 * 0.5 * 0.5)) * 0.5;
				}
			}
			else {
				ans = n + 2 + r - l;
				if (s[r] == 'S') ans += 0.5 + sqrt(sqr(1 - (s3 / 2)) + sqr(n - r - 0.5));
				else {
					point p = calc(circle(0.5, 0.5, 0.5), point(n - r + 0.5, s3 / 2));
					ans += dis(p, point(n - r + 0.5, s3 / 2)) +
						acos((0.25 + 0.25 - sqr(dis(p, point(0.5, 1)))) / (2 * 0.5 * 0.5)) * 0.5;
				}
				if (s[l] == 'S') ans += 0.5 + sqrt(sqr(1 - (s3 / 2)) + sqr(l - 1 - 0.5));
				else {
					point p = calc(circle(0.5, 0.5, 0.5), point(l - 1 + 0.5, s3 / 2));
					ans += dis(p, point(l - 1 + 0.5, s3 / 2)) +
						acos((0.25 + 0.25 - sqr(dis(p, point(0.5, 1)))) / (2 * 0.5 * 0.5)) * 0.5;
				}
			}
		}
	}
	printf("%.8f\n", ans);
	return 0;
}