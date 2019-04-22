#include <bits/stdc++.h>

using namespace std;

int n, x[3], y[3];

void print(int a, int b, int c, int d, char ch = '?') {
	printf("%c %d %d %d %d\n", ch, a, b, c, d);
	fflush(stdout);
}

int main() {
	int res;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		print(i, 1, i, n);
		scanf("%d", &res);
		if (res & 1) x[++ x[0]] = i;
	}
	for (int i = 1; i <= n; i ++) {
		print(1, i, n, i);
		scanf("%d", &res);
		if (res & 1) y[++ y[0]] = i;
	}
	if (x[0] == 2 && y[0] == 2) {
		print(x[1], y[1], x[1], y[1]);
		scanf("%d", &res);
		if (res & 1) print(x[1], y[1], x[2], y[2], '!');
		else print(x[1], y[2], x[2], y[1], '!');
	}
	else if (x[0] == 2) {
		int l = 1, r = n, mid, p;
		while (l <= r) {
			mid = l + r >> 1;
			print(1, 1, x[1], mid);
			scanf("%d", &res);
			if (res & 1) p = mid, r = mid - 1;
			else l = mid + 1;
		}
		print(x[1], p, x[2], p, '!');
	}
	else {
		int l = 1, r = n, mid, p;
		while (l <= r) {
			mid = l + r >> 1;
			print(1, 1, mid, y[1]);
			scanf("%d", &res);
			if (res & 1) p = mid, r = mid - 1;
			else l = mid + 1;
		}
		print(p, y[1], p, y[2], '!');
	}
	return 0;
}