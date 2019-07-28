#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

const int e8 = 1e8;
const int e9 = 1e9;

typedef long long ll;

struct point {
	ll x, y;

	point operator - (const point &p) const {
		return (point){x - p.x, y - p.y};
	}

	bool operator < (const point &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
}p[N];

int t, n;

ll cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

int calc(point a, point b) {
	int res = 0;
	for (int i = 0; i < n; i ++)
		res += cross(b - a, p[i] - a) > 0;
	return res;
}

bool judge(point a, point b) {
	//double k =1.0*(b.y-a.y)/(b.x-a.x);
	//printf("%.6f\n", );
	for (int i = 0; i < n; i ++)
		if (cross(b - a, p[i] - a) == 0)
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	point p1, p2;
	srand(time(NULL));
	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = 0; i < n; i ++)
			cin >> p[i].x >> p[i].y;
		while (1) {
			p1.x = -9e8 - (rand() % e8);
			p2.x = +9e8 + (rand() % e8);
			p1.y = rand() % (e9 * 2) - e9;
			p2.y = rand() % (e9 * 2) - e9;
			ll l = -e9 - min(p1.y, p2.y);
			ll r = +e9 - max(p1.y, p2.y);
			ll mid, cnt;
			while (l <= r) {
				mid = l + r >> 1;
				cnt = calc((point){p1.x, p1.y + mid}, (point){p2.x, p2.y + mid});
				if (cnt * 2 == n) break;
				if (cnt * 2 < n) r = mid - 1;
				else l = mid + 1;
			}
			if (calc((point){p1.x, p1.y + mid}, (point){p2.x, p2.y + mid}) * 2 == n && 
				judge((point){p1.x, p1.y + mid}, (point){p2.x, p2.y + mid})) {
				printf("%lld %lld %lld %lld\n", p1.x, p1.y + mid, p2.x, p2.y + mid);
				//printf("%lld\n", cnt);
				break;
			}
		}
	}
	return 0;
}