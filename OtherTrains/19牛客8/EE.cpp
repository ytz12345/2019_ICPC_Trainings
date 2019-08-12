#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;

typedef pair<int, int> piir;

struct edge {
	int u, v, l, r;
}e[N];

namespace LCT {
	int fa[N], ch[N][2], maxv[N];
	int sta[N], top;
	int tim[N];

	int mmax(int x, int y) {
		return tim[x] < tim[y] ? x : y;
	}

	bool isroot(int x) {
		return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
	}

	void reverse(int x) {
		if (!x) return;
		swap(ch[x][0], ch[x][1]);
		rev[x] ^= 1;
	}

	void pushdown(int x) {
		if (!rev[x]) return;
		reverse(ch[x][0]);
		reverse(ch[x][1]);
		rev[x] ^= 1;
	}

	void pushup(int x) {
		maxv[x] = mmax(mmax(ch[x][0], ch[x][1]), tim[x]);
	}

	void rot(int x) {
		int y = fa[x], z = fa[y], d = ch[y][1] == x, c = ch[x][!d];
		fa[x] = z; if (!isroot(y)) ch[z][ch[z][1] == y] = x;
		ch[y][d] = c; if (c) fa[c] = y;
		fa[y] = x, ch[x][!d] = y;
		pushup(y), pushup(x);
	}

	void splay(int x) {
		int u = x, top = 0, y, z;
		while (!isroot(u)) sta[++ top] = u, u = fa[u];
		sta[++ top] = u;
		while (top) pushdown(sta[top --]);
		while (!isroot(x)) {
			y = fa[x], z = fa[y];
			if (!isroot(y)) {
				if ((ch[z][0] == y) ^ (ch[y][0] == x)) rot(x);
				else rot(y);
			}
			rot(x);
		}
	}

	void access(int x) {
		for (int y = 0; x != 0; y = x, x = fa[x])
			splay(x), ch[x][1] = y, pushup(x);
	}

	void makeroot(int x) {
		access(x), splay(x), reverse(x);
	}

	int findroot(int x) {
		access(x), splay(x);
		while (ch[x][0]) pushdown(x), x = ch[x][0];
		splay(x);
		return x;
	}

	void split(int x, int y) {
		makeroot(x);
		access(y), splay(y);
	}

	void link(int x, int y) {
		makeroot(x);
		if (findroot(y) != x) fa[x] = y;
	}

	void cut(int x, int y) {
		makeroot(x);
		if (findroot(y) == x && fa[y] == x && ch[x][1] == y) {
			fa[y] = ch[x][1] = 0;
			pushup(x);
		}
	}
}

int a[N], cnt;

int add[N], del[N];

vector <piir> f[N];

using namespace LCT;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].l >> e[i].r;
		a[cnt ++] = e[i].l - 1;
		a[cnt ++] = e[i].r;
	}
	a[cnt ++] = -1;
	a[cnt ++] = 1e9;
	sort (a, a + cnt);
	cnt = unique(a, a + cnt) - a;
	for (int i = 1; i <= m; i ++) {
		add[i] = lower_bound(a + 1, a + cnt, e[i].l - 1) - a + 1;
		del[i] = lower_bound(a + 1, a + cnt, e[i].r) - a + 1;
		f[add[i]].push_back(piir(i, 1));
		f[del[i]].push_back(piir(i, -1));
	}
	for (int x, y, i = 0; i <= cnt; i ++) {
		for (piir j : e[i]) {
			x = e[j.first].u, y = e[j.first].v;
			makeroot(x);
			if (findroot(y) != x) {
				fa[x] = y;
				tim[x] = del[j.first];
			}
			else {	
				split(x, y);

			}
		}
	}
	return 0;
}