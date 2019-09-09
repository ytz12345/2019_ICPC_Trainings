#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	int t = 3;
	int N = 10, X = 8;
	while (t --) {
		int n = rand() % N + 1;
		while (n == 1) {
			n = rand () %N + 1;
		}
		int m = rand() % N + 1;
		cout << n << ' ' << m << '\n';
		for (int i = 1; i <= n;  i++) {
			cout << rand() % X << ' ';
		}
		cout << '\n';
		for (int i = 0; i < m; i ++) {
			int op = rand () % 2;
			if (op) {
				int l = rand() % n + 1;
				int r = rand() % n + 1;
				if (l > r) swap(l, r);
				cout << "1 " << l << ' ' << r << '\n';
			}
			else {
				cout << "2 " << (rand() % (n - 1) + 1) << '\n';
			}
		}
	}
}