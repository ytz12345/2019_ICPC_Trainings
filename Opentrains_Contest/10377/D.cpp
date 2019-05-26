#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pr;

const int N = 3e5 + 5;

const int inf = 1e9 + 7;

int n, l, r;

int a[N], s[N];

int dp[N];

multiset <int, greater<int> > ss[666666];

struct node {
	node *c[2];
	pr v;
	int mv, r, siz;

	node() {
		c[0] = c[1] = NULL;
		v = pr(-inf, -inf), mv = -inf, r = siz = 0;
	}

	void update() {
		siz = c[0] -> siz + c[1] -> siz + 1;
		mv = max(v.second, max(c[0] -> mv, c[1] -> mv));
	}

	void init(pr x);
};

node *null = new node, *root = null;

void node::init(pr x) {
	v = x, r = rand(), siz = 1;
	c[0] = c[1] = null;
	mv = x.second;
}

void rot(node *&o, int d) {
	node *tmp = o -> c[!d];
	o -> c[!d] = tmp -> c[d], tmp -> c[d] = o;
	o -> update(), tmp -> update(), o = tmp;
}

void insert(node *&o, pr x) {
	if (o == null) {
		o = new node();
		o -> init(x);
		return;
	}
	int d = x < o -> v ? 0 : 1;
	insert(o -> c[d], x);
	if (o -> c[d] -> r < o -> r) rot(o, !d);
	o -> update();
}

void del(node *&o, pr x) {
	if (o == null) return;
	if (x == o -> v) {
		if (o -> c[0] == null) {o = o -> c[1]; return;}
		if (o -> c[1] == null) {o = o -> c[0]; return;}
		int d = o -> c[0] -> r < o -> c[1] -> r ? 1 : 0;
		rot(o, d), del(o -> c[d], x);
	}
	else del(o -> c[x >= o -> v], x);
	o -> update();
}

void add(int x) {
	if (dp[x] == -inf) return;
	ss[s[x]].insert(dp[x]);
	insert(root, pr(s[x], dp[x]));
}

void rem(int x) {
	if (dp[x] == -inf) return;
	ss[s[x]].erase(ss[s[x]].find(dp[x]));
	del(root, pr(s[x], dp[x]));
}

int ask(int x) {
	static node *p;
	int res = -inf;
	p = root;
	while (p != null) {
		if ((p -> v).first < s[x]) res = max(max(p -> c[0] -> mv, (p -> v).second) + 1, res), p = p -> c[1];
		else p = p -> c[0];
	}
	p = root;
	while (p != null) {
		if ((p -> v).first > s[x]) res = max(max(p -> c[1] -> mv, (p -> v).second) - 1, res), p = p -> c[0];
		else p = p -> c[1];
	}
	if (!ss[s[x]].empty()) res = max(res, (*ss[s[x]].begin()));
	return res;
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin >> n >> l >> r; s[0] = n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i], s[i] = s[i - 1] + a[i];
		dp[i] = -inf;
	}
	int st = 0, en = 0;
	for (int i = l; i <= n; i ++) {
		while ((i - en) >= l) add(en ++);
		while ((i - st) >  r) rem(st ++);
		if (root -> siz == 0) continue;
		dp[i] = ask(i);
	}
	if (dp[n] == -inf) puts("Impossible");
	else printf("%d\n", dp[n]);
	return 0;
}