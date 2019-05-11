#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int n, m, c[N];

char pre[N][N], last[N];

int len[N], a[N], b, ans;

string t;

int work() {
	int s = m, now, ret = 0;
	for (int i = 0; s > 0; i ++) {
		now = i % n, c[i] = min(c[i], s), s -= c[i];
		int p1 = b, p2 = a[now], flag = 0;
		char c1, c2;
		while (p1 >= 0 && p2 >= 0) {
			if (last[p1] != pre[now][p2]) {
				c1 = last[p1], c2 = pre[now][p2];
				last[++ b] = c2;
				pre[now][++ a[now]] = c1; 
				flag = 1;
				break;
			}
			p1 --, p2 --;
		}
		if (!flag) last[++ b] = 'W', pre[now][++ a[now]] = 'B';
		if (c[i] != 1) last[b + 1] = pre[now][a[now]], pre[now][a[now] + 1] = last[b], b ++, a[now] ++;
	}
	for (int i = 0; i < m; i ++)
		ret += last[i] == 'W';
	return ret;
}

int main() {
	//#define ONLINE_JUDGE
	#ifndef ONLINE_JUDGE
		freopen("checkers.in","r",stdin);
		freopen("checkers.out","w",stdout);
	#endif
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> t, len[i] = -1;
		for (int j = max((int)(t.size()) - 20, 0); j < t.size(); j ++)
			pre[i][++ len[i]] = t[j];
	}
	for (int i = 0, tp = 1 << m; i < tp; i ++) {
		for (int j = 0; j < n; j ++)
			a[j] = len[j];
		for (int j = 0; j < m; j ++) 
			c[j] = ((i >> j) & 1) + 1;
		b = -1, ans = max(ans, work());
	}
	cout << ans;
	return 0;
}