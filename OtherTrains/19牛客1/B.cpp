#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Mod = 1e9 + 7;

const int N = 1010;

ll n, a[N], ans[N][N];

ll sqr(ll x) {
	return x * x;
}

ll calc(ll x, ll k = Mod - 2) {
	ll res = 1;
	for (x %= Mod; k > 0; k >>= 1, x = x * x % Mod)
		if (k & 1) res = res * x % Mod;
	return res % Mod;
}

ll dfs(int l, int r) {
	if (ans[l][r] != -1) return ans[l][r];
	if (l == r) return ans[l][r] = calc(a[r] * 2) % Mod;
	return ans[l][r] = (dfs(l, r - 1) - dfs(l + 1, r)) % Mod * calc(sqr(a[r]) - sqr(a[l])) % Mod;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 1; i <= n; i ++) 
			cin >> a[i];
		sort (a + 1, a + n + 1);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				ans[i][j] = -1;
		cout << (dfs(1, n) % Mod + Mod) % Mod << '\n';
	}
	return 0;
}