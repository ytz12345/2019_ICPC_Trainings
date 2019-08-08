#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4e5 + 2019;

const int inf = 1e9 + 7;

struct seg{
	int l,r;
}sg[N << 1];

struct node {
	int l, r, siz, len;
	ll cnt, sum, lazy;
	node *c[2];
	void mata() {
		siz = c[0] -> siz + c[1] -> siz + 1;
		len = c[0] -> len + c[1] -> len + r - l + 1;
		sum = c[0] -> sum + c[1] -> sum + cnt * (r - l + 1);
	}
	int cmp(int k) {
		return k <= c[0] -> siz ? 0 : (k == c[0] -> siz + 1 ? -1 : 1);
	}
	void init(int l, int r, ll cnt);
	void pushdown();
}pool[N * 2 + 2019], *null = new node(), *root;

int head;

void node::init(int _l, int _r, ll _cnt) {
	lazy = 0, cnt = _cnt, l = _l, r = _r;
	siz = 1, len = r - l + 1, sum = cnt * len;
	c[0] = c[1] = null;
}

void node::pushdown() {
	if (!lazy) return;
	if (c[0] != null) {
		c[0] -> cnt += lazy;
		c[0] -> lazy += lazy;
		c[0] -> sum += lazy * c[0]->len;
	}
	if (c[1] != null) {
		c[1] -> cnt += lazy;
		c[1] -> lazy += lazy;
		c[1] -> sum += lazy * c[1]->len;
	}
	lazy = 0;
}

void getLKth(node *&tmp, ll &pos, int L) {
	node *o = root; pos = 0; int temp = 0;
	while (o != null) {
		o -> pushdown();
		if (o -> l <= L) pos = temp + o -> c[0] -> siz + 1, temp += o -> c[0] -> siz + 1, tmp = o, o = o -> c[1];
		else o = o -> c[0];
	}
}

void getRKth(node *&tmp, ll &pos, int R) {
	node *o = root; pos = 0;int temp = 0;
	while (o != null) {
		o -> pushdown();
		if (o -> r >= R) pos = temp + o -> c[0] -> siz + 1, tmp = o, o = o -> c[0];
		else temp += o -> c[0] -> siz + 1, o = o -> c[1];
	}
}

void rot(node *&o, int k) {
	o -> pushdown(); node *tmp = o -> c[k];
	tmp -> pushdown(); o -> c[k] = tmp -> c[!k];
	tmp -> c[!k] -> pushdown(); tmp -> c[!k] = o;
	o -> mata(), tmp -> mata(), o = tmp;
}

void splay(node *&o, int k) {
	int k1 = o -> cmp(k); o -> pushdown();
	if (k1 == -1) return; o -> c[k1] -> pushdown();
	if (k1) k -= o -> c[0] -> siz + 1;
	int k2 = o -> c[k1] -> cmp(k);
	if (~k2) {
		if (k2) k -= o -> c[k1] -> c[0] -> siz + 1;
		o -> c[k1] -> c[k2] -> pushdown();
		splay(o -> c[k1] -> c[k2], k);
		if (k2 == k1) rot(o, k1);
		else rot(o -> c[k1], k2);	
	}
	rot(o, k1);
}

int ask(node *o, ll k) {
	while (1) {
		o -> pushdown();
		//printf("%d %d %lld\n", o ->l,o->r,k);
		if (o -> c[0] -> sum + o -> cnt * (o -> r - o -> l + 1) < k) {
			k -= o -> c[0] -> sum + o -> cnt * (o -> r - o -> l + 1);
			o = o -> c[1];
		}
		else if (o -> c[0] -> sum < k) {
			k -= o -> c[0] -> sum;
			break;
		}
		else o = o -> c[0];
	}
	return o -> l + (k / (o -> cnt)) - (k % (o -> cnt) == 0); 
}

node* newnode(int l, int r, ll cnt) {
	node *res = &pool[head ++];
	res -> init(l, r, cnt);
	return res;
}

node *build(int l, int r) {
	if (l == r) {
		//printf("%d %d %d\n", r, sg[r].l, sg[r].r);
		return newnode(sg[r].l, sg[r].r, 0);
	}
	int mid = l + r >> 1;
	//printf("%d %d %d\n", r, sg[mid].l, sg[mid].r);
	node *tmp = newnode(sg[mid].l, sg[mid].r, 0);
	if (l < mid) tmp -> c[0] = build(l, mid - 1);
	if (mid < r) tmp -> c[1] = build(mid + 1, r);
	tmp -> mata(); return tmp;
}

void work(int L, int R) {
	static ll siz, posl, posr, ll, rr; 
	static node *tmp;

	getLKth(tmp, posl, L);
	getRKth(tmp, posr, R);
	
	splay(root, posr + 1);
	//printf("%d %d\n", root ->l,root->r);
	splay(root -> c[0], posl - 1);
	root -> c[0] -> c[1] -> lazy ++;
	root -> c[0] -> c[1] -> cnt ++;
	root -> c[0] -> c[1] -> sum += root -> c[0] -> c[1] -> len;
	root -> c[0] -> c[1] -> pushdown();
	root -> c[0] -> c[1] -> mata();
	root -> c[0] -> mata();
	root -> mata(); 

	siz = root -> sum;
	//printf("%lld\n", siz);
	printf("%d\n", ask(root, (siz + 1) / 2));
	//root -> print();
}

int n;

ll X[N], Y[N], A[N], B[N], C[N], M[N], L[N], R[N];

int cnt, pt[N << 1];

int main() {
	cin >> n;
	root = newnode(-1, -1, 0);
	root -> c[1] = newnode(0, inf, 0);
	root -> c[1] -> c[1] = newnode(inf + 1, inf + 1, 0);
	root -> c[1] -> c[1] -> mata();
	root -> c[1] -> mata();
	root -> mata();
	cin >> X[0] >> X[1] >> A[0] >> B[0] >> C[0] >> M[0];
	cin >> Y[0] >> Y[1] >> A[1] >> B[1] >> C[1] >> M[1];
	for (int i = 0; i < n; i ++) {
		if (i >= 2) {
			X[i] = (A[0] * X[i - 1] + B[0] * X[i - 2] + C[0]) % M[0];
			Y[i] = (A[1] * Y[i - 1] + B[1] * Y[i - 2] + C[1]) % M[1];
		}
		L[i] = min(X[i], Y[i]) + 1;
		R[i] = max(X[i], Y[i]) + 1;

		pt[cnt ++] = L[i] - 1;
		pt[cnt ++] = R[i];
	}

	pt[cnt ++] = -1;
	pt[cnt ++] = inf;

	sort (pt, pt + cnt);
	cnt = unique(pt, pt + cnt) - pt;

	for (int i = 1; i < cnt; i ++) 
		sg[i] = (seg){pt[i - 1] + 1, pt[i]};

	sg[0] = (seg){-1, -1};
	sg[cnt] = (seg){inf + 1, inf + 1};
	root = build(0, cnt);

	for (int i = 0; i < n; i ++)
		work(L[i], R[i]);

	//printf("%d\n", clock());
	return 0;
}