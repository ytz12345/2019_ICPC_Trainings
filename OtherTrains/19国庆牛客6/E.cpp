#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

ll n, m;

ll f[5];

piir a[N], b[N];

ll c[N];

int lb(int x) {return (x&(-x));}
void add(int i, int x) {while (i <= m) c[i] += x, i += lb(i);}
int ask(int i) {int res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

ll calc() {
	ll res = 0, tot = 0;
	for (int i = 1; i <= m; i ++) c[i] = 0;
	for (int i = 1; i <= n; i ++)
		if (a[i].first < a[i].second)
			add(a[i].first, 1), b[tot ++] = a[i];
	for (int i = 0; i < tot; i ++)
		res += tot - ask(b[i].second);
	return res;
}

ll ca1c() {
	ll res = 0, tot = 0;
	for (int i = 1; i <= m; i ++) c[i] = 0;
	for (int i = 1; i <= n; i ++)
		if (a[i].first < a[i].second)
			add(a[i].first, 1), b[tot ++] = a[i];
	for (int i = 1; i <= n; i ++)
		res += tot - ask(min(a[i].first, a[i].second));
	for (int i = 1; i <= m; i ++) c[i] = 0;
	for (int i = 0; i < tot; i ++)
			add(b[i].second, 1);
	for (int i = 1; i <= n; i ++)
		res += ask(max(a[i].first, a[i].second) - 1);
	return res;
}

ll c4lc() {
	ll res = 0, tot = 0;
	for (int i = 1; i <= m; i ++) c[i] = 0;
	for (int i = 1; i <= n; i ++) {
		swap(a[i].first, a[i].second);
		if (a[i].first <= a[i].second)
			add(a[i].first, 1), b[tot ++] = a[i];
	}
	for (int i = 0; i < tot; i ++)
		res += tot - ask(b[i].second - 1);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i ++)
			cin >> a[i].first >> a[i].second;
		f[4] = calc();
		f[3] = ca1c();
		f[1] = c4lc();
		f[3] -= f[4] * 2;
		f[2] = n * n - f[3] - f[4] - f[1];
		for (int i = 1; i <= 4; i ++)
			printf("%lld%c", f[i], i == 4 ? '\n' : ' ');
	}
}