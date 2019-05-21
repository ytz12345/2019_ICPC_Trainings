#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

const ll inf = 1e9, inff = 1e18;

int t;

char s[30];

ll n, lp, lq, rp, rq, mp, mq;

ll l, r, mid, cnt;

int main() {
	for (cin >> t; t --; ) {
		cin >> s, n = 0;
		for (int i = 2; i < 20; i ++)
			n = n * 10 + s[i] - '0';
		if (n == 0) puts("0 1");
		else {
			lp = 0, lq = rp = rq = 1;
			while (max(lq, rq) <= inf) {
				mp = lp + rp, mq = lq + rq;
				if (mp * inff <= mq * n) { 
					l = 1, r = (inf - lq) / rq + 1, cnt = 1;
					while (l <= r) {
						mid = l + r >> 1;
						if ((lp + rp * mid) * inff <= (lq + rq * mid) * n)
							cnt = mid, l = mid + 1;
						else
							r = mid - 1;
					}
					lp = lp + rp * cnt, lq = lq + rq * cnt; 
				}
				else { 
					l = 1, r = (inf - rq) / lq + 1, cnt = 1;
					while (l <= r) {
						mid = l + r >> 1;
						if ((rp + lp * mid) * inff > (rq + lq * mid) * n)
							cnt = mid, l = mid + 1;
						else
							r = mid - 1;
					}
					rp = rp + lp * cnt, rq = rq + lq * cnt;
				}
			}
			if (lq <= inf) printf("%lld %lld\n", (long long)lp, (long long)lq);
			else printf("%lld %lld\n", (long long)rp, (long long)rq);
		}
	}
	return 0;		
}