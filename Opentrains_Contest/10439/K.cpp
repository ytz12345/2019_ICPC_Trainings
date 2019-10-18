#include <bits/stdc++.h>

using namespace std;

const int N = 2019;

int n, rt, sum;

int s[N][2];

int f[N], dep[N];

char c[N];

int son[N], len[N], top[N];

void dfs(int u) {
	dep[u] = 1;
	if (s[u][0] != 0) {
		dfs(s[u][0]);
		if (dep[u] < dep[s[u][0]] + 1)
			dep[u] = dep[s[u][0]] + 1, son[u] = s[u][0];
	}
	if (s[u][1] != 0) {
		dfs(s[u][1]);
		if (dep[u] < dep[s[u][1]] + 1)
			dep[u] = dep[s[u][1]] + 1, son[u] = s[u][1];
	}
}

void dfs(int u, int tp) {
	top[u] = tp;
	if (son[u]) dfs(son[u], tp);
	if (s[u][0] != 0 && s[u][0] != son[u]) dfs(s[u][0], s[u][0]);
	if (s[u][1] != 0 && s[u][1] != son[u]) dfs(s[u][1], s[u][1]);
}

void work(int u, int cnt) {
	if (dep[u] < cnt) {
		puts("Impossible");
		exit(0);
	}
	int len = 0, leaf;
	for (int i = u; i != 0; i = son[i]) leaf = i, len ++;
	if (len == cnt) for (int i = u; i != 0; i = son[i]) c[i] = 'B';
	else {
		c[leaf] = 'R', len --, leaf = f[leaf];
		for (int i = len - cnt; i > 0; i --) {
			c[leaf] = 'B', leaf = f[leaf];
			c[leaf] = 'R', leaf = f[leaf];
		}
		for (int i = cnt - (len - cnt); i > 0; i --) 
			c[leaf] = 'B', leaf = f[leaf];
	}
}

void redfs(int u, int cnt) {
	if (top[u] == u) work(u, sum - cnt);
	if (s[u][0] != 0) redfs(s[u][0], cnt + (c[u] == 'B'));
	if (s[u][1] != 0) redfs(s[u][1], cnt + (c[u] == 'B'));
}

int judge(int u, int cnt) {
	//printf("%d %d %d %d\n", u, s[u][0], s[u][1], cnt);
	if (u == 0) {
		if (cnt != sum) return 0;
		return 1;
	}
	if (!judge(s[u][0], cnt + (c[u] == 'B')) || !judge(s[u][1], cnt + (c[u] == 'B'))) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; 
	for (int i = 1; i <= n; i ++) {
		cin >> f[i];
		if (f[i] == 0) rt = i;
		else {
			if (s[f[i]][0] == 0) s[f[i]][0] = i;
			else                 s[f[i]][1] = i;
		} 
	}
	dfs(rt), dfs(rt, rt);
	sum = dep[rt] / 2;
	redfs(rt, 0);
	if (!judge(rt, 0)) {
		puts("Impossible");
		exit(0);
	}
	c[n + 1] = 0;
	puts(c + 1);
}