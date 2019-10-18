#include <bits/stdc++.h>

#define lb(x) (x&(-x))

using namespace std;

const int N = 1e5 + 5;

int n, m;

void add(int *c, int i, int x) {while (i <= n) c[i] += x, i += lb(i);}

int ask(int *c, int i) {int res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

int c[3][N];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		memset (c, 0, sizeof c);
		for (int op, x, y; m --; ) {
			cin >> op >> x >> y;
			if (op == 1) {
				add(c[0], x, 1), add(c[0], y + 1, -1);
				if (y - x >= 1) add(c[1], x + 1, 1), add(c[1], y + 1, -1);
				if (y - x >= 2) add(c[2], x + 2, 1), add(c[2], y + 1, -1);
			}
			else {
				printf("%d\n", ask(c[y - x], y));
			}
		}
	}
}