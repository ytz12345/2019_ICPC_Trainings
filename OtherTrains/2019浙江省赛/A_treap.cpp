#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int get_char() {
	static const int SIZE = 1 << 20;
	static char *S, *T = S, buf[SIZE];
	if (S == T) {
		T = fread(buf, 1, SIZE, stdin) + (S = buf);
		if (S == T) return -1;
	}
	return *S ++;
}

inline void in(int &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

inline void in(ll &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

const int N = 1e5 + 5;

const int poolSize = 5e5 + 10;

int t, n, m;

ll calc(ll x) {
	return x * (x - 1) / 2;
}

struct node {
	node *c[2];
	int v, r, siz;
	ll sv, sm, sum;
	void update();
	void init(int x);
};

node *null = new node(), *root = null;

void node::update() {
	siz = c[0] -> siz + c[1] -> siz + 1;
	sv = c[0] -> sv + c[1] -> sv + v;
	sum = c[0] -> sum + c[1] -> sum + sm;
}

void node::init(int x) {
	v = x, r = rand(), siz = 1;
	c[0] = c[1] = null;
	sv = x, sum = sm = calc(x);
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
	int d = x > o -> v ? 0 : 1;
	insert(o -> c[d], x);
	if (o -> c[d] -> r < o -> r) rot(o, !d);
	o -> update();
}

void del(node *&o, int x) {
	if (x == o -> v) {
		if (o -> c[0] == null) {o = o -> c[1]; return;}
		if (o -> c[1] == null) {o = o -> c[0]; return;}
		int d = o -> c[0] -> r < o -> c[1] -> r ? 1 : 0;
		rot(o, d), del(o -> c[d], x);
	}
	else del(o -> c[x <= o -> v], x);
	o -> update();
}

int f[N], s[N];

int fa(int x) {
	return x == f[x] ? x : (f[x] = fa(f[x]));
}

int ask(node *o, ll k) {
	int res = 0, cnt = 0; ll s1 = 0;
	if (calc(o -> sv) - o -> sum <= k) return o -> siz;
	while (o != null) {
		if (calc(cnt + o -> c[0] -> sv) - o -> c[0] -> sum - s1 >= k) o = o -> c[0];
		else if (calc(cnt + o -> c[0] -> sv + o -> v) - o -> c[0] -> sum - o -> sm - s1 >= k) {
			return res + o -> c[0] -> siz + 1;
		}
		else {
			cnt += o -> c[0] -> sv + o -> v;
			s1 += o -> c[0] -> sum + o -> sm;
			res += o -> c[0] -> siz + 1;
			o = o -> c[1];
		} 
	}
}

void build(node *&o, int l, int r) {
	o = newnode(1);
	if (l == r) return;
	int mid = l + r >> 1;
	if (l < mid) build(o -> c[0], l, mid - 1);
	if (o -> c[0] != null && o -> c[0] -> r < o -> r) swap(o -> c[0] -> r, o -> r);
	if (mid < r) build(o -> c[1], mid + 1, r);
	if (o -> c[1] != null && o -> c[1] -> r < o -> r) swap(o -> c[1] -> r, o -> r);
	o -> update();
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	in(t); int op, u, v, fu, fv;
	ll k; ll sum, cnt = 0;
	while (t --) {
		head = 0;
		in(n), in(m), root = null, sum = 0, cnt = n;
		for (int i = 1; i <= n; i ++)
			f[i] = i, s[i] = 1;
		build(root, 1, n);
		for (int i = 1; i <= m; i ++) {
			in(op);
			if (op == 1) {
				in(u), in(v);
				fu = fa(u), fv = fa(v);
				if (fu == fv) {
					sum --;
					continue;
				}
				else {
					cnt --;
					del(root, s[fu]);
					del(root, s[fv]);
					f[fu] = fv;
					sum += 1ll * s[fu] * s[fv] - 1;
					s[fv] += s[fu];
					insert(root, s[fv]);
				}
			}
			else {
				in(k);
				printf("%lld ", max(1ll, cnt - k));
				k -= sum;
				if (k <= 0) printf("%lld\n", cnt);
				else {
					printf("%lld\n", cnt - ask(root, k) + 1);
				}
			}
		}
	}
	return 0;
}