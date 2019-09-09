#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

ll n, a[N], b[N];

ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		ans += 1ll * (i - b[a[i]]) * (n - i + 1);
		b[a[i]] = i;
	}
	cout << ans << endl;
	return 0;
}