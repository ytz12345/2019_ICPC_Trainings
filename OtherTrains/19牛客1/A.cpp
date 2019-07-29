#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tr[2][N << 2], M;

int n, a[2][N];

__int128 x;

int mmin(int k, int i, int j) {
	return a[k][i] < a[k][j] ? i : j;
}

int ask(int *te, int k, int s, int t) {
	int res = 0;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = mmin(k, res, te[s ^ 1]);
		if ( t&1) res = mmin(k, res, te[t ^ 1]);
	}
	return res;
}

bool check(int l, int r) {
	int p1 = ask(tr[0], 0, l, r);
	int p2 = ask(tr[1], 1, l, r);
	if (p1 != p2) return 0;
	if (p1 != l) {
		if (!check(l, p1 - 1)) return 0;
	}
	if (p1 != r) {
		if (!check(p1 + 1, r)) return 0;
	}
	return 1;
}

bool judge(int k) {
	return check(1, k);
}

int main() {
	ios::sync_with_stdio(false);
	a[0][0] = a[1][0] = 1e9;
	while (cin >> n) {
		for (int i = 1; i <= n; i ++) cin >> a[0][i];
		for (int i = 1; i <= n; i ++) cin >> a[1][i];
		for (M = 1; M < n + 2; M <<= 1);
		for (int i = 0; i < 2; i ++)
			for (int j = 0; j < (M << 1) + 5; j ++)
				tr[i][j] = 0;
		for (int i = 1; i <= n; i ++)
			tr[0][i + M] = tr[1][i + M] = i;
		for (int i = M - 1; i > 0; i --) {
			for (int j = 0; j < 2; j ++)
				tr[j][i] = mmin(j, tr[j][i << 1], tr[j][i << 1 | 1]);
		}
		int l = 1, r = n, mid, ans = 1;
		while (l <= r) {
			mid = l + r >> 1;
			if (judge(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}