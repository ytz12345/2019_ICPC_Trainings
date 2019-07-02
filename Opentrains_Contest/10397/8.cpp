#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

const int M = N * 25;

int n, m, k;

int a[N], d[N], add[N], de[N];

int b[N], lb[N], root[N];

int L[M], R[M], siz[M];

ll s[M], sumadd[N];
 
int cnt;

#define l(o) L[o]
#define r(o) R[o]
#define s(o) s[o]
#define sz(o) siz[o]

int build(int l, int r) {
	int x = ++ cnt;
	s(x) = sz(x) = 0;
	if (l == r) {
		l(x) = r(x) = 0;
	}
	else {
		int mid = l + r >> 1;
		l(x) = build(l, mid);
		r(x) = build(mid + 1, r);
	}
	return x;
}

int change(int o, int l, int r, int p) {
	int x = ++ cnt, mid = l + r >> 1;
	s(x) = s(o) + b[p], sz(x) = sz(o) + 1;
	l(x) = l(o), r(x) = r(o);
	if (l == r) return x;
	if (p <= mid) l(x) = change(l(o), l, mid, p);
	else r(x) = change(r(o), mid + 1, r, p);
	return x;
}

ll askl(int o1, int o2, int l, int r, int x) {
	//cout << "L " << l << ' ' << r << ' ' << sz(o2) - sz(o1) << ' ' << x << endl;
	if (l == r) return 1ll * b[r] * x; 
	if (sz(o2) - sz(o1) == x) return s(o2) - s(o1);
	int mid = l + r >> 1, ls = sz(l(o2)) - sz(l(o1));
	//cout << ' ' << ls << endl;
	if (ls >= x) return askl(l(o1), l(o2), l, mid, x);
	return s(l(o2)) - s(l(o1)) + askl(r(o1), r(o2), mid + 1, r, x - ls);
}

ll askr(int o1, int o2, int l, int r, int x) {
	//cout << "R " << l << ' ' << r << ' ' << sz(o2) - sz(o1) << ' ' << x << endl; 
	if (l == r) return 1ll * b[r] * x; 
	if (sz(o2) - sz(o1) == x)  return s(o2) - s(o1);
	int mid = l + r >> 1, rs = sz(r(o2)) - sz(r(o1));
	//cout << rs << endl;
	if (rs >= x) return askr(r(o1), r(o2), mid + 1, r, x);
	return s(r(o2)) - s(r(o1)) + askr(l(o1), l(o2), l, mid, x - rs);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; 
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> d[i];
	for (int i = 1; i <= n; i ++) {
		add[i] = a[i] + d[i];
		b[i] = de[i] = a[i] - d[i];
		sumadd[i] = add[i] + sumadd[i - 1];
	}
	sort (b + 1, b + n + 1);
	k = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i ++) 
		lb[i] = lower_bound(b + 1, b + k + 1, de[i]) - b;
	root[0] = build(1, k);
	for (int i = 1; i <= n; i ++) 
		root[i] = change(root[i - 1], 1, k, lb[i]);
	cin >> m;
	for (int s, t, len, i = 0; i < m; i ++) {
		cin >> s >> t, len = (t - s + 1) / 3;
		printf("%.2f\n", (sumadd[t] - sumadd[s - 1] 
			- askl(root[s - 1], root[t], 1, k, len) 
			+ askr(root[s - 1], root[t], 1, k, len)) / 2.0);
	}
	return 0;
}