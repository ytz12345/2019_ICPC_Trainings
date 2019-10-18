#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

int n, m, k;

int ans[N], tim;

namespace UFS {
	int f[N], rk[N];
	int top, sta[N * 5];
	int fa(int x) {
		while (x != f[x]) x = f[x];
		return x;
	}
	void un(int x, int y) {
		x = fa(x), y = fa(y);
		if (x == y) return;
		if (rk[x] > rk[y]) swap(x, y);
		if (rk[x] == rk[y]) rk[y] ++, sta[++ top] = -y;
		f[x] = y, sta[++ top] = x;
	}
	void undo(int last) {
		for (; top > last; top --) {
			if (sta[top] < 0) rk[-sta[top]] --;
			else f[sta[top]] = sta[top];
		}
	}
	void init() {
		for (int i = 1; i <= n; i ++)
			f[i] = i, rk[i] = 0;
	}
}

struct node {
	int u, v, l, r, id;
}a[N];

void solve (int head, int tail, const vector <node> &e) {
	int last = UFS::top, mid = head + tail >> 1;
	if (head == tail) {
		for (node i : e) 
			if (i.id == 0)
				UFS::un(i.u, i.v);
		for (node i : e) {
			if (UFS::fa(i.u) == UFS::fa(i.v))
				ans[i.id] = tim;
		} 
		UFS::undo(last);
		return;
	}
	vector<node> l, r;
	for (node i : e) {
		if (i.l <= head && tail <= i.r)  UFS::un(i.u, i.v);
		else {
			if (i.l <= mid) l.push_back(i);
			if (i.r >  mid) r.push_back(i);
		}
	}
	solve(head, mid, l), solve(mid + 1, tail, r); 
	UFS::undo(last);
}

vector <node> e;

map <piir, int> p;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i].u >> a[i].l >> a[i].r;
		a[i].l ++, a[i].r ++;
		if (a[i].l > a[i].r) swap(a[i].l, a[i].r);
		if (a[i].u == 0) cin >> a[i].v;
		if (a[i].u == 2) ans[++ k] = -1;
	}

	for (int j = 9, d; j >= 0; j --) {
		e.clear(), p.clear(), tim = j, d = 0;
		for (int i = 1; i <= m; i ++) {
			if (a[i].u == 0) {
				if (a[i].v <= j) p[piir(a[i].l, a[i].r)] = i;
			}
			else if (a[i].u == 1) {
				if (p.find(piir(a[i].l, a[i].r)) != p.end()) {
					e.push_back((node){a[i].l, a[i].r, p[piir(a[i].l, a[i].r)], i, 0});
					p.erase(piir(a[i].l, a[i].r));
				}
			}
			else 
				e.push_back((node){a[i].l, a[i].r, i, i, ++ d});
		}
		for (auto i : p)
			e.push_back((node){i.first.first, i.first.second, i.second, m + 1, 0});
		UFS::init(), solve(1, m + 1, e);
	}
	for (int i = 1; i <= k; i ++) 
		printf("%d\n", ans[i]);
	return 0;
}