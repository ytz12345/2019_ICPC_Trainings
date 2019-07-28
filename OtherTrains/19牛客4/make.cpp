#include <bits/stdc++.h>

using namespace std;

int main() {
	srand(time(NULL));
	const int X = 1e6;
	int n = 0;
	printf("%d\n", n);
	for (int i = 1; i <= n; i ++) {
		printf("%d ", (rand() % X + 1) * (rand() & 1 ? 1 : -1));
	}	
	puts("");
	for (int i = 1; i <= n; i ++) {
		printf("%d ", (rand() % X + 1) * (rand() & 1 ? 1 : -1));
	}	
	puts("");
}