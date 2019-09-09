#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int minv[N << 2];

int t, n, y, a[N];

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)

void build(int o, int l, int r) {
	if (l == r) {
		minv[o] = (a[n] - a[n - r]) / r;
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	minv[o] = min(minv[lc], minv[rc]);
}

int ask(int o, int l, int r, int v) {
	if (l == r) return n - r;
	if (minv[lc] < v) return ask(lc, l, mid, v);
	return ask(rc, mid + 1, r, v);
}

int main() { 
	ios::sync_with_stdio(false);
	while (cin >> n >> y){
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		sort (a + 1, a + n + 1);
		if (n == 1) {
			for (int i = 1; i <= y; i ++)
				printf("%d%c", a[1] + i, i == y ? '\n' : ' ');
		}
		else {
			build(1, 1, n - 1);
			for (int j, i = 1; i <= y; i ++) {
				if (minv[1] >= i) {
					printf("%d%c", a[n] + i, i == y ? '\n' : ' ');
				}
				else {
					printf("%d%c", max(a[n] + i, a[ask(1, 1, n - 1, i)] + y), i == y ? '\n' : ' ');
				}
			}
		}
	}
}