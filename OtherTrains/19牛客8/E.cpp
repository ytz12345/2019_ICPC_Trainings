#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;

typedef pair<int, int> piir;

struct node {
	int u, v, l, r;
};

int n, m, tot;

int a[N * 2], cnt, ans;

int f[N], s[N];

int sta[N * 20];

int top;

vector <node> e;

int fa(int x) {
	while (x != f[x]) x = f[x];
	return x;
}

void link(int u, int v) {
	u = fa(u), v = fa(v);
	if (u == v) return;
	if (s[u] > s[v]) swap(u, v);
	if (s[u] == s[v]) s[v] ++, sta[++ top] = -v;
	f[u] = v, sta[++ top] = u;
}

void cut(int last) {
	while (top > last) {
		if (sta[top] < 0) s[-sta[top]] --;
		else f[sta[top]] = sta[top];
		top --;
	}
}

void solve (int head, int tail, const vector <node> &e) {
	if (e.size() == 0) return;
	int last = top, mid = head + tail >> 1;
	vector <node> l, r;
	for (node i : e) {
		if (i.l <= head && tail <= i.r) {
			link(i.u, i.v);
		}
		else {
			if (i.l <= mid) l.push_back(i);
			if (i.r >  mid) r.push_back(i);
		}
	}
	if (fa(1) == fa(n)) {
		//printf("%d %d\n", head, tail);
		ans += a[tail] - a[head - 1];
		cut(last);
		return;
	}
	if (head == tail) {
		cut(last);
		return;
	}
	solve(head, mid, l);
	solve(mid + 1, tail, r);
	cut(last);
}

int main() {
	//cout << sizeof (int) << endl;
	//cout << sizeof (e) + sizeof(sta) << endl;return 0;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	e.resize(m);
	for (int i = 0; i < m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].l >> e[i].r;
		a[cnt ++] = e[i].l - 1;
		a[cnt ++] = e[i].r;
	}
	a[cnt ++] = 0;
	a[cnt ++] = 1e9;
	sort (a, a + cnt);
	cnt = unique(a, a + cnt) - a;
	for (int i = 0; i < m; i ++) {
		e[i].l = lower_bound(a + 1, a + cnt, e[i].l) - a;
		e[i].r = lower_bound(a + 1, a + cnt, e[i].r) - a;
	}
	for (int i = 1; i <= n; i ++)
		f[i] = i, s[i] = 1;
	solve(1, cnt - 1, e);
	cout << ans << endl;
	return 0;
}