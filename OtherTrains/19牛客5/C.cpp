/*xi = x(i-1) * a + b
 *x(i-1) = (xi + (-b)) * (a ^ (-1))
 *xi -b
 *0 0
 *
 *a^(-1) 0 
 *a^(-1) 1
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace my_hash {
	const int N = (1 << 24) - 1;
	struct E {
		int v, h;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;
	int vis[N + 1], T;
	void ins(int v, int h) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return;
		p = cur ++; p -> v = v; p -> h = h; p -> nxt = g[u]; g[u] = p;
	}
	int ask(int v) {
		int u = v & N;
		if (vis[u] < T) return -1;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return p -> h;
		return -1;
	}
	void init() {T ++, cur = pool;}//应对多组数据使用
}

using my_hash::ins;
using my_hash::ask;
using my_hash::init;

const int K = 2;

ll t, n, x0, a, b, bf, p, q;

struct matrix {
	ll c[K][K];

	void clear() {
		memset (c, 0, sizeof c);
	}

	matrix operator * (const matrix& a) const {
		matrix res; res.clear();
		for (int k = 0; k < K; k ++)
			for (int i = 0; i < K; i ++)
				for (int j = 0; j < K; j ++) {
					res.c[i][j] += c[i][k] * a.c[k][j] % p;
					while (res.c[i][j] >= p) res.c[i][j] -= p;
					while (res.c[i][j] < 0)  res.c[i][j] += p;
				}
		return res;
	}

	matrix operator ^ (int k) const {
		matrix res, x = *this; res.clear();
		for (int i = 0; i < K; i ++) res.c[i][i] = 1;
		for (; k > 0; k >>= 1, x = x * x)
			if (k & 1) res = res * x;
		return res;
	}

	void print() {
		for (int i = 0; i < K; i ++)
			for (int j = 0; j < K; j ++)
				printf("%lld%c", c[i][j], j + 1 == K ? '\n' : ' ');
		puts("");
	}	
};

ll qpow(ll x, ll k, ll p) {
	ll res = 1;
	for (x %= p; k > 0; x = x * x % p, k >>= 1)
		if (k & 1) res = res * x % p;
	return (res % p + p) % p;
}

ll bsgs(){
	init(); cin >> q; x0 %= p;
	ll m = sqrt(p * q * 8) + 1, s = x0, up = min(p, n) / m + 2;
    for (int i = 0; i < m; i ++) {
        ins(s, i);
        s = (s * a + b) % p;
    }
    matrix x, yy, tmp;
    yy.c[0][0] = yy.c[1][0] = qpow(a, p - 2, p);
    yy.c[0][1] = 0, yy.c[1][1] = 1;
    tmp.c[0][1] = (p - b) % p;
    tmp.c[1][0] = tmp.c[1][1] = 0;
    yy = yy ^ m;
    ll ans, temp;
    while (q --) {
    	cin >> tmp.c[0][0]; x = yy; ans = -1; tmp.c[0][0] %= p;
    	if ((temp = ask(tmp.c[0][0])) != -1) {
    		cout << temp << '\n';
    		continue;
    	}
    	for (int i = 1; i <= up; i ++) {
    		if((temp = ask((tmp * x).c[0][0])) != -1) {
	        	ans = i * m + temp;
	        	break;
	        }
	        x = x * yy;
    	}
    	if (ans >= n) ans = -1;
    	cout << ans << '\n';
    }
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> x0 >> a >> b >> p;
		bsgs();
	}
	//cout << clock() << endl;
	return 0;
}