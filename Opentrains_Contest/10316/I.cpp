#include <bits/stdc++.h>

using namespace std;

int n, x, y, a, b, c, d;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i ++) {
		cin >> a >> b;
		a -= x, b -= y;
		c = a + b, d = -a;
		cout << x + c << ' ' << y + d << '\n';
	}
	return 0;
}