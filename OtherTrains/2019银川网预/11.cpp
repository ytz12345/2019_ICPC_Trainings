#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int B = 20;

int n, m, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n; ll ans;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	cin >> m;
	for (int op, l, r, x; m --; ) {
		cin >> op >> l >> r;
		if (op == 1) {
			ans = 0;
			for (int i = l; i <= r; i ++)
				ans += a[i];
			printf("%lld\n", ans);
		}
		else if (op == 2) {
			cin >> x;
			for (int i = l; i <= r; i ++)
				a[i] ^= x;
		}
		else if (op == 3) {
			cin >> x;
			for (int i = l; i <= r; i ++)
				a[i] |= x;
		}
		else if (op == 4) {
			cin >> x;
			for (int i = l; i <= r; i ++)
				a[i] &= x;
		}
	}
	return 0;
}