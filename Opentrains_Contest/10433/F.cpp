#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k, a[N];

bool l() {
	if (n == k) return 1;
	for (int i = 2; i <= k; i ++)
		if (a[i] > a[i - 1])
			return 0;
	for (int i = k + 1; i <= n; i ++)
		if (a[i] > a[k])
			return 0;
	return 1;
}

bool r() {
	for (int i = n - k + 2; i <= n; i ++)
		if (a[i] < a[i - 1])
			return 0;
	for (int i = 1; i <= n - k; i ++)
		if (a[i] > a[n - k + 1])
			return 0;
	return 1;
}

int mid() {
	int mx = -1, len = 0;
	for (int i = 1; i <= n; i ++) mx = max(mx, a[i]);
	for (int i = 1; i <= n; i ++) {
		len += a[i] == mx;
		if (a[i] != a[i + 1] || i == n) {
			if (len >= k) return i - len + 1;
			len = 0;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	if (l()) puts("1");
	else if (r()) printf("%d\n", n - k + 1);
	else printf("%d\n", mid());

	return 0; 
}