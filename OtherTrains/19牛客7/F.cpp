#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> piir;

const int N = 2e5 + 5;

const int T = 2e5;

int t, n, m;

struct node {
	ll x, y, z;
}a[N], b[N];

set <int> s;

piir c[N];

template<class T>void clear(T &container) {
	container.clear();
	T().swap(container);
}

piir operator + (const piir a, const piir b) {
	return piir(a.first + b.first, a.second + b.second);
}

int lb(int x) {
	return x & (-x);
}

void add(int i, piir x) {
	while (i < T) c[i] = c[i] + x, i += lb(i);
}

piir ask(int i) {
	piir res = piir(0, 0);
	while (i > 0) res = res + c[i], i -= lb(i);
	return res;
}

void ins(int x) {
	s.insert(x);
	auto it = s.find(x);
	auto pre = it, suc = it;
	pre --, suc ++;
	if (suc == s.end()) add(x - (*pre), piir(1, x - (*pre)));
	else {
		add((*suc) - (*pre), piir(-1, -((*suc) - (*pre))));
		add(x - (*pre), piir(1, x - (*pre)));
		add((*suc) - x, piir(1, (*suc) - x));
	}
}

void del(int x) {
	auto it = s.find(x);
	auto pre = it, suc = it;
	pre --, suc ++;
	if (suc == s.end()) add(x - (*pre), piir(-1, -(x - (*pre))));
	else {
		add((*suc) - (*pre), piir(1, (*suc) - (*pre)));
		add(x - (*pre), piir(-1, -(x - (*pre))));
		add((*suc) - x, piir(-1, -((*suc) - x)));
	}
	s.erase(it);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	for (int tt = 1; tt <= t; tt ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) 
			cin >> a[i].x >> a[i].y >> a[i].z;
		cin >> m;
		for (int x, y, z, i = 0; i < m; i ++) {
			cin >> x >> y >> z;
			b[i << 1] = (node){y - 1, x, 1};
			b[i << 1 | 1] = (node){z, x, -1};
		}
		sort (b, b + (m <<= 1), [&](node a, node b){
			return a.x < b.x;
		});
		clear(s); s.insert(0); piir sum, tmp; ll ans = 0;
		for (int i = 0, j = 0; i < n; i ++) {
			while (j < m && b[j].x <= i) {
				if (b[j].z == 1) ins(b[j].y);
				else del(b[j].y);
				j ++;
			}
			if (s.size() == 1);
			else if (a[i].y == 0) ans += a[i].x;
			else {
				auto ed = s.end(); ed --;
				auto bg = s.begin(); bg ++;
				ans += min(a[i].z, a[i].x + (a[i].y * (*bg)));
				add(*bg, piir(-1, -(*bg)));
				sum = ask(T);
				tmp = ask(a[i].z / a[i].y);
				ans += tmp.second * a[i].y + a[i].z * (sum.first - tmp.first);
				add(*bg, piir(1, *bg));
			}
		}
		printf("Case #%d: %lld\n", tt, ans);
		for (int i = 1; i <= T; i ++)
			c[i] = piir(0, 0);
	}
	return 0;
}