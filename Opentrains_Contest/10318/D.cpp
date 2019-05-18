#include <bits/stdc++.h>

using namespace std;

int n, a[555];

int main() {
	cin >> n;
	puts("Yes");
	for (int i = 2; i <= n; i ++) a[i - 1] = i;
	for (int i = 1; i <= (n - 1) / 2; i ++) {
		printf("1");
		for (int j = 1; j <= (n - 1) / 2; j ++) printf(" %d %d", a[j], a[n - j]);
		puts("");
		int t = a[n - 1];
		for (int i = n - 1; i >= 2; i --) a[i] = a[i - 1];
		a[1] = t;
	}
	return 0;
}
