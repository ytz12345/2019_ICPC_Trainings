 #include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

typedef long long ll;

const ll inf = -1e18;

struct line {
	ll l, r, y, v;
}a[N], b[N];

struct node {
	ll lazy, maxs, active;
}tr[N << 2];

ll tot, c[N];

ll ans;

ll n, l, r;


ll calc(int x, int y) {
	ll res = 0;
	for (int i = 0; i < n; i ++)
		if (l <= max(abs(x - a[i].l), abs(y - a[i].r)) && max(abs(x - a[i].l), abs(y - a[i].r)) <= r)
			res += a[i].v;
	//if (res == 15) cout << x << ' ' << y << endl;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i ++) {
		cin >> a[i].l >> a[i].r >> a[i].v;
		b[i * 4 + 0] = (line){a[i].l - r, a[i].l + r, a[i].r - r, a[i].v};
		b[i * 4 + 1] = (line){a[i].l - r, a[i].l + r, a[i].r + r + 1, -a[i].v};
		b[i * 4 + 2] = (line){a[i].l - l + 1, a[i].l + l - 1, a[i].r - l + 1, -a[i].v};
		b[i * 4 + 3] = (line){a[i].l - l + 1, a[i].l + l - 1, a[i].r + l, a[i].v};
	}
	for (int i = -20; i <= 20 ; i++)
		for (int j = -20; j <= 20; j ++)
			ans = max(ans, calc(i, j));
	cout << ans << endl;
	return 0;
}