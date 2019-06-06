#include <bits/stdc++.h>

using namespace std;

void dfs(int x) {
	if (x < 6) {
		for (int i = 1; i <= x; i ++)
			putchar('1');
		return;
	}
	putchar('[');
	dfs(x >> 1);
	putchar(']');
	if (x & 1) putchar('1');
}

int main() {
	int n;
	cin >> n;
	dfs(n);
	return 0;
}