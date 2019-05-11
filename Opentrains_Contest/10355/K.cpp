#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

namespace my_hash {
	const int N = (1 << 20) - 1;

	struct E {
		int v;
		int c;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;

	int vis[N + 1], T;

	void ins(int v){
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] =NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) {p -> c ++; return;}
		p = cur ++; p -> v = v; p->c= 1;p -> nxt = g[u]; g[u] =p; 
	}

	int ask(int v) {
		int u = v & N;
		if (vis[u] < T) return 0;
		for (p = g[u]; p; p = p->nxt) if (p ->v == v) return p -> c;
			return 0;
	}

	void init() {T ++; cur = pool;}
}

char str[N];

int t, p;

ll cnt, l, r;

int pw[N];

ll calc(ll x, ll k, ll md) {
	ll res = 1;
	for (x %= md; k > 0; k >>= 1, x = x * x % md)
		if (k & 1) res = res * x % md;
	return res; 
}

int main() {
	ios::sync_with_stdio(false);
	cin >> str >> t >> p; 
	int n = strlen(str);
	for (int i = 1; i <= n; i ++)
		pw[i] = (calc(10, 1ll * (p - 2) * i, p) % p + p) % p;
	for (int x; t --; ) {
		my_hash::init();
		my_hash::ins(0);
		cin >> x; l = r = cnt = 0;
		for (int y, i = 1, tmp, last = 0; i <= n; i ++) {
			last = (10ll * last + str[i - 1] - '0') % p;
			tmp = 1ll * (last - x + p) % p * pw[i] % p;
			y = my_hash::ask(tmp); cnt += y;
			if (r == 0 && y != 0) {
				r = i;
				if (tmp == 0) l = 1;
				else {
					int temp = 0;
					for (int j = 1; ; j ++) {
						temp = (10ll * temp + str[j - 1] - '0') % p;
						if (1ll * temp * pw[j] % p == tmp) {
							l = j + 1;
							break;
						}
					}
				}
			}
			my_hash::ins(1ll * last * pw[i] % p);
		}
		printf("%lld %lld %lld\n", cnt, l, r);
	}
	//printf("%d\n", clock());
	return 0;
}