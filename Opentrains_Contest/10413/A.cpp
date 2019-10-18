#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

ll d, n[3], a[3][N];

ll calc1(int b0, int b1, int b2) {
	ll res = 0;
	for (int i = 0; i < n[b0]; i ++)
		res += (upper_bound(a[b1], a[b1] + n[b1], a[b0][i] + d) 
			  - lower_bound(a[b1], a[b1] + n[b1], a[b0][i]))
			  *(upper_bound(a[b2], a[b2] + n[b2], a[b0][i] + d)
			  - lower_bound(a[b2], a[b2] + n[b2], a[b0][i]));
	return res;
}

ll calc2(int b0, int b1, int b2) {
	ll res = 0;
	for (int i = 0; i < n[b0]; i ++)
		res += (upper_bound(a[b1], a[b1] + n[b1], a[b0][i]) 
			  - lower_bound(a[b1], a[b1] + n[b1], a[b0][i]))
			  *(upper_bound(a[b2], a[b2] + n[b2], a[b0][i] + d)
			  - lower_bound(a[b2], a[b2] + n[b2], a[b0][i]));
	return res;
}

ll calc3(int b0, int b1, int b2) {
	ll res = 0;
	for (int i = 0; i < n[b0]; i ++)
		res += (upper_bound(a[b1], a[b1] + n[b1], a[b0][i]) 
			  - lower_bound(a[b1], a[b1] + n[b1], a[b0][i]))
			  *(upper_bound(a[b2], a[b2] + n[b2], a[b0][i])
			  - lower_bound(a[b2], a[b2] + n[b2], a[b0][i]));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> d) {
		for (int i = 0; i < 3; i ++) cin >> n[i];
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < n[i]; j ++)
				cin >> a[i][j];
		
		ll ans = 0;
		ans += calc1(0, 1, 2);
		ans += calc1(1, 0, 2);
		ans += calc1(2, 0, 1);

		ans -= calc2(0, 1, 2);
		ans -= calc2(0, 2, 1);
		ans -= calc2(1, 2, 0);

		ans += calc3(0, 1, 2);

		cout << ans << '\n';		
	}
}