#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int x, y;

double f[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> x >> y;
	for (int i = 1; i <= y; i ++)
		f[x + i] = 1;
	for (int i = x; i >= 1; i --)
		f[i] = f[i << 1] / 2 + f[i << 1 | 1] / 4;
	printf("%.10f\n", f[1]);
}