#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("test.txt", "w", stdout);
	srand(time(NULL));
	int t = 2;
	printf("%d\n", t);
	while (t --) {
		int n = 1e6;
		printf("%d\n", n);
		for (int i = 0; i < n; i ++) {
			printf("%d %d\n", rand() % n + 1, rand() % n + 1);
		}
	}
	return 0;
}
