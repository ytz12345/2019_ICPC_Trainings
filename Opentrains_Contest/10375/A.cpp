#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const int inf = 1e9 + 7;

int ans = inf;

int n;

int lb(int x) {return x & (-x);}

struct node {
	ll a, b, c;

	void in() {
		cin >> a >> b;
		c = a + b;
	}

}a[N], b[N];

ll c[N];

int p[N], d[N], cc;

ll ask(int i) {ll res = 0; while (i > 0) res += c[i], cc += d[i], i -= lb(i); return res;}

void add(int i, ll x) {while (i <= n) c[i] += x, d[i] ++, i += lb(i);} 

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		a[i].in();
	sort (a + 1, a + n + 1, [&](node x, node y) {
		return x.c < y.c;
	});
	/*for (int i = 1; i <= n; i ++) {
		cout << i << ' ' << a[i].a << ' ' << a[i].b << endl;
	}*/
	for (int i = 1; i <= n; i ++)
		b[i].a = a[i].a, b[i].b = i;
	sort (b + 1, b + n + 1, [&](node x, node y) {
		return x.a > y.a;
	});
	for (int i = 1; i <= n; i ++) 
		p[b[i].b] = i;
	for (int i = 1; i <= n; i ++) {
		//cout << i << ' ' << p[i] << endl;
		add(p[i], a[i].a);
		int l = 1, r = n, mid, ansi = inf;
		while (l <= r) {
			mid = l + r >> 1; cc = 0;
			if (ask(mid) >= a[i].c) ansi = min(ansi, cc), r = mid - 1;
			else l = mid + 1;
		}
		ans = min(ans, ansi);
		//cout << ' ' << ansi << endl;
	}
	cout << (ans == inf ? -1 : ans) << endl;
	return 0;
}