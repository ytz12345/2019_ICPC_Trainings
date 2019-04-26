#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int c1[10], c2[20][10];

int n, a[N], b[N];

long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		c1[a[i] % 7] ++;
		for (int j = a[i]; j > 0; j /= 10)
			b[i] ++;
		c2[b[i]][a[i] % 7] ++;
	}
	for (ll i = 0; i < 7; i ++) {
		for (ll j = 10, k = 1; k <= 10; k ++, j *= 10) {
			for (ll t = 0; t < 7; t ++) {
				if ((i * j + t) % 7 == 0)
					ans += 1ll * c1[i] * c2[k][t];
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		ll j = 1;
		for (int t = 1; t <= b[i]; t ++)
			j *= 10;
		if (((a[i] % 7) * j + (a[i] % 7)) % 7 == 0)
			ans --;
	}
	cout << ans;
	return 0;
}