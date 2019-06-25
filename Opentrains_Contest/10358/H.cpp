#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 1010;

const int M = 1e6 + 5;

int n, m;

char s[N][N];

int p[N][N];

int sum[N][N];

int maxs[N][N];

int f[M];

struct edge {
	int u, v, w;
	bool operator < (const edge &a) const {
		return w > a.w;
	}
}E[M * 2];

int len;

vector <piir> e[M];

inline int calc(int i, int j, int k) {
	return sum[i + k / 2][j + k / 2] +
		   sum[i - k / 2 - 1][j - k / 2 - 1] -
		   sum[i - k / 2 - 1][j + k / 2] -
		   sum[i + k / 2][j - k / 2 - 1];
}

inline void add(int a, int b, int c, int d, int f) {
	E[len ++] = (edge){p[a][b], p[c][d], f};
}

inline int F(int x) {return f[x] == x ? x : (f[x] = F(f[x]));}

int fa[M], son[M], siz[M], dep[M], val[M], root[M], RT;

int cnt, top[M], dfn[M], pos[M];

int MM, tr[M << 2];

void dfs1(int u) {
	siz[u] = 1, root[u] = RT;
	for (auto w : e[u]) {
		int v = w.first;
		if (root[v]) continue;
		dep[v] = dep[u] + 1, fa[v] = u, dfs1(v);
		siz[u] += siz[v], val[v] = w.second;
		if (siz[v] > siz[son[u]]) son[u] = v; 
	}
}

void dfs2(int u, int tp) {
	dfn[u] = ++cnt, pos[cnt] = u, top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (auto v : e[u]) {
		if (v.first == fa[u] || v.first == son[u]) continue;
		dfs2(v.first, v.first);
	}
}

int query(int s, int t) {
	int res = 1e9;
	for (s += MM - 1, t += MM + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = min(res, tr[s ^ 1]);
		if ( t&1) res = min(res, tr[t ^ 1]);
	}
	return res;
}

int ask(int u, int v) {
	if (root[u] != root[v]) return 0;
	int res = 1e9;
	for (int fu = top[u], fv = top[v]; fu != fv; fu = top[u = fa[fu]]) {
		if (dep[fu] < dep[fv]) swap(fu, fv), swap(u, v);
		res = min(res, query(dfn[fu], dfn[u]));
	}
	if (u == v) return res;
	if (dep[u] < dep[v]) swap(u, v);
	return min(res, query(dfn[v] + 1, dfn[u]));
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= n; j ++) {
			sum[i][j] = sum[i][j - 1] +
						sum[i - 1][j] -
						sum[i - 1][j - 1] +
						(s[i][j] == '#');
			p[i][j] = (i - 1) * n + j;
		}
	}
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j ++) {
			if (s[i][j] == '#') continue;
			int l = 1, r = 2 * min(min(i, j), min(n - i + 1, n - j + 1)) - 1, mid;
			while (l <= r) {
				mid = l + r >> 1;
				if (calc(i, j, mid) == 0) l = mid + 1, maxs[i][j] = mid;
				else r = mid - 1;
			}
			if (i != 1 && s[i - 1][j] != '#') add(i - 1, j, i, j, min(maxs[i][j], maxs[i - 1][j])); 
			if (j != 1 && s[i][j - 1] != '#') add(i, j - 1, i, j, min(maxs[i][j], maxs[i][j - 1])); 
		}
	for (int i = 1; i < M; i ++)
		f[i] = i;
	sort (E, E + len);
	for (int u, v, i = 0; i < len; i ++) {
		u = F(E[i].u), v = F(E[i].v);
		if (u == v) continue;
		f[u] = v;
		e[E[i].u].push_back(piir(E[i].v, E[i].w));
		e[E[i].v].push_back(piir(E[i].u, E[i].w));
	}
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j ++) 
			if (s[i][j] != '#' && !root[p[i][j]]) {
				RT = p[i][j];
				dfs1(p[i][j]);
				dfs2(p[i][j], p[i][j]);
			}
	for (MM = 1; MM < cnt + 2; MM <<= 1);
	memset(tr, 0x3f, sizeof tr);
	for (int i = 1; i <= cnt; i ++)
		tr[i + MM] = val[pos[i]];
	for (int i = MM - 1; i >= 1; i --)
		tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
	scanf("%d", &m);
	for (int a, b, c, d, i = 0; i < m; i ++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", ask(p[a][b], p[c][d]));
	}
	return 0;
}