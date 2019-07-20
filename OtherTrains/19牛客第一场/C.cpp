#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

const int Mod = 1e9 + 7;

const int N = 10010;

ll n, m, a[N], b[N], c[N];

ll p, q, g;

ll tp, tq;

ll sqr(ll x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	int tmp;
	while (cin >> tmp) {
		n = tmp, cin >> tmp, m = tmp;
		//
		p = q = 0;
		memset (c, 0, sizeof c);
		p = -m;
		for (int i = 1; i <= n; i ++)
			cin >> tmp, a[i] = tmp, p += a[i];
		tp = -p, tq = n * m;//tp/tq个单位法向量
		/*p *= p, q = n * m * m;
		g = __gcd(p, q);
		p /= g, q /= g;*/
		ll sum = 0, cnt = 0;
		//cout << (long long)tp << endl;
		for (int i = 1; i <= n; i ++)
			if ((b[i] = a[i] * n + tp) < 0) {
				c[i] = 1;
				cnt ++;
				sum -= b[i];
				b[i] = 0;
			}
		for (int i = 1; i <= n; i ++) {
			if (c[i]) continue;
			b[i] = b[i] * (n - cnt) - sum;
			//printf("%d %lld\n", i, (long long)b[i]);
		}
		p = 0;
		for (int i = 1; i <= n; i ++) {
			p += sqr(a[i] * n * (n - cnt) - b[i]);
		}
		q = n * m * m * n * sqr(n - cnt);
		g = __gcd(p, q);
		p /= g, q /= g;
		if (p == 0) puts("0");
		else if (q == 1) printf("%lld\n", (long long)p);
		else printf("%lld/%lld\n", (long long)p, (long long)q);
	}
	return 0;
}