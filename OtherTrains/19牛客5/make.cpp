#include <bits/stdc++.h>

using namespace std;

int main() {
	int t = 4;
	printf("%d\n", t);
	srand(time(NULL));
	while (t --) {
		int n = 17;
		int x0 = rand() % n;
		int a = rand() % n;
		int b = rand() % n;
		printf("%d %d %d %d %d\n", n, x0, a, b, n);
		int m = n;
		printf("%d\n", m);
		while (m --) {
			printf("%d\n", rand() % n);
		}
	}
}