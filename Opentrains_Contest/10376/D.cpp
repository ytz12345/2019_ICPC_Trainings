#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, v[N];

vector <int> e[N];

int fa[N], siz[N], son[N], dep[N], top[N];

int cnt, st[N], pos[N], en[N];

int a[N];

#define lc (o << 1)
#define rc (o << 1 | 1)

struct node {
	int s, y;
}tr[N << 2];

void pushup(int o) {
	tr[o].s = tr[lc].s + tr[rc].s;
}

void pushdown(int o) {
	if (!tr[o].y) return;
	tr[lc].s = tr[rc].s = 0; 
	tr[lc].y = tr[rc].y = 1;
	tr[o].y = 0;
}

int ask(int o, int l, int r, int s, int t) {
	if (s <= l && r <= t) return tr[o].s;
	pushdown(o);
	int mid = l + r >> 1, res = 0;
	if (s <= mid) res += ask(lc, l, mid, s, t);
	if (t >  mid) res += ask(rc, mid + 1, r, s, t);
	return res;
} 

void modify(int o, int l, int r, int s, int t) {
	if (l == r) {
		tr[o].s = 0;
		return;
	}
	int mid = l + r >> 1;
	if (t > mid && ask(rc, mid + 1, r, s, t) > 0) modify(rc, mid + 1, r, s, t);
	else modify(lc, l, mid, s, t);
	pushup(o);
}

void change(int o, int l, int r, int s) {
	if (l == r) {
		tr[o].s = 1;
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (s <= mid) change(lc, l, mid, s);
	else change(rc, mid + 1, r, s);
	pushup(o);
}

void dfs1(int u) {
	siz[u] = 1;
	for (int v : e[u]) {
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs1(v), siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
 	}	
}

void dfs2(int u, int tp) {
	st[u] = ++ cnt, pos[cnt] = u, top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int v : e[u])
		if (v != son[u])
			dfs2(v, v);
	en[u] = cnt;
}

void modify(int u) {
	for (int fu = top[u]; fu; fu = top[u = fa[fu]]) {
		if (ask(1, 1, n, st[fu], st[u])) {
			modify(1, 1, n, st[fu], st[u]);
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n, n ++, v[1] = 1e9 + 7, a[1] = 1;
	for (int p, i = 2; i <= n; i ++) {
		cin >> v[i] >> p; a[i] = i;
		e[p + 1].push_back(i);
	}
	dfs1(1), dfs2(1, 1); 
	sort (a + 1, a + n + 1, [&](int x, int y){
		if (v[x] != v[y]) return v[x] < v[y];
		return dep[x] < dep[y];
	});
	for (int i = 1; i <= n; i ++) 
		modify(a[i]), change(1, 1, n, st[a[i]]);
	cout << tr[1].s - 1 << endl;
	return 0;
}