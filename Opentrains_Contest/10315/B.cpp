#include <bits/stdc++.h>

using namespace std;

int n;

set <int> s;

int main() {
	cin >> n;
	for (int x, i = 0; i < n; i ++) {
		cin >> x;
		for (int j = 1; j * j <= x; j ++)
			if (x % j == 0)
				s.insert(j), s.insert(x / j);
	}
	for (int i = 1; ; i ++) {
		if (s.find(i) == s.end()) {
			cout << i;
			return 0;
		}
	}
}