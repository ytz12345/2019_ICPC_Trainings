#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2019;

int t, n, m;

struct point {
	int x, y, k, t;
}p[N];

int a[N], b[N];

int k1, k2;

ll ans;

ll calc(int lx, int ly, int rx, int ry) {//(lx, rx] (ly, ry]
	ll res = 0; int c1, c2, c3, c4, x, y;
	for (int i = 0; i < 60; i ++) {
		c1 = lx / 60 + (lx % 60 >= i);
		c2 = rx / 60 + (rx % 60 >= i);
		if (c1 == c2) continue;
		for (int j = 0; j < 60; j ++) {
			c3 = ly / 60 + (ly % 60 >= j);
			c4 = ry / 60 + (ry % 60 >= j);
			if (c3 == c4) continue;
			int flag = 1;
			x = rx / 60 * 60 + i;
			y = ry / 60 * 60 + j;
			while (x > rx) x -= 60;
			while (x <= lx) x += 60;
			while (y > ry) y -= 60;
			while (y <= ly) y += 60;
			//if (rx == 3 && ry == 2) printf("%d %d %d %d %d %d %d %d\n",c1,c2,c3,c4,i,j,x,y);
			for (int k = 0; k < n; k ++) {
				if ((abs(p[k].x - x) + abs(p[k].y - y)) % p[k].k != p[k].t) {
					flag = 0;
					break;
				}
			}
			if (flag) res += 1ll * (c2 - c1) * (c4 - c3);
		}
	}
	//printf("%d %d %d %d %lld\n", lx, ly, rx, ry, res);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m; ans = 0;
		for (int i = 0; i < n; i ++) {
			cin >> p[i].x >> p[i].y >> p[i].k >> p[i].t;
			a[i] = p[i].x, b[i] = p[i].y;
		}	
		a[n] = b[n] = -1;
		a[n + 1] = b[n + 1] = m;
		sort (a, a + n + 1 + 1);
		sort (b, b + n + 1 + 1);
		k1 = unique(a, a + n + 1 + 1) - a;
		k2 = unique(b, b + n + 1 + 1) - b;
		for (int i = 1; i < k1; i ++)
			for (int j = 1; j < k2; j ++) 
				ans += calc(a[i - 1], b[j - 1], a[i], b[j]);
		cout << ans << '\n';
	}
	return 0;
}