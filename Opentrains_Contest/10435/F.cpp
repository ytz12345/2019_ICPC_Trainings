#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll t, n;

struct node {
	ll l, r, s;
}tr[2019];

int cnt;

map <ll, int> p;

int build(ll x) {
	if (p.find(x) != p.end()) return p[x];
	int l = build((x + 1) / 2), r = build(x - (x + 1) / 2);
	tr[++ cnt] = (node){l, r, tr[l].s + tr[r].s};
	return p[x] = cnt; 
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n, cnt = 0;
		p.clear(), p[1] = 0;
		tr[0] = (node){-1, -1, 1};
		int r = build(n);
		cout << r + 1 << '\n';
		for (int i = 0; i <= r; i ++)
			cout << tr[i].l << ' ' << tr[i].r << '\n';
		cout << r << '\n';
	}	
	return 0;
}