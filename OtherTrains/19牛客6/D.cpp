#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int t, n, k, a[N], c[N];

struct node {
	int v, c;
}tr[23333];

#define lc (o << 1)
#define rc (o << 1 | 1)

void pushup(int o) {
	tr[o].v = max(tr[lc].v, tr[rc].v);
}

void build(int o, int l, int r) {
	if (l == r) {
		tr[o].c = c[r];
		if (tr[o].c != 0) tr[o].v = r;
		else tr[o].v = 0;
		return;
	}
	int mid = l + r >> 1;
	build (lc, l, mid);
	build (rc, mid + 1, r);
	pushup(o);
}

int ask(int o, int l, int r, int p) {
	if (r <= p) return tr[o].v;
	int mid = l + r >> 1;
	if (p <= mid) return ask(lc, l, mid, p);
	return max(tr[lc].v, ask(rc, mid + 1, r, p));
}

void del(int o, int l, int r, int p) {
	if (l == r) {
		tr[o].c --;
		if (tr[o].c == 0) tr[o].v = 0;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid) del(lc, l, mid, p);
	else          del(rc, mid + 1, r, p);
	pushup(o);
}

bool judge(int x) {
	build(1, 1, 1000); int y, z;
	for (int i = 1, j = n; i <= k; i ++) {
		y = x;
		//printf("%d %d\n", i, y);
		while (j > 0 && y > 0) {
			z = ask(1, 1, 1000, y);
			//printf("%d\n", z);
			if (z == 0) break;
			y -= z;
			del(1, 1, 1000, z);
			j --;
		}
		if (j == 0) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt ++) {
		scanf("%d %d", &n, &k);
		memset (c, 0, sizeof c);
		for (int i = 1; i <= n; i ++)
			scanf("%d", &a[i]), c[a[i]] ++;
		//judge(7); return 0;
		int l = 1, r = 1e6, mid, ans = 1e6;
		while (l <= r) {
			mid = l + r >> 1;
			if (judge(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		//return 0;
		for (int i = ans - 1, d = ans - 300; i >= d && i > 0; i --) 
			if (judge(i))
				ans = i;
		printf("Case #%d: %d\n", tt, ans);
	}
	//printf("%d\n", clock());
	return 0;
}