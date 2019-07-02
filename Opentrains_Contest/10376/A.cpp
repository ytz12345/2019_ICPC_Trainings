#include <bits/stdc++.h>

using namespace std;

const int N = 310;

char str[N];

int n;

stack <char> s;

struct node {
	int l, r, v, c;
}a[N];

int c[N];

int cmp(const node &x) {
	if (x.r == 0) return -2;
	if (x.l == 0) return 2;
	if (x.l >  x.r) return -1;
	if (x.l == x.r) return 0;
	return 1; 
}

int dp[2][N * N];

void upd(int &x, int y) {
	x = max(x, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> str;
		for (int j = 0, l = strlen(str); j < l; j ++) {
			if (str[j] == '(') s.push(str[j]);
			else if (!s.empty() && s.top() == '(') s.pop();
			else s.push(str[j]);
		}
		while (!s.empty()) {
			if (s.top() == '(') a[i].l ++;
			else a[i].r ++;
			s.pop();
		}
		a[i].v = strlen(str);
		a[i].c = cmp(a[i]);
	}
	sort (a + 1, a + n + 1, [&](node x, node y) {
		if (x.c != y.c) return x.c < y.c;
		if (x.c < 0) return x.r < y.r;
		return x.r > y.r;
	});
	memset (dp[0], -1, sizeof dp[0]);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		memset (dp[i&1], -1, sizeof dp[i&1]);
		for (int j = 0; j < N * N; j ++) {
			if (dp[!(i&1)][j] == -1) continue;
			if (j >= a[i].r) 
				upd(dp[i&1][j - a[i].r + a[i].l], dp[!(i&1)][j] + a[i].v);
		}
		for (int j = 0; j < N * N; j ++)
			upd(dp[i&1][j], dp[!(i&1)][j]);
	}
	cout << dp[n&1][0] << endl;
	return 0;
}