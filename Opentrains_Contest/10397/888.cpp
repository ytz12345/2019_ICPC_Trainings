#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 1;

int main() {
	const int N = 23;
	srand(time(NULL));
	ios::sync_with_stdio(false);
	int n = rand() % N + 3;
	cout << n << endl;
	for (int i = 1; i <= n; i ++) cout << rand() % M << ' ';cout << endl;
	for (int i = 1; i <= n; i ++) cout << rand() % M << ' ';cout << endl;
	int m = rand() % N + 10;
	cout << m << endl;
	for (int i = 1; i <= m; i ++){
		int l = rand() % (n - 2) + 1;
		cout << l << ' ' << (rand() % ((n - l + 1) / 3) + 1) * 3 + l  - 1 << endl;
	}
	return 0;
}