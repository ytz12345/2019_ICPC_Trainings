#include <bits/stdc++.h>

using namespace std;

priority_queue <int, vector<int>, greater<int> > q;

int r, s, n, m;

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> s >> n;
	for (int x, y, z, i = 0; i < n; i ++) {
		cin >> x >> y, z = r + 1 - x;
		if (y <= s) z += (s + 1) - y;
		else        z += y - s;
		q.push(z);
	}
	while (!q.empty()) m = max(m + 1, q.top()), q.pop();
	cout << m << endl;
}