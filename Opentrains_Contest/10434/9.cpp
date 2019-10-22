#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

#define mid (l + r >> 1)

struct node{
	ll sum, cnt;
	int ls, rs;
}tr[N * 55];

inline ll getint(bool isFloat = true) {
	static double x; cin >> x;
	return isFloat ? x * 1e6 + 0.5 : x + 0.5;
}

ll n, nn, py;

int tot, root;

void add(int &o, ll l, ll r, ll s, ll t, int id) {
	if (o == 0) o = ++ tot;
	if (s <= l && r <= t) {
		tr[o].sum += id;
		tr[o].cnt ++;
		return;
	}
	if (s <= mid) add(tr[o].ls, l, mid, s, t, id);
	if (t >  mid) add(tr[o].rs, mid + 1, r, s, t, id);
}

int ask(int o, ll l, ll r, ll p) {
	if (o == 0) return 0;
	py = (py + tr[o].sum) % n;
	return (l == r ? 0 : (p <= mid ? ask(tr[o].ls, l, mid, p) : ask(tr[o].rs, mid + 1, r, p))) +
		tr[o].cnt;
}

int main() {
	ios::sync_with_stdio(false);
	n = getint(0), nn = n * 1000000;
	for (ll op, c, r, id = 0, i = 0; i < n * 2; i ++) {
		op = getint(0), c = (getint() + py * 1000000) % nn, c += nn + 1;
		if (op == 0) r = getint(), add(root, 1, nn * 3, c - r, c + r, id ++);
		else printf("%d\n", ask(root, 1, nn * 3, c));
	}
	return 0;
}