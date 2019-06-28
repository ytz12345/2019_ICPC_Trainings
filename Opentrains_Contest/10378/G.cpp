#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 40;

int n, k, a, b;

int l[N], r[N], v[N];

map <ll, int> p;

ll ans;

void dfs(int id, ll x) {
	if (id > k) {
		p[x] ++;
		return;
	}
	dfs(id + 1, x);
	dfs(id + 1, x + v[id]);
}

void redfs(int id, ll x) {
	if (id > n) {
		ans += p[-x];
		return;
	}
	redfs(id + 1, x);
	redfs(id + 1, x + v[id]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i ++) {
		cin >> l[i] >> r[i];
		v[i] = l[i] * b - r[i] * a;
	}
	k = n >> 1;
	dfs(1, 0);
	redfs(k + 1, 0);
	cout << ans - 1 << endl;
	return 0;
}