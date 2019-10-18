#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, a;

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a;
		putchar(a % 5 == 0 ? 'B' : 'F');
	}
}