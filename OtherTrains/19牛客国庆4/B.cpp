#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

int n, m, k, ans;

struct edge{int u, v, w;}e[N], d[N];

int fa(int *f, int x) {return x == f[x] ? x : (f[x] = fa(f, f[x]));}

int f[N], ff[N];

int used[N], pos;

int cnt[100];

void work(int l, int r) {//[l, r)
	//printf("%d %d\n", l, r);
	for (int i = 1; i <= n; i ++)
		ff[i] = i;
	for (int u, v, i = 0; i < k; i ++) 
		if (!(l <= i && i < r)) {
			u = fa(ff, d[i].u), v = fa(ff, d[i].v);
			if (u != v) ff[u] = v;
		}
	int rpos = pos;
	for (; rpos < m && e[rpos].w == d[l].w; rpos ++);//[pos, rpos)
	//if (d[l].w == 2) printf("%d %d\n", pos, rpos);
	for (int u, v, i = pos; i < rpos; i ++) {
		u = fa(ff, e[i].u), v = fa(ff, e[i].v);
		if (u != v) {
			if (u > v) swap(u, v);
			cnt[u] ++, cnt[v] ++;
		}
	}
	for (int u, v, i = pos; i < rpos; i ++) {
		u = fa(ff, e[i].u), v = fa(ff, e[i].v);
		if (u != v) {
			if (u > v) swap(u, v);
			ans = min(ans, min(cnt[u], cnt[v]));
		}
	}
	for (int u, v, i = pos; i < rpos; i ++) {
		u = fa(ff, e[i].u), v = fa(ff, e[i].v);
		if (u != v) {
			if (u > v) swap(u, v);
			cnt[u] --, cnt[v] --;
		}
	}
	pos = rpos;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		k = 0; ans = m;
		for (int i = 0; i < m; i ++)
			cin >> e[i].u >> e[i].v >> e[i].w;
		e[m ++] = (edge){1, n, int(1e9 + 7)};
		sort (e, e + m, [&](edge a, edge b){return a.w < b.w;});
		for (int i = 0; i < m; i ++)
			f[i] = i, used[i] = 0;
		for (int u, v, i = 0, j = 1; j < n; i ++) {
			u = fa(f, e[i].u), v = fa(f, e[i].v);
			if (u == v) continue;
			used[i] = 1, f[u] = v, j ++, d[k ++] = e[i];
		}
		pos = 0;
		//cout << k << endl;
		for (int i = 1, last = 0; i < k; last = i) {
			while (pos < m && e[pos].w < d[last].w) pos ++;
			while (i < k && d[i].w == d[last].w) i ++;
			work(last, i);
		}
		cout << ans << '\n';
		//return 0;
	}
}