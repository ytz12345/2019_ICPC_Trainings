#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N], v[N];

int n, k, a[N];

bool judge(int x) {
	int cnt = 1, g = 0;
	for (int i = 1; i <= n; i ++) {
		g = __gcd(g, a[i]);
		if (v[g] < x) cnt ++, g = a[i];
	}
	return cnt <= k;
}

int main() {
	ios::sync_with_stdio(false);
	for (int i = 2; i < N; i ++) {
		if (!v[i]) {
			p[++ p[0]] = i; v[i] = i;
			for (int j = i << 1; j < N; j += i)
				v[j] = i;
		} 
	}
	while (cin >> n >> k) {
		for (int i = 0; i < n; i ++)
			cin >> a[i];
		int l = 0, r = p[0], mid, ans = 0;
		while (l <= r) {
			mid = l + r >> 1;
			if (judge(p[mid])) ans = p[mid], l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}