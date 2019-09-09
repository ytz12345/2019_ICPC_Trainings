#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = N * 20;

struct {
	int sz, l, r;
}tr[M];

#define l(x) tr[x].l
#define r(x) tr[x].r
#define s(x) tr[x].sz
#define mid (l + r >> 1)

int tot, root[N];

int build(int l, int r) {
	int x = ++ tot;
	s(x) = 0;
	if (l < r) {
		l(x) = build(l, mid);
		r(x) = build(mid + 1, r);
	}
	return x;
}

int change(int o, int l, int r, int p) {
	int x = ++ tot;
	s(x) = s(o) + 1, l(x) = l(o), r(x) = r(o);
	if (l < r) {
		if (p <= mid) l(x) = change(l(o), l, mid, p);
		else r(x) = change(r(o), mid + 1, r, p);
	}
	return x;
} 

int ask(int o1, int o2, int l, int r, int k) {
	//printf(" %d %d\n", l, r);
	if (l == r) return r;
	if (s(r(o2)) - s(r(o1)) < k) return ask(l(o1), l(o2), l, mid, k - (s(r(o2)) - s(r(o1))));
	return ask(r(o1), r(o2), mid + 1, r, k); 
}

int n, m, k, a[N], b[N];

long long c[N];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort (b + 1, b + n + 1);
		k = unique(b + 1, b + n + 1) - b - 1;
		tot = 0, root[0] = build(1, k);
		for (int i = 1; i <= n; i ++) {
			root[i] = change(root[i - 1], 1, k, lower_bound(b + 1, b + k + 1, a[i]) - b);
			//printf("%d %d\n", i, lower_bound(b + 1, b + k + 1, a[i]) - b);
		}
		for (int flag, l, r, i = 1; i <= m ; i ++) {
			cin >> l >> r;
			if (r - l + 1 < 3) puts("-1");
			else {
				flag = 0;
				for (int i = 1, up = r - l + 1; i <= up; i ++) {
					c[i] = b[ask(root[l - 1], root[r], 1, k, i)];
					//printf("%d %d %d %d\n", l, r, i, b[ask(root[l - 1], root[r], 1, k, i)]);
					if (i >= 3) {
						if (c[i - 2] < c[i - 1] + c[i]) {
							printf("%lld\n", c[i - 2] + c[i - 1] + c[i]);
							flag = 1;
							break;
						}
					}
				}
				if (!flag) puts("-1");	
			}
		}
		//break;
	}
	return 0;
}