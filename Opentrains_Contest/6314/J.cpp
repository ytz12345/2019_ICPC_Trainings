#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n, l2[N];

ll a[N], b[N], ans;

int main() {
	ios::sync_with_stdio(false);
	l2[1] = 0;
	for (int i = 2; i < N; i ++)
		l2[i] = l2[i >> 1] + 1;

	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	sort (a + 1, a + n, [&](ll x, ll y){
		return x > y;
	});
	ll base, tmp;
	ans += (base = a[1] - a[2]); b[2] = a[1]; 
	for (int i = 3; i < n; i ++) {
		ll cnt = (b[i - 1] - a[i] - base) * (l2[i - 1] + 1);
		b[i] = b[i - 1] + (b[i - 1] - a[i] - base) * l2[i - 1];
		if (b[i] > a[0]) { 
			ans += (a[0] + 1 - b[i - 1]) / l2[i - 1] * (l2[i - 1] + 1);
			tmp =  (a[0] + 1 - b[i - 1]) % l2[i - 1];
			if (tmp == 0) ans --;
			else ans += tmp;
			cout << ans - 1 << endl;
			return 0;
		}
		else {
			ans += cnt;
			base += (b[i - 1] - a[i] - base) * (l2[i - 1] + 1);
		}
	}
	ans += (a[0] + 1 - b[n - 1]) / l2[n - 1] * (l2[n - 1] + 1);
	tmp =  (a[0] + 1 - b[n - 1]) % l2[n - 1];
	if (tmp == 0) ans --;
	else ans += tmp;
	cout << ans - 1 << endl;
	return 0;
}