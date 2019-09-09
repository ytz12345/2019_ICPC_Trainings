#include <bits/stdc++.h>

int main() {
	srand(time(NULL));
	int t = 4;
	int lim = 4444441;
	printf("%d\n", t);
	while (t --) {
		int n = 40;
		printf("%d\n", n);
		while (n --) {
			printf("%d ", rand() % lim + 4);
		}
		puts("");
	}
}