#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

int t;

ll a;

ll a1[100], a2[100];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> a;
		if (a % 3 == 0) {
			printf("1 %lld\n", a);
		}
		else {
			a1[0] = a2[0] = 0;
			for (int i = 0; i < 64; i ++) {
				if ((a >> i) & 1) {
					if (i & 1) a2[++ a2[0]] = i;
					else       a1[++ a1[0]] = i;
				}
			}
			if (a2[0] == 0) {
				ll x = 0, y = 0;
				int k = a1[0] / 3 * 3;
				for (int i = a1[0], j = 0; j < k; i --, j ++)
					x |= 1ll << a1[i];
				y = (1ll << a1[1]) | (1ll << a1[2]) | (1ll << a1[3]);
				printf("2 %lld %lld\n", x, y); 
			}
			else if (a1[0] == 0) {
				ll x = 0, y = 0;
				int k = a2[0] / 3 * 3;
				for (int i = a2[0], j = 0; j < k; i --, j ++)
					x |= 1ll << a2[i];
				y = (1ll << a2[1]) | (1ll << a2[2]) | (1ll << a2[3]);
				printf("2 %lld %lld\n", x, y); 
			}
			else {
				ll x = 0, y = 0;
				int k = min(a1[0], a2[0]);
				for (int i = 1; i <= k; i ++) {
					x |= 1ll << a1[i];
					x |= 1ll << a2[i];
				}
				for (int i = 1 + k; i <= a1[0]; i ++) 
					y |= 1ll << a1[i];
				for (int i = 1 + k; i <= a2[0]; i ++) 
					y |= 1ll << a2[i];

				if (y % 3 == 1) y |= 1ll << a2[1];
				else y |= 1ll << a1[1]; 

				printf("2 %lld %lld\n", x, y); 
			}
		}
	}
	return 0;

}