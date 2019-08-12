#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> piir;
 
const int N = 2e5 + 5;
const int inf = 1e9;
 
int n, m, w[N];
 
int fa[N], dep[N], siz[N], son[N], top[N];
 
int cnt, ed[N], pos[N], dfn[N];
 
struct {int x, k;}q[N];
 
set <piir, greater<piir> > sv[N], sk[N];
 
vector <int> e[N];
 
piir mv[N], mk[N];
 
piir tr[N << 2];

int ans[N];
 
#define lc(x) (x << 1)
#define rc(x) (lc(x) | 1)
#define mid (l + r >> 1) 

void dfs1(int u) {
    siz[u] = 1;
    for (int v : e[u]) {
        if (v == fa[u]) continue;
        fa[v] = u, dep[v] = dep[u] + 1;
        dfs1(v), siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}
 
void dfs2(int u, int tp) {
    pos[u] = ++ cnt, dfn[cnt] = u, top[u] = tp, ed[tp] = u;
    if (son[u]) dfs2(son[u], tp);
    for (int v : e[u])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}
 
int maxv(int x, int y) {
    return mv[x] > mv[y] ? x : y;
}

int maxk(int x, int y) {
	return mk[x] > mk[y] ? x : y;
}
 
void update(int o) {
	tr[o].first  = maxv(tr[lc(o)].first,  tr[rc(o)].first);
	tr[o].second = maxk(tr[lc(o)].second, tr[rc(o)].second);
}

void build(int o, int l, int r) {
	if (l == r) {
		tr[o] = piir(dfn[r], dfn[r]);
		return;
	}
	build(lc(o), l, mid);
	build(rc(o), mid + 1, r);
	update(o);
}

void modify(int p, int o = 1, int l = 1, int r = n) {
    if (l == r) return;
    if (p <= mid) modify(p, lc(o), l, mid);
    else          modify(p, rc(o), mid + 1, r);
    update(o);
}

int askv(int s, int t, int o = 1, int l = 1, int r = n) {
	if (s <= l && r <= t) return tr[o].first;
	int res = 0;
	if (s <= mid) res = maxv(res, askv(s, t, lc(o), l, mid));
	if (mid <  t) res = maxv(res, askv(s, t, rc(o), mid + 1, r));
	return res;
}

int askk(int s, int t, int o = 1, int l = 1, int r = n) {
	if (s <= l && r <= t) return tr[o].second;
	int res = 0;
	if (s <= mid) res = maxk(res, askk(s, t, lc(o), l, mid));
	if (mid <  t) res = maxk(res, askk(s, t, rc(o), mid + 1, r));
	return res;
}
 
void change(int id, int flag = 1) {
    int u = q[id].x;
    do {
        if (flag == 1) {
        	sv[u].insert(piir(w[u] + q[id].k, id));
        	sk[u].insert(piir(q[id].k, id));
        }
        else {
        	sv[u].erase(piir(w[u] + q[id].k, id));
        	sk[u].erase(piir(q[id].k, id));
        }
        if (sv[u].empty()) {
        	mv[u] = piir(-inf, 0);
        	mk[u] = piir(-inf, 0);
        }
        else {
        	mv[u] = *(sv[u].begin());
        	mk[u] = *(sk[u].begin());
        }
        modify(pos[u]), u = fa[top[u]];
    }while (u);
}
 
piir query(int u) {
    piir res = piir(-inf, 0);
    for (int i; u; u = fa[top[u]]) {
    	i = askv(pos[top[u]], pos[u]);
        res = max(res, mv[i]);
    	i = askk(pos[u], pos[ed[top[u]]]);
        res = max(res, piir(mk[i].first + w[u], mk[i].second));
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    for (int u, v, i = 1; i < n; i ++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1), dfs2(1, 1); 
 
    for (int i = 0; i <= n; i ++) mv[i] = mk[i] = piir(-inf, 0);
    build(1, 1, n);

    for (int i = 1; i <= m; i ++) {
        cin >> q[i].x >> q[i].k;
        change(i);
    }
    for (int i = n; i >= 1; i --) {
        for (piir j = query(i); j.first >= i; j = query(i)) {
            ans[j.second] = i;
            change(j.second, -1);
        }
    }
 
    for (int i = 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}