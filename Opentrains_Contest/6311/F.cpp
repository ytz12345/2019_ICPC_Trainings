#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], b[N], c[N];

int m, st[N], l[N];

struct OP{char op; int l, r;};

vector <OP> ans;

inline int print(char op, int l, int r, int calc = 0) {
	static int res;
	ans.push_back((OP){op, l, r});
	if (!calc) return 0;
	res = op == 'm' ? 1e9 : 0;
	for (int i = l; i <= r; i ++) res = op == 'm' ? min(res, a[i]) : max(res, a[i]);
	return res;
}

inline void print() {
	printf("%d\n", int(ans.size()));
	for (auto i : ans)
		printf("%c %d %d\n", i.op, i.l, i.r);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; int val;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> b[i];
	for (int i = 1; i <= n; i ++)
		if (b[i] != b[i - 1]) 
			c[++ m] = b[i], st[m] = i; 
	for (int i = 1, j = 1; i <= n; i ++) {
		if (a[i] == c[j]) l[j] = i, j ++;
		if (i == n && j <= m) return puts("-1"), 0;
	}
	if (l[1] != 1) 
		print(print('m', 1, l[1] - 1, 1) < c[1] ? 'M' : 'm', 1, l[1]), l[1] = 1;
	l[m + 1] = n + 1;
	for (int i = 1; i <= m; i ++)
		if (l[i] + 1 != l[i + 1])
			print(print('m', l[i] + 1, l[i + 1] - 1, 1) < c[i] ? 'M' : 'm', l[i], l[i + 1] - 1);  
	for (int i = m - 1; i; i --) 
		print(c[i] > c[i + 1] ? 'M' : 'm', l[i], n - m + i);
	for (int i = 2; i <= m; i ++)
		print(c[i] > c[i - 1] ? 'M' : 'm', st[i], n - m + i);
	print();
}