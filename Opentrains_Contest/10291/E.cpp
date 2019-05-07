/*
 *最小矩形覆盖,保留六位小数,逆时针输出四个顶点坐标
 */
#include <bits/stdc++.h>

using namespace std;

namespace minRectCover {

	const int N = 1e5 + 5;
	const double eps = 1e-8;

	struct point{
		double x, y;
		point(){}
		point(double x, double y):x(x), y(y){}

		bool operator < (const point &a) const {
			return fabs(y - a.y) < eps ? x < a.x : y < a.y;
		}

		point operator - (const point &a) const {
			return point(x - a.x, y - a.y);
		}

		double operator * (const point &a) const { // X
			return x * a.y - y * a.x;
		}

	}p[N], q[N], rc[8];

	double sqr(double x) {return x * x;}
	double dot(point a, point b) {return a.x * b.x + a.y * b.y;} // .
	double abs(point a) {return sqrt(dot(a, a));}
	int sgn(double x) {return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}

	void convexhull(int n, point *hull, int &top) {//如果要计算周长需要特判 n==2
		for (int i = 1; i < n; i ++)
			if (p[i] < p[0])
				swap(p[i], p[0]);
		sort (p + 1, p + n, [&](point a, point b){
			double t = (a - p[0]) * (b - p[0]);
			if (fabs(t) < eps) return sgn(abs(p[0] - a) - abs(p[0] - b)) < 0;
			return t > 0;
		});

		int cnt = 0;//去重
		for (int i = 1; i < n; i ++)
			if (sgn(p[i].x - p[cnt].x) != 0 || sgn(p[i].y - p[cnt].y) != 0)
				p[++ cnt] = p[i];
		n = cnt + 1;
		
		hull[top = 1] = p[0];
		for (int i = 1; i < n; i ++) {
			while (top > 1 && (hull[top] - hull[top - 1]) * (p[i] - hull[top]) < eps) top --;
			hull[++ top] = p[i];
		}
		hull[0] = hull[top];
	}

	void main() {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf("%lf %lf", &p[i].x, &p[i].y);

		convexhull(n, q, n);

		double ans = 0;
		int l = 1, r = 1, t = 1;
		double L, R, D, H;
		for (int i = 0; i < n; i ++) {
			D = abs(q[i] - q[i + 1]);
			while (sgn((q[i + 1] - q[i]) * (q[t + 1] - q[i]) - (q[i + 1] - q[i]) * (q[t] - q[i])) > -1) t = (t + 1) % n;
			while (sgn((q[i + 1] - q[i]) * (q[r + 1] - q[i]) - (q[i + 1] - q[i]) * (q[r] - q[i])) > -1) r = (r + 1) % b;
		}
	}


} 

int main() {
	minRectCover::main();
	return 0;
}