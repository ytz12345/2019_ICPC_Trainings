#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, ld, ner[N];
vector <int> e[N], f[N];
int vis[N], pre[N], ans, tim;
bool dfs(int u) {
	if (vis[u] == tim) return 0;
	vis[u] = tim;
	for (int v : f[u]) 
		if (!pre[v] || dfs(pre[v])) 
			return pre[v] = u, 1;
	return 0;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int u, v, i = 1; i <= m; i ++) {
		scanf("%d %d", &u, &v);
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for (int i = 1; i <= n; i ++) {
		if (e[i].size() < n / 2) continue;
		memset (ner, 0, sizeof ner);
		memset (pre, 0, sizeof pre);
		ner[ld = i] = 1;
		int c1 = n - 1, c2 = 0;
		for (int j : e[ld])
			ner[j] = 1, c1 --;
		for (int j = 1; j <= n; j ++) {
			f[j].clear();
			if (ner[j]) continue;
			for (int k : e[j])
				if (k != ld && ner[k])
					f[j].push_back(k);
		}
		for (int j = 1; j <= n; j ++) {
			if (ner[j]) continue;
			tim ++, c2 += dfs(j);
		}
		if (c1 != c2) continue;
		memset (vis, 0, sizeof vis);
		printf("Yes\n%d %d\n", ld, n - 1 - c1), vis[ld] = 1;
		for (int j = 1; j <= n; j ++) 
			if (j != ld && ner[j])
				printf("%d %d\n", j, pre[j] ? pre[j] : -1);
		return 0;
	}
	puts("No");
 	return 0;
}