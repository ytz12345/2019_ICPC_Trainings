#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int sg[N], c[N], a[N];

int n, tr[N << 2];

void update(int o, int l, int r, int x, int p) {
	if (l == r) {tr[o] = p; return;}
	int mid = l + r >> 1;
	if (x <= mid) update(o << 1, l, mid, x, p);
	else update(o << 1 | 1, mid + 1, r, x, p);
	tr[o] = min(tr[o << 1], tr[o << 1 | 1]);
}

int ask(int o, int l, int r, int p, int x) {
	if (l == r) return r;
	int mid = l + r >> 1;
	if (p <= mid) return ask(o << 1, l, mid, p, x);
	if (tr[o << 1] < x) return ask(o << 1, l, mid, p, x);
	return ask(o << 1 | 1, mid + 1, r, p, x);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; int ans = 0;
	for (int i = 1; i < n; i ++)
		cin >> c[i] >> a[i];
	memset (tr, -1, sizeof tr);
	sg[0] = 0; update(1, 0, n - 1, sg[0], 0);
	for (int i = 1; i < n; i ++) {
		sg[i] = ask(1, 0, n - 1, c[i], i - c[i]);
		update(1, 0, n - 1, sg[i], i);
		if (a[i] & 1) ans ^= sg[i];
	}
	puts(ans ? "First" : "Second");
	return 0;
}