#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll n, m, c, t, a[N];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> c) {
		for (int i = 1; i <= n; i ++)
			cin >> a[i], a[i] += a[i - 1];
		sort (a, a + n + 1); t = 0;
		for (int l = 0, r = n; m --; l ++, r --) {
			if (a[r] - a[l] <= c) break;
			t += a[r] - a[l] - c;
		}
		cout << t << '\n';
	}
}