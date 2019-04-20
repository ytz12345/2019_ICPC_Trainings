#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef __int128 ll;

typedef pair<ll, ll> pr;

int n;

ll sqr(ll x) {
	return x * x;
}

struct point {
	ll x, y;
	point():x(0), y(0) {}
	point(ll x, ll y):x(x), y(y) {}

	point operator * (const ll &r) const {
		return point(x * r, y * r);
	}

	void getInput() {
		int a, b;
		cin >> a >> b;
		x = a, y = b;
	}
};

ll dis(point a, point b) {
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}

struct triangle{
	point p[3];

	void getInput() {
		for (int i = 0; i < 3; i ++)
			p[i].getInput();
	}

	point circleCenter(ll &r) {
		ll a1 = p[1].x - p[0].x, b1 = p[1].y - p[0].y, c1 = (sqr(a1) + sqr(b1));
		ll a2 = p[2].x - p[0].x, b2 = p[2].y - p[0].y, c2 = (sqr(a2) + sqr(b2));
		ll d = a1 * b2 - a2 * b1; r = d * 2;
		return point(p[0].x * r + (c1 * b2 - c2 * b1), p[0].y * r + (a1 * c2 - a2 * c1));
	}
}a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		a[i].getInput();
	for (int i = 0; i < n; i ++) {
		ll r;
		point c = a[i].circleCenter(r);
		ll d = dis(c, a[i].p[0] * r);
		for (int j = 0; j < n; j ++)
			for (int k = 0; k < 3; k ++)
				if (dis(c, a[j].p[k] * r) < d) {
					puts("NO");
					return 0;
				}
	}
	puts("YES");
	return 0;
}