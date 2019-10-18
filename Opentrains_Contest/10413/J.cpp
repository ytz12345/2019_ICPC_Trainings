#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 2e5 + 5;
const ll Mod = 1e9 + 7;

ll n, m, q, a[N];

struct node {ll l, r, id;};

vector <node> e;

ll ans[N];

ll L[N][23], R[N][23];

void solve(ll l, ll r, const vector<node> &e) {
	if (e.empty()) return;
	if (l == r) {
		for (auto i : e)
			ans[i.id] = a[r] % m == 0 ? 2 : 1;
		return;
	}
	ll mid = l + r >> 1;
	for (ll i = 1; i < m; i ++)
		L[mid + 1][i] = R[mid][i] = 0;
	L[mid + 1][0] = R[mid][0] = 1;
	for (ll i = mid; i >= l; i --) {
		for (ll j = 0; j < m; j ++) L[i][j] = L[i + 1][j];
		for (ll j = 0; j < m; j ++) (L[i][(j + a[i]) % m] += L[i + 1][j]) %= Mod;
	}
	for (ll i = mid + 1; i <= r; i ++) {
		for (ll j = 0; j < m; j ++) R[i][j] = R[i - 1][j];
		for (ll j = 0; j < m; j ++) (R[i][(j + a[i]) % m] += R[i - 1][j]) %= Mod;
	}
	vector <node> ls, rs;
	for (auto i : e) {
		if (i.r <= mid) ls.push_back(i);
		else if (i.l > mid) rs.push_back(i);
		else {
			ans[i.id] = 0;
			for (ll j = 0; j < m; j ++)
				(ans[i.id] += L[i.l][j] * R[i.r][(m - j) % m] % Mod) %= Mod;
		} 
	}
	solve(l, mid, ls), solve(mid + 1, r, rs);
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (ll i = 1; i <= n; i ++)
			cin >> a[i], a[i] %= m;
		cin >> q;
		e.resize(q);
		for (ll i = 0; i < q; i ++)
			cin >> e[i].l >> e[i].r, e[i].id = i;
		solve(1, n, e);
		for (ll i = 0; i < q; i ++)
			printf("%lld\n", (ans[i] % Mod + Mod) % Mod);
	}
}