#include <bits/stdc++.h>

using namespace std;

const int M = 100;

const int N = 100;

int p[N], v[N];

int main() {
	//int t;
	int t = 10;
	printf("%d\n", t);
	for (int i = 2; i < M; i ++) {
		 if (!v[i]) p[++ p[0]] = i;
		 for (int j = 1; j <= p[0] && i * p[j] < M; j ++) {
		 	v[i * p[j]] = 1;
		 }
	}
	while (t --) {
		printf("%d %d\n", rand() % N + 1, p[rand() % p[0] + 1]);
	}
}