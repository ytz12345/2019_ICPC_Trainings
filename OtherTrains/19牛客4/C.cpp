#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e6 + 6;

const int NN = 8400000;

int n;

ll ans;

ll a[N], b[N];

int M, T[NN];

queue <int> ql, qr;

struct node {
	ll lmin, lmax, rmin, rmax, sum;
}tr[NN];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1)

int mmin(int i, int j) {
	return a[i] < a[j] ? i : j; 
}

const int SIZE = 1 << 20;
inline int get_char() {
	static char *S, *T, buf[SIZE];
	if (S == T) {
		T = fread(buf, 1, SIZE, stdin) + (S = buf);
		if (S == T) return -1;
	}
	return *S ++;
}

int getint() {
	static int flag, res, ch; 
	while (ch = get_char(), ch < '0' && ch > '9' && ch != '-');
	if (ch == '-') flag = 1, res = 0;
	else flag = 0, res = ch - '0';
	while (ch = get_char(), ch >= '0' && ch <= '9') res = res * 10 + ch - '0';
	if (flag) res = -res;
	return res;
}

void update(node &o, node ls, node rs) {
	o.lmin = min(ls.lmin, ls.sum + rs.lmin);
	o.rmin = min(rs.rmin, rs.sum + ls.rmin);
	o.lmax = max(ls.lmax, ls.sum + rs.lmax);
	o.rmax = max(rs.rmax, rs.sum + ls.rmax);
	o.sum = ls.sum + rs.sum;
}

void build(int o, int l, int r) {
	if (l == r) {
		tr[o].lmax = tr[o].rmax = max(b[r], 0ll);
		tr[o].lmin = tr[o].rmin = min(b[r], 0ll);
		tr[o].sum = b[r];
		return;
	}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	update(tr[o], tr[lc], tr[rc]);
}

node query(int o, int l, int r, int s, int t) {
	if (s <= l && r <= t) return tr[o];
	if (t <= mid) return query(lc, l, mid, s, t);
	if (s >  mid) return query(rc, mid + 1, r, s, t);
	node res; 
	update(res, query(lc, l, mid, s, t), query(rc, mid + 1, r, s, t));
	return res;
}

int ask(int s, int t) {
	int res = 0;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = mmin(res, T[s ^ 1]);
		if ( t&1) res = mmin(res, T[t ^ 1]); 
	}
	return res;
}

int main() {
	n = getint();
	for (int i = 1; i <= n; i ++)
		a[i] = getint();
	for (int i = 1; i <= n; i ++)
		b[i] = getint();

	//cout << clock () << endl;

	a[0] = 1e9;
	for (M = 1; M < n + 2; M <<= 1);
	for (int i = 1; i <= n; i ++)
		T[i + M] = i;
	for (int i = M - 1; i > 0; i --)
		T[i] = mmin(T[i << 1], T[i << 1 | 1]); 

	build(1, 1, n);

	int l, r, p;
	node t1, t2;
	ql.push(1), qr.push(n);
	while (!ql.empty()) {
		l = ql.front(), r = qr.front();
		ql.pop(), qr.pop();
		p = ask(l, r);
		t1 = query(1, 1, n, l, p);
		if (p != r) t2 = query(1, 1, n, p + 1, r);
		else        t2 = (node){0, 0, 0, 0, 0};
		
		//cout << l << ' ' << r << ' ' << t2
		ans = max(ans, max(a[p] * (t1.rmax + t2.lmax), a[p] * (t1.rmin + t2.lmin)));

		if (l <= p - 1) ql.push(l), qr.push(p - 1);
		if (p + 1 <= r) ql.push(p + 1), qr.push(r);
	}

	cout << ans << endl;
	//cout << clock() << endl;
	return 0;
}