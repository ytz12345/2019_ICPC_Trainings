#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

long long ans;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		ans = 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		for (int u, v, i = 1; i < n;  i ++) {
			cin >> u >> v;
			ans += min(a[u], a[v]);
		}
		cout << ans << '\n';
	}
}