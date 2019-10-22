#include <bits/stdc++.h>

using namespace std;

const int n = 1e6;

int t, x, b, c;

int main() {
	for (cin >> t; t --; ) {
		cin >> x;
		b = -(x + 1), c = x;
		if (abs(b) > n || abs(c) > n || abs(b) == 0) b = -(x - 1), c = -x;
		printf("1 %d %d\n", b, c);
	}
}