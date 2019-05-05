#include <bits/stdc++.h>

using namespace std;
//最小矩形覆盖，保留5位小数
namespace minRectCover {
	typedef double D;
	const int N = 1e5 + 5;

	struct P{
		D x, y;
		P(){}
		P(D x, D y):x(x), y(y){}
	}p[N], pp[N], hull[N], pivot, A, B, C, rect[8];

	int n, i, j, l, r, k;
	D w, h, ans = 1e20, tmp, len;
	bool del[N];

	D sqr(D x) {return x * x;}
	int zero(D x) {return fabs(x) < 1e-4;}
	int sig(D x) {if (fabs(x) < 1e-8) return 0; return x > 0 ? 1 : -1;}
	D cross(P A, P B, P C) {return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);}
	D distsqr(P A, P B) {return sqr(B.x - A.x) + sqr(B.y - A.y);}

	bool cmp(P a, P b) {
		D t = cross(pivot, a, b);
		return sig(t) == 1 || sig(t) == 0 && sig(distsqr(pivot, a) - distsqr(pivot, b)) == -1;
	}

	void convexhull(int n, P stck[], int &m) {
		int i, k, top;
		for (i = 0; i < n; i ++) pp[i] = p[i];
		for (k = 0, i = 1; i < n; i ++) if (pp[i].y < pp[k].y || (pp[i].y == pp[k].y && pp[i].x < pp[k].x)) k = i;
		pivot = pp[k]; pp[k] = pp[0], pp[0] = pivot;
		sort (pp + 1, pp + n, cmp);
		stck[0] = pp[0], stck[1] = pp[1];
		for (top = 1, i = 2; i < n; i ++) {
			while (top && sig(cross(pp[i], stck[top], stck[top - 1])) >= 0) -- top;
			stck[++ top] = pp[i];
		}
		m = top + 1;
	}

	D area(P A, P B, P C) {return fabs(cross(A, B, C));}
	P vertical(P A, P B) {return P(A.x - B.y + A.y, A.y + B.x - A.x);}

	void main() {
		scanf("%d", &n);
		for (i = 0; i < n; i ++) scanf("%lf %lf", &p[i].x, &p[i].y);
		convexhull(n, hull, n);
		for (i = 1; i < n; i ++) if (zero(hull[i].x - hull[i - 1].x) && zero(hull[i].y - hull[i - 1].y)) del[i] = 1;
		for (k = i = 0; i < n; i ++) if (!del[i]) hull[k ++] = hull[i];
		for (hull[n = k] = hull[i = 0]; i < n; i ++) {
			A = hull[i], B = hull[i + 1], C = vertical(A, B);
			while (sig(area(A, B, hull[j]) - area(A, B, hull[j + 1])) < 1) j = (j + 1) % n;
			while (sig(cross(A, C, hull[l]) - cross(A, C, hull[l + 1])) < 1) l = (l + 1) % n;
			while (sig(cross(A, C, hull[r]) - cross(A, C, hull[r + 1])) > -1) r = (r + 1) % n;
			len = sqrt(distsqr(A, B));
			h = area(A, B, hull[j]) / len;
			w = (cross(A, C, hull[l]) - cross(A, C, hull[r])) / len;
			if (sig(h * w - ans) == -1) {
				ans = h * w;
				tmp = area(A, B, hull[l]) / len / len;
				rect[0] = P(hull[l].x + tmp * (A.x - C.x), hull[l].y + tmp * (A.y - C.y));
				tmp = h / len;
				rect[3] = P(rect[0].x + tmp * (C.x - A.x), rect[0].y + tmp * (C.y - A.y));
				tmp = w / len;
				rect[1] = P(rect[0].x + tmp * (B.x - A.x), rect[0].y + tmp * (B.y - A.y));
				rect[2] = P(rect[3].x + tmp * (B.x - A.x), rect[3].y + tmp * (B.y - A.y));
			}
		}
		for (i = 0; i < 4; i ++) rect[i + 4] = rect[i];
		for (j = 0, i = 1; i < 4; i ++)
			if (sig(rect[i].y - rect[j].y) == -1 ||
				sig(rect[i].y - rect[j].y) == 0 && sig(rect[i].x - rect[j].x) == -1) j = i;
		//printf("%.5f\n", ans);
		for (i = 0; i < 4; i ++)
			printf("%.5f %.5f\n", rect[j + i].x, rect[j + i].y);
	}
}

int main() {
	minRectCover::main();
	return 0;
}