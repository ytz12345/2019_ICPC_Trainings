#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, m;

char s[N], t[N];

int tot;

struct edge{
	int to, next;
}e[N + 2019];

int head[26];

void add(int u, int v) {
	e[++ tot] = (edge){v, head[u]}, head[u] = tot;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d %d %s %s", &n, &m, s + 1, t + 1);
	for (int i = 0; i < 26; i ++) add(i, n + 1);
	for (int i = n; i >= 1; i --) add(s[i] - 'a', i);
	int last = 0, ans = -1;
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j < 26; j ++) 
			while (e[head[j]].to <= last) head[j] = e[head[j]].next;
		if (t[i] != 'z') {
			int pos = n + 1;
			for (int j = t[i] - 'a' + 1; j < 26; j ++)
				pos = min(pos, e[head[j]].to);
			if (pos <= n) ans = max(ans, i - 1 + n - pos + 1);
		}
		do {last ++;} while (last <= n && s[last] != t[i]);
		if (last > n) break;
	}
	if (last < n) ans = max(ans, m + n - last);
	cout << ans << '\n';
	return 0;
}