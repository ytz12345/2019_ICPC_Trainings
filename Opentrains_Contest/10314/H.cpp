#include <bits/stdc++.h>

#define rep(i, j, k) for (int i = (j); i <= (k); i ++)

using namespace std;

typedef long long ll;

ll n;

int m;

const double eps = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	while (m --) {
		cin >> n;
		int i = 2;
		do {
			if (n % i == 0) {
				n = -1;
				break;
			}
			n -= n / i;
			i ++;
		}while(n >= i);
		printf("%lld\n", n);
	}
	return 0;
}