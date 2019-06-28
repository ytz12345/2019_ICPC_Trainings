#include <bits/stdc++.h>

using namespace std;

namespace my_hash {
	const int N = (1 << 20) - 1;
	struct E {
		int v;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;
	int vis[N + 1], T;
	void ins(int v) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return;
		p = cur ++; p -> v = v; p -> nxt = g[u]; g[u] = p;
	}
	int ask(int v) {
		int u = v & N;
		if (vis[u] < T) return 0;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return 1;
		return 0;
	}
	void init() {T ++; cur = pool;}
}

const int N = 50010;

int n, m, k;

struct group {
	int n, a, b;
	vector <int> s;
}a[N];

int f(char *str) {
	int res = 0;
	for (; *str; str ++)
		res = res * 27 + (*str) - 'a' + 1;//, printf("%c %d\n",*str, res);;
	return res;
}

void dfs(char *str, int x) {
	if (*str == 0) {
		my_hash::ins(x);
		return;
	}
	dfs(str + 1, x);
	dfs(str + 1, x * 27 + (*str) - 'a' + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; char tmp[10];
	for (int i = 0; i < n; i ++) {
		cin >> a[i].n; a[i].a = 0, a[i].b = -1;
		for (int j = 0; j < a[i].n; j ++) {
			cin >> tmp;
			sort (tmp, tmp + strlen(tmp));
			a[i].s.push_back(f(tmp));
			//printf("%s %d\n", tmp, f(tmp));
		}
	}
	cin >> m;
	for (int k, i = 0; i < m; i ++) {
		my_hash::init();
		for (cin >> k; k --; ) {
			cin >> tmp;
			sort (tmp, tmp + strlen(tmp));
			//printf("%d %s\n", i, tmp);
			dfs(tmp, 0);
		}
		for (int j = 0; j < n; j ++) {
			int cnt = 0;
			for (k = 0; k < a[j].n; k ++) {
				cnt += my_hash::ask(a[j].s[k]);
			}
			//printf("%d %d %d\n", i, j, cnt);
			if (cnt > a[j].b) a[j].b = cnt, a[j].a = i + 1;
		}
	}
	for (int i = 0; i < n; i ++)
		printf("%d\n", a[i].a);
	return 0;
}	