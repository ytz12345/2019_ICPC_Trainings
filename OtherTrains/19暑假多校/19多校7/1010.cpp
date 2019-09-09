#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

namespace IO {//only for int!!!
	static const int SIZE = 1 << 20;
	inline int get_char() {
	static char *S, *T = S, buf[SIZE];
		if (S == T) {
			T = fread(buf, 1, SIZE, stdin) + (S = buf);
			if (S == T) return -1;
		}
		return *S ++;
	}
	inline void in(int &x) {//for int
		static int ch;
		while (ch = get_char(), ch < 48);x = ch ^ 48;
		while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
	}
	inline void in(ull &x) {//for ull
		static ull ch;
		while (ch = get_char(), ch < 48);x = ch ^ 48;
		while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
	}
};

namespace my_hash {
	const int N = (1 << 23) - 1;
	struct E {
		int v, p;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;

	int vis[N], T, cnt;

	int ins(int v) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return p -> p;
		p = cur ++, p -> v = v, p -> p = ++ cnt, p -> nxt = g[u]; g[u] = p;
		return p -> p;
	}

	void init() {
		T ++; cnt = 0;
		cur = pool;
	}
}

int md;
ull k1, k2;
ull rng() {
    ull k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

using my_hash::ins;

const int N = 2e5 + 5;

int t, n, m, p, a[N], b[N];

int ca[N], cb[N], cc[N], cd[N];

using IO::in;

int main() {
	for (in(t); t --;) {
		my_hash::init();
		in(n), in(m), in(p);
		if (p == 1) {
			for (int i = 0; i < n; i ++) 
				in(a[i]);
			for (int i = 0; i < m; i ++)
				in(b[i]);
		}
		else {
			in(k1), in(k2), in(md);
			for (int i = 0; i < n; ++i)
			    a[i] = rng() % md;

			in(k1), in(k2), in(md);
			for (int i = 0; i < m; ++i)
			    b[i] = rng() % md;
		}
		for (int k, i = 0; i < n; i ++) {
			k = ins(a[i]);
			ca[k] ++;
			cc[k] ++;
		}
		for (int k, i = 0; i < m; i ++) {
			k = ins(b[i]);
			cb[k] ++;
			cc[k] ++;
		}

		int sa = n, sb = m, ct = my_hash::cnt;
		for (int i = 0; i <= ct; i ++)
			if (ca[i] && cb[i]) 
				cd[cc[i]] ++;
		
		for (int j = 1, i = ct; i >= 0; i --) {
			sa += i * cd[i] / 2;
			sb += i * cd[i] / 2;
			if (cd[i] & 1) {
				if (j & 1) sa += i;
				else       sb += i;
				j ^= 1;
			}
		}

		for (int i = 0; i <= ct; i ++)
			ca[i] = cb[i] = cc[i] = cd[i] = 0;

		puts(sa <= sb ? "Cuber QQ" : "Quber CC");
	}
	return 0;
}