#include <bits/stdc++.h>

using namespace std;

priority_queue <int> q;

long long a[2];

int t, n, x;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> x;
			q.push(x);
		}
		a[0] = a[1] = 0;
		for (int i = 0; i < n; i ++) {
			a[i & 1] += q.top();
			q.pop();
		}
		printf("%lld %lld\n", a[0], a[1]);
	}
	return 0;
}