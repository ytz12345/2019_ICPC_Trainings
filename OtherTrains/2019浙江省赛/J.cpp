#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int t, n;

int m, ans, b[N], c[N], d[N];

int vis[N];

struct node {
	int id, bel;

	bool operator < (const node &a) const {
		return id > a.id;
	}
};

priority_queue <int, vector<int>, greater<int> > a[N];

priority_queue <node> q;

vector <int> e[N];

inline int get_char() {
	static const int SIZE = 1 << 20;
	static char *S, *T = S, buf[SIZE];
	if (S == T) {
		T = fread(buf, 1, SIZE, stdin) + (S = buf);
		if (S == T) return -1;
	}
	return *S ++;
}

inline void in(int &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

void work(int st) {
	static queue <int> qq;
	while (!qq.empty()) qq.pop();
	q.push((node){st, st});
	vis[st] = c[st] = 1, qq.push(st);
	while (!qq.empty()) {
		int now = qq.front(); qq.pop();
		for (int u : e[now])
			if (!vis[u])
				qq.push(u), vis[u] = 1;
	} 
}

int main() {
	ios::sync_with_stdio(false);
	in(t);
	while (t --) {
		in(n), in(m);
		ans = 0;
		for (int i = 1; i <= n; i ++) 
			e[i].clear(), b[i] = 1e9, c[i] = vis[i] = 0; 
		for (int u, v, i = 1; i <= m; i ++) {
			in(u), in(v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i = 1; i <= n; i ++)
			if (!vis[i])
				work(i), ans ++;
		printf("%d\n", ans);
		for (int j, i = 1; i <= n; i ++) {
			d[i] = q.top().id;
			j = q.top().bel; q.pop();
			for (int v : e[d[i]])
				if (!c[v])
					a[j].push(v), c[v] = 1;
			if (a[j].empty()) continue;
			q.push((node){a[j].top(), j});
			a[j].pop();
		}
		for (int i = 1; i <= n; i ++)
			printf("%d%c", d[i], i == n ? '\n' : ' ');
	}
	return 0;
}