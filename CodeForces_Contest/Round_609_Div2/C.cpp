#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int sgn(double x) {return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}

struct point {
    double x, y;

    point():x(0), y(0) {}
    point(double x, double y):x(x), y(y) {}

    bool operator < (const point &a) const {return sgn(y - a.y) == 0 ? x < a.x : y < a.y;}
    point operator + (const point &a) const {return point(x + a.x, y + a.y);}
    point operator - (const point &a) const {return point(x - a.x, y - a.y);}
    point operator / (const double &a) const {return point(x / a, y / a);}
    point operator * (const double &a) const {return point(x * a, y * a);}

    void get() {
        cin >> x >> y;
    }

    void print() {
        cout << x << ' ' << y << endl;
    }
};

double sqr(double x) {return x * x;}
double dot(point a, point b) {return a.x * b.x + a.y * b.y;}
double dot(point a) {return dot(a, a);}
double abs(point a) {return sqrt(dot(a));}
point vertical(point a) {return point(a.y, -a.x);}
point vec(point a){return a / abs(a);}

struct circle {
    point c;
    double r;

    circle():c(), r(0) {}
    circle(point c, double r):c(c), r(r) {}
    circle(double x, double y, double r):c(x, y), r(r) {}

    void get() {
        c.get();
        cin >> r;
    }

    bool isPointInCircle(point p) {
        return sgn(dot(c - p) - sqr(r)) <= 0;
    }
};

void circleInter(const circle &u, const circle &v, vector<point> &vp) {
    point d = u.c - v.c; double r1 = u.r, r2 = v.r; vp.clear();
    if (sgn(r1 + r2 - abs(d)) >= 0 && sgn(abs(r1 - r2) - abs(d)) <= 0 && sgn(abs(d)) != 0) {
        point mid = d / abs(d) * (dot(d) + r2 * r2 - r1 * r1) / (2 * r2 * abs(d)) * r2 + v.c;
        point p = vec(vertical(d)) * sqrt(sqr(r1) - dot(u.c - mid)); 
        vp.push_back(mid + p);
        if (sgn(r1 + r2 - abs(d)) == 0 || sgn(abs(r1 - r2) - abs(d)) == 0) return;
        vp.push_back(mid - p);
    }
}

int n;
circle c[66];

bool judge(double R) {
    static circle cc[66];
    static vector<point> vp;
    
    for (int i = 0; i < n; i ++) {
        if (R < c[i].r) return 0;
        cc[i] = circle(c[i].c, R - c[i].r);
    }

    for (int i = 0; i < n; i ++)
        for (int j = i + 1; j < n; j ++) {
            circleInter(cc[i], cc[j], vp);
            for (point &p : vp) {
                int flag = 1;
                for (int k = 0; k < n; k ++)
                    if (!cc[k].isPointInCircle(p)) {
                        flag = 0;
                        break;
                    }
                if (flag) return 1;
            }
        }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i ++) 
        c[i].get();
    sort (c, c + n, [&](circle x, circle y) {return x.r > y.r;});
    int m = n, n = 1;
    for (int i = 1; i < m; i ++) {
        int flag = 1;
        for (int j = 0; j < n; j ++) {
            if (sgn(abs(c[i].r - c[j].r) - abs(c[i].c - c[j].c)) > 0) {
                flag = 0;
                break;
            }
        }
        if (flag) c[n ++] = c[i]; 
    }
    double l = 0, r = 1e5, mid, ans;
    for (int t = 50; t --; ) {
        mid = (l + r) / 2;
        if (judge(mid)) ans = mid, r = mid - eps;
        else l = mid + eps;
    }

    if (n == 1) ans = c[0].r;
    printf("%.6f\n", ans);
    return 0;
}