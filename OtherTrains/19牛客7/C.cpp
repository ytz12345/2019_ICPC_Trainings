#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const int poolSize = 5e5 + 10;

struct tree {
	ll h, c, p;
}t[N];

struct node {
	node *c[2];
	int r;
	ll v, sv, siz, num;
	void update();
	void init(int x);
};

node *null = new node(), *root;

void node::update() {
	siz = c[0] -> siz + c[1] -> siz + num;
	sv = c[0] -> sv + c[1] -> sv + v * num;
}

void node::init(int x) {
	v = t[x].c, r = rand(), siz = num = t[x].p, sv = v * num;
	c[0] = c[1] = null;
}

node nodesPool[poolSize];

int head;

node *newnode(int x) {
	node *res = &nodesPool[head ++];
	res -> init(x);
	return res;
}

void rot(node *&o, int d) {
	node *tmp = o -> c[!d];
	o -> c[!d] = tmp -> c[d], tmp -> c[d] = o;
	o -> update(), tmp -> update(), o = tmp;
}

void insert(node *&o, int x) {
	if (o == null) {
		o = newnode(x);
		return;
	}
	int d = t[x].c < o -> v ? 0 : 1;
	insert(o -> c[d], x);
	if (o -> c[d] -> r < o -> r) rot(o, !d);
	o -> update();
}

ll ask(node *o, ll k) {
	ll res = 0;
	while (o != null && k > 0) {
		if (o -> c[0] -> siz + o -> num <= k) {
			res += o -> c[0] -> sv + o -> num * o -> v;
			k -= o -> c[0] -> siz + o -> num;
			o = o -> c[1];
		}
		else if (o -> c[0] -> siz <= k) {
			res += o -> c[0] -> sv + o -> v * (k - o -> c[0] -> siz);
			break;
		}
		else {
			o = o -> c[0];
		}
	}
	return res;
}

int n;

ll sv[N];

int main() {
	srand(time(NULL));
	while (scanf("%d", &n) != EOF) {
		head = 0, root = null;
		for (int i = 0; i < n; i ++) 
			scanf("%lld %lld %lld", &t[i].h, &t[i].c, &t[i].p);
		sort (t, t + n, [&](tree a, tree b) {
			return a.h < b.h;
		});	
		sv[n - 1] = t[n - 1].c * t[n - 1].p;
		for (int i = n - 2; i >= 0; i --) {
			sv[i] = sv[i + 1] + t[i].c * t[i].p;
		}
		ll sum, ans = 1e18;
		for (int j, i = 0; i < n; ) {
			sum = t[i].p;
			j = i + 1; 
			while (j < n && t[j].h == t[i].h) sum += t[j].p, j ++;
			if (root -> siz < sum) ans = min(ans, sv[j]);
			else ans = min(ans, sv[j] + ask(root, root -> siz - (sum - 1)));
			while (i < j) insert(root, i ++);
		}
		cout << ans << '\n';
	}
	return 0;
}