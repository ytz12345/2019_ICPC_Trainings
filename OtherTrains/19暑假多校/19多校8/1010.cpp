#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, d;

struct node {
	char s[14];
	int p, t;
}a[N];

int main() {
	//freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	for (scanf("%d", &t); t --; ) {
		scanf("%d %d", &n, &d);
		for (int i = 0; i < n; i ++) {
			scanf("%s %d %d", a[i].s, &a[i].p, &a[i].t);
			//cin >> a[i].s >> a[i].p >> a[i].t;
		}
		sort (a, a + n, [&](node x,node y) {
			if (x.p != y.p) return x.p > y.p;
			return x.t < y.t;
		});
		if (n * d % 10 == 5) {
			n = n * d / 10;
			puts(a[n].s);
			//cout << a[n].s << '\n';
		}
		else puts("Quailty is very great");
	}
	return 0;
}
