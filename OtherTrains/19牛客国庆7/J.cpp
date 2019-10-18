#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x) {return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}//判断数字符号
struct point {
    double x, y;
    point():x(0), y(0) {}
    point(double x, double y):x(x), y(y) {}
    bool operator < (const point &a) const {return sgn(y - a.y) == 0 ? x < a.x : y < a.y;}
    point operator + (const point &a) const {return point(x + a.x, y + a.y);}
    point operator - (const point &a) const {return point(x - a.x, y - a.y);}
    point operator * (const double &a) const {return point(x * a, y * a);}
    point operator / (const double &a) const {return point(x / a, y / a);}
};
struct line:public vector<point> {
	line(){}
	line(point a, point b) {push_back(a), push_back(b);}
};
double sqr(double x) {return x * x;}
double abs(point a) {return sqrt(sqr(a.x) + sqr(a.y));}//向量长度
point vec(point a){return a / abs(a);}//向量a对应的单位向量
point vec(const line &a) {return a[1] - a[0];}//直线化为向量
double det(point a, point b) {return a.x * b.y - a.y * b.x;}//叉积
double dot(point a, point b) {return a.x * b.x + a.y * b.y;}//点积
point rotate(point u, double a) {
    return point(u.x * cos(a) - u.y * sin(a), u.y * cos(a) + u.x * sin(a));
}//坐标逆时针旋转a度
point convertPoint(point u, point v, point c) {
	return point(det(c, v) / det(u, v), det(c, u) / det(v, u));  
}//uv不平行时，存在a*u+b*v=c,返回(a,b)
int cross(point s, point a, point b) {
	point u = a - s, v = b - s; double res = det(u, v);
	if (res > 0) return 1;//在线段左方
	if (res < 0) return -1;//在线段右方
	if (dot(u, v) <= 0) return 0;//在线段上
	if (abs(u) > abs(v)) return 2;//在a到b延长线上
	return -2;//在b到a的延长线上
}//判断点s与线段ab的位置关系
bool isInterSS(const line &u, const line &v) {
	if (sgn(det(vec(u), vec(v))) == 0) return 0;//平行
	if (sgn(cross(u[0], u[1], v[0]) * cross(u[0], u[1], v[1]) <= 0) && 
		sgn(cross(v[0], v[1], u[0]) * cross(v[0], v[1], u[1]) <= 0))
		return 1;//相交
	return 0;
}//判断线段交
point interLL(const line &u, const line &v) {
	double a = det(vec(u), vec(v));
	double b = det(vec(u), u[1] - v[0]);
	if (sgn(a) == 0) return v[0];
	return v[0] + vec(v) * b / a;
}
struct convexHull {
	vector<point> p; int n;
	convexHull():n(0) {p.clear();}
	convexHull(vector<point> &q):n(0) {
		int m = q.size(), cnt = 0; sort (q.begin(), q.end());
		for (int i = 1; i < m; i ++)
			if (sgn(q[i].x - q[cnt].x) != 0 || sgn(q[i].y - q[cnt].y) != 0)
				q[++ cnt] = q[i];
		q.resize(m = cnt + 1), p.resize(m + 1);
		for (int i = 1; i < m; i ++) if (q[i] < q[0]) swap(q[i], q[0]);
		sort (q.begin() + 1, q.begin() + m, [&](point a, point b){
			double t = det((a - q[0]), (b - q[0]));
			if (sgn(t) == 0) return sgn(abs(q[0] - a) - abs(q[0] - b)) < 0;
			return t > 0;
		});
		p[n = 1] = q[0];
		for (int i = 1; i < m; i ++) {
			while (n > 1 && det((p[n] - p[n - 1]), (q[i] - p[n])) < eps) n --;
			p[++ n] = q[i];
		}
		p[0] = p[n], p.resize(n + 1);
	}//得到n个点的凸包,且p[0]=p[n]
	double getArea() const{
		double res = 0;
		for (int i = 2; i < n; i ++)
			res += abs(det(p[i] - p[0], p[i - 1] - p[0]));
		return res / 2;
	}
};
bool isInConvexHull(point p, const convexHull &h) {
	double s = h.getArea();
	for (int i = 0; i < h.n; i ++)
		s -= abs(det(p - h.p[i + 1], p - h.p[i])) / 2;
	return sgn(s) == 0;
}
vector<point> pts, tri, rec; 
convexHull *p, *t, *r;
int main() {
	double x[5], y[5];
	while (cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[4] >> y[4]) {
        pts.clear(), tri.clear(), rec.clear();

        tri.push_back(point(x[1], y[1]));
        tri.push_back(point(x[1], y[2]));
        tri.push_back(point(x[2], y[1]));

        rec.push_back(point(x[3], y[3]));
        rec.push_back(point(x[3], y[4]));
        rec.push_back(point(x[4], y[3]));
        rec.push_back(point(x[4], y[4]));

        t = new convexHull(tri);
        r = new convexHull(rec);

        for (int i = 0; i < t -> n; i ++)
        	if (isInConvexHull(t -> p[i], *r))
        		pts.push_back(t -> p[i]);

        for (int i = 0; i < r -> n; i ++)
        	if (isInConvexHull(r -> p[i], *t))
        		pts.push_back(r -> p[i]);
         
        for (int i = 0; i < t -> n; i ++)
        	for (int j = 0; j < r -> n; j ++)
 				if (isInterSS(line(t -> p[i], t -> p[i + 1]), line(r -> p[j], r -> p[j + 1])))
                    pts.push_back(interLL(line(t -> p[i], t -> p[i + 1]), line(r -> p[j], r -> p[j + 1])));
 		
 		p = new convexHull(pts);
        printf("%.10f\n", p -> getArea());
    }  
}