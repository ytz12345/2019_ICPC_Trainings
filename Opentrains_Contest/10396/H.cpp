#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, k, d;

int a[N], b[N];

long long ans;

bool judge(int t) {
	static queue <int> q;
	while (!q.empty()) q.pop();
	for (int i = 0; i < t; i ++)
		q.push(1);
	for (int i = 1; i <= k; i ++) {
		if (b[i] - q.front() > d) return 0;
		q.pop(), q.push(b[i]);
	}
	while (!q.empty()) {
		if (n - q.front() > d) return 0;
		q.pop();
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> d;
	for (int i = 1; i <= m; i ++)
		cin >> a[i];
	for (int i = 1; i <= k; i ++)
		cin >> b[i];
	sort (a + 1, a + m + 1);
	sort (b + 1, b + k + 1);
	int l = 1, r = m, mid, maxm = 0;
	while (l <= r) {
		mid = l + r >> 1;
		if (judge(mid)) maxm = mid, l = mid + 1;
		else r = mid - 1;
	}
	if (maxm != 0) {
		for (int i = 1; i + maxm <= m; i ++)
			ans += a[i];
	} 
	else {
		for (int i = 2; i <= m; i ++)
			ans += a[i];
		if (b[1] - 1 > d) ans += a[1];
		for (int i = 2; i <= k; i ++)
			if (b[i] - b[i - 1] > d)
				ans += a[1];
		if (n - b[k] > d) ans += a[1];
	}
	cout << ans << endl;
	return 0;
}