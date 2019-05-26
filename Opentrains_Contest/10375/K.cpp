#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
#define dwn(i, j, k) for (int i = int(j); i >= int(k); -- i)
typedef long long ll;
const int N = 5e5 + 7;
int cnt[70], bit[70];
int f[70][N];
int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	ll S;
	cin >> S;
	rep(j, 0, 64) bit[j] = (S & 1), S >>= 1;
	rep(i, 1, n) {
		ll x;
		cin >> x;
		rep(j, 0, 64) cnt[j] += (x & 1), x >>= 1;
	}

	rep(k, 0, 1)
	if (bit[0] == k) {
		if (cnt[0] % 2 == k) f[0][cnt[0] / 2] = 1;
		if ((n - cnt[0]) % 2 == k) f[0][(n - cnt[0]) / 2] = 1;
	}

	rep(i, 0, 64) rep(j, 0, N - 1) 
	if (f[i][j]) {
		rep(k, 0, 1)
		if (bit[i + 1] == k) {
			if ((j + cnt[i + 1]) % 2 == k) f[i + 1][(j + cnt[i + 1]) / 2] = 1;
			if ((j + n - cnt[i + 1]) % 2 == k) f[i + 1][(j + n - cnt[i + 1]) / 2] = 1;
		}
	}

	if (!f[64][0]) {
		cout << -1 << endl;
		return 0;
	}

	ll ans = 0; int need = 0; 
	dwn(i, 63, 1) {
		if (bit[i] + need >= cnt[i] && bit[i] + need - cnt[i] < N && f[i - 1][bit[i] + need - cnt[i]]) {
			need = (bit[i] + need - cnt[i]) * 2;
		}
		else if (bit[i] + need >= n - cnt[i] && bit[i] + need - (n - cnt[i]) < N && f[i - 1][bit[i] + need - (n - cnt[i])]) {
			ans += 1ll << i;
			need = (bit[i] + need - (n - cnt[i])) * 2;
		}
	}
	//cout << need << endl;
	if (need + bit[0] == cnt[0]); 
	else if (need + bit[0] == n - cnt[0]) ans += 1;
	cout << ans << endl;
}