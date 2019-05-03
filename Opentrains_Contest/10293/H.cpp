#include <bits/stdc++.h>
//#include <unordered_set>

using namespace std;

typedef long long ll;

const ll lim = 2e8;

ll p, a, l, r;

ll len;

ll calc(ll x, ll k) {
	ll res = 1;
	for (; k > 0; k >>= 1, x = x * x % p)
		if (k & 1) res = res * x % p;
	return res % p;
}

namespace ha {
	const int N = (1 << 19) - 1;

	struct E {
		int v;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;

	int vis[N + 1], T;

	void ins(int v) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return;
		p = cur ++; p -> v = v; p -> nxt = g[u]; g[u] = p;
	}

	int ask(int v) {
		int u = v & N;
		if (vis[u] < T) return 0;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return 1;
		return 0;
	}

	void init() {T ++, cur = pool;}
}

void work1() {
	ha::init();
	vector <int> x;
	vector <int> ans; ans.clear();
	int y = 1;
	for (int i = 0, j = 1 << 16; i < j; i ++) {
		x.push_back(y);
		y = 1ll * y * a % p;
	}
	int p16 = y;
	for (int i : x)
		ha::ins(i);
	vector <int> z(int(x.size()));
	vector <int> zz(int(x.size()));
	for (int i = 0; i < (int)x.size(); i ++) {
		zz[i] = calc(p16, i) % p;
		z[i] = calc(zz[i], p - 2);
	}
	for (ll i = l; i <= r; i ++) {
		//printf("%lld\n", i);
		int f = 0;
		for (int t = 0; t < (int)x.size(); t ++) {
			if (i == x[t] || i == zz[t]) {
				f = 1;
				break;
			}
			if (ha::ask(i * z[t] % p) == 1) {
				f = 1;
				break;
			}
		}
		if (f) {
			ans.push_back(i);
			continue;
		}
	}
	sort (ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i ++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
}

void work2() {
	vector <int> ans; ans.clear();
	int x = 1;
	for (int i = 0; i < len; i ++) {
		if (l <= x && x <= r)
			ans.push_back(x);
	//	if (x == 112296) printf("%d\n", i);
		x = 1ll * x * a % p;
	}
	sort (ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i ++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
}

void work3() {
	vector <int> ans; ans.clear();
	for (int i = max(1ll, l); i <= min(p - 1, r); i ++) {
		ans.push_back(i);
	}
	sort (ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i ++) {
		if (i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
}

int main() {
	/*p = 1e9 + 7;
	l = 1, r = 501;
	a = 233333;
	work1();
	printf("%d\n", clock());*/
	cin >> p >> a >> l >> r;
	len = p - 1; l = max(l, 1ll);
	for (ll i = 1; i * i <= p - 1; i ++)
		if ((p - 1) % i == 0) {
			if (calc(a, i) == 1) len = min(len, i);
			if (calc(a, (p - 1) / i) == 1) len = min(len, (p - 1) / i);
		}
	//work1(); return 0;
	if (len == p - 1) work3();
	else if (len <= 1.5e8) work2();
	else work1();
	return 0;
}