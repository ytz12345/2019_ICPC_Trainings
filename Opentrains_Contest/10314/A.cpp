#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); i ++)

using namespace std;

typedef long long ll;

int n, m;

const double eps = 1e-9;

struct node {
	double x, y;

	/*bool operator < (const noed &a) const {
		if (x * a.y != a.x * y) {

		}
		return 0;
	}*/
}a[2019], b[1000100];

double c[1000100];
 
ll sqr(ll x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int x, y;
	rep(i, 0, n - 1) {
		cin >> x >> y;
		a[i].x = -2 * x, a[i].y = sqr(x) + sqr(y);
	}
	rep(i, 0, n - 1)
		rep(j, i + 1, n - 1) {
			if (a[i].x == a[j].x) continue;
			b[m].x = a[i].x - a[j].x, b[m].y = a[j].y - a[i].y;
			c[m] = b[m].y / b[m].x;
			m ++;
		}
	sort (c, c + m);
	int cnt = m != 0;
	for (int i = 1; i < m; i ++)
		if (c[i] - c[i - 1] > eps)
			cnt ++;
	cout << cnt + 1;
	return 0;
}