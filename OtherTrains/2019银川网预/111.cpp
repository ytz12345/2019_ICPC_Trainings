#include <ios>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5;
const int B = 20;

const int M = 1e6;

int n, m, a[N];

int main() {
	ios::sync_with_stdio(false);
	int n = rand() % N + 1;
	printf("%d\n", n);
	for (int i = 1; i <=n;i ++)
		printf("%d ",rand() % M + 1);
	puts(""); 
	int m = rand() % 1000 + 1;
	for (int i = 1; i <= n; i ++) {
		int op = rand() % 4 + 1;
		int l = rand() % n + 1, r = rand() % n + 1;
		if (l > r) swap(l, r);
		printf("%d %d %d", op, l, r);
		if (op == 1) puts("");
		else printf(" %d\n", rand() % M + 1);
	}
	return 0;
}