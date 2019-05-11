#include <bits/stdc++.h>

using namespace std;

priority_queue <int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(false);
	int n, k, x, ans = 0;
	cin >> n >> k;
	for (int i = 1; i < k; i ++)
		cin >> x, q.push(x), ans += x;
	for (int i = k; i <= n; i ++) {
		cin >> x, q.push(x), ans += x;
		if (q.size() > k) ans -= q.top(), q.pop();
		printf("%d ", ans);
	}
	return 0;
}