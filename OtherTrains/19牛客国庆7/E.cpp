#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[1000];

int f[1000];

int check() {
	int v = 0;
	for (int i = 1; i <= n; i ++) {
		f[i] = 1;
		for (int j = 1; j < i; j ++) {
			if (a[j] < a[i]) {
				f[i] = max(f[i], f[j] + 1);
				if (f[i] > v) break;
			}
		}
		v = max(v, f[i]);
	}
	return v == n - 1;
}

int main() {
	for (n = 1; n <= 10; n ++) {
		m = 0;
		for (int i = 1; i <= n; i ++)
			a[i] = i;
		do {m += check();} while (next_permutation(a + 1, a + n + 1));
		cout << n << ' ' << m << endl;
	}
}