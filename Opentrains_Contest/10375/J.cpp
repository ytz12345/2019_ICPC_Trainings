#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, q;

vector <int> e[N];

int root[N], fa[N];

int siz[N], top[N], son[N], dep[N];

int tim, flag[N];

void bfs(int rt) {
	static int q[N];
	static int head, tail, u;
	head = 1, tail = 0;
	q[++ tail] = rt, root[rt] = rt;
	while (head <= tail) {
		u = q[head ++];
		siz[u] = 1;
		for (int v : e[u]) {
			if (!root[v]) {
				root[v] = rt, fa[v] = u, dep[v] = dep[u] + 1, q[++ tail] = v;
			}
 		}
	}
	for (int j, i = tail; i > 1; i --) {
		j = q[i];
		siz[fa[j]] += siz[j];
	}
	for (int j, i = tail; i > 0; i --) {
		j = q[i];
		if (siz[j] > siz[son[fa[j]]]) son[fa[j]] = j;
		//printf("%d %d %d %d\n", i, j, fa[j], son[fa[j]]);
	}
	for (int j, i = 1; i <= tail; i ++) {
		if (!top[j = q[i]])
			for (; j != 0; top[j] = q[i], j = son[j]);
	}
}

int dis(int u, int v) {
	int d = 0;
	for (int fu = top[u], fv = top[v]; fu != fv; fu = top[u = fa[fu]], d ++) {
		if (dep[fu] < dep[fv]) swap(u, v), swap(fu, fv);
		d += dep[u] - dep[fu];
	}
	//printf("%d %d %d\n", u, v, d);
	return d + abs(dep[u] - dep[v]);
}

int bfs_dis(int u, int v, int max_dis) {
	static int q[N], d[N];
	static int head, tail, now;
	head = 1, tail = 0;
	q[++ tail] = u; tim ++; flag[u] = tim; d[u] = 0;
	while (head <= tail) {
		now = q[head];
		if (d[head] > max_dis) return max_dis;
		if (now == v) return d[head];
		for (int w : e[now]) {
			if (flag[w] != tim) {
				flag[w] = tim, q[++ tail] = w, d[tail] = d[head] + 1;
			}
		}
		head ++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u, v, i = 1; i <= m; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) 
		if (!root[i]) 
			bfs(i);
	/*for (int i = 1; i <= n; i ++)
		printf("%d %d %d %d %d %d\n", i, dep[i], fa[i], siz[i], son[i], top[i]);
	return 0;*/
	cin >> q;
	for (int w, u, v, i = 1; i <= q; i ++) {
		cin >> u >> v;
		printf(" %d %d %d ", i, q, (i <= q ? 1 : 0));
		if (root[u] != root[v]) {puts("-1"); continue;}
		w = dis(u, v); //return 0; 
		//printf("%d\n",w);
		if (w == abs(dep[u] - dep[v])) printf("%d\n", w);
		else printf("%d\n", bfs_dis(u, v, w));
	}
 	return 0;
}