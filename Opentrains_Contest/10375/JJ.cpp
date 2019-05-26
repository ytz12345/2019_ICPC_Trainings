#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pr;

set <pr> s, t;

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int n = 1e5;
	int m = 3e5;
	int q = 1e4;
	cout << n << ' ' << m << '\n';
	int x, y;
	while (m --) {
		while (1) {
			x = rand() % n + 1;
			y = rand() % n + 1;
			if (x > y) swap(x, y);
			if (x != y && s.find(pr(x, y)) == s.end()) {
				cout << x << ' ' << y << '\n';
				s.insert(pr(x, y));
				break;
			} 
		}
 	}
 	cout << q << '\n';
 	while (q --) {
 		while (1) {
			x = rand() % n + 1;
			y = rand() % n + 1;
			if (x > y) swap(x, y);
			if (x != y && t.find(pr(x, y)) == t.end()) {
				cout << x << ' ' << y << '\n';
				t.insert(pr(x, y));
				break;
			} 
		}
 	}
 	return 0;
}