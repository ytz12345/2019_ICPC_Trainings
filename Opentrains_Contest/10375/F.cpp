#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, p[N], r[N];

bool judge() {
	int d = p[1] + r[1];
	for (int i = 2; i <= n; i ++) {
		if (d < p[i]) return 0;
		d = max(d, p[i] + r[i]);
	}
	d = p[n] - r[n];
	for (int i = n - 1; i >= 1; i --) {
		if (d > p[i]) return 0;
		d = min(d, p[i] - r[i]);
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> p[i] >> r[i];
	}
	if (judge()) cout << 3ll * (p[n] - p[1]) << endl;
	else cout << -1 << endl;
	return 0; 
}