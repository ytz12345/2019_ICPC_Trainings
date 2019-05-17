#include <bits/stdc++.h>

using namespace std;

int T, n;

struct line {
	int a, b, c;
	int id;
};

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T --) {
		cin >> n;
		vector <line> a(n);

		for (int i = 0; i < n; i ++) {
			a[i].id = i + 1;
			cin >> a[i].a >> a[i].b >> a[i].c;
			int d = __gcd(a[i].a, __gcd(a[i].b, a[i].c));
			a[i].a /= d, a[i].b /= d, a[i].c /= d;
		}
	}
}