#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll t, n;

bool vis[1010];

bool f[1010][1010];

struct {ll x, y, z;}a[1010];

ll tmp, ansx[1010], ansy[1010], co[1010];

ll sqr(ll x) {
	return x * x;
}

queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> n;
		memset (f, 0, sizeof f);
		for (int i = 0; i < n; i ++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			ansx[i] = ansy[i] = co[i] = -1;
			vis[i] = 0;
		}
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				if (sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y) == sqr(a[i].z + a[j].z))
					f[i][j] = 1;
		ansx[0] = 1, ansy[0] = 1;
		q.push(0); vis[0] = 1, co[0] = 1;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			ansx[now] = a[0].z, ansy[now] = a[now].z;
			for (int i = 0; i < n; i ++)
				if (!vis[i] && f[now][i]) 
					q.push(i), vis[i] = 1, co[i] = co[now] ^ 1;
		}
		for (int i = 0; i < n; i ++) {
			if (co[i] == -1) puts("not moving");
			else if (co[i] == 1) {
				tmp = __gcd(ansx[i], ansy[i]);
				ansx[i] /= tmp, ansy[i] /= tmp;
				if (ansy[i] == 1) printf("%lld clockwise\n", ansx[i]);
				else printf("%lld/%lld clockwise\n", ansx[i], ansy[i]);
			}
			else {
				tmp = __gcd(ansx[i], ansy[i]);
				ansx[i] /= tmp, ansy[i] /= tmp;
				if (ansy[i] == 1) printf("%lld counterclockwise\n", ansx[i]);
				else printf("%lld/%lld counterclockwise\n", ansx[i], ansy[i]);
			}
		}
	}
	return 0;
}