#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int n, m, k;

int tr[N], M;

int ask(int s, int t) {
	int res = 1e9;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = min(res, tr[s ^ 1]);
		if ( t&1) res = min(res, tr[t ^ 1]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> s) {
		k = 0;
		for (M = 1; M < n + 2; M <<= 1);
		for (int i = 1; i <= n; i ++) {
			k += s[i - 1] == '(' ? 1 : -1;
			tr[i + M] = k;
		}
		for (int i = n + 1; i <= M + 1; i ++)
			tr[i + M] = 1e9;
		for (int i = M; i >= 1; i --) 
			tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
		for (int l, r; m --; ) {
			cin >> l >> r;
			if (l > r) swap(l, r);
			if (s[l - 1] == '(' && s[r - 1] == ')' && ask(l, r - 1) < 2) puts("No");
			else puts("Yes");
		}
	}
}