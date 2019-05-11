#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 10010;

const int M = 1000000;

const ll inf = 1e12;

int n, m, k;

int a[10010][200];

const int SPFA_inf = 0x3f3f3f3f;

const ll DIS_inf = 1e17; 

int s, t, len;

int head[N], incf[N], path[N], pre[N], vis[N];

ll d[N], ans, maxflow;

struct edge{
	int to, next, cap;
	ll cost;
}e[M];

void add(int u, int v, int w, ll c) {
	e[++ len] = (edge){v, head[u], w, c}, head[u] = len;
	e[++ len] = (edge){u, head[v], 0, -c}, head[v] = len;
}

bool spfa() {
	deque <int> q;
	q.push_back(s), incf[s] = SPFA_inf;
	for (int i = 1; i <= t; i ++) d[i] = DIS_inf;
	d[s] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop_front();
		vis[x] = 0;
		for (int i = head[x]; i; i = e[i].next) {
			if (e[i].cap && d[e[i].to] > d[x] + e[i].cost) {
				d[e[i].to] = d[x] + e[i].cost;
				pre[e[i].to] = x, path[e[i].to] = i;
				incf[e[i].to] = min(incf[x], e[i].cap);
				if(!vis[e[i].to]) {
					vis[e[i].to] = 1;
					if (q.empty() || d[e[i].to] < d[q.front()]) q.push_front(e[i].to);
					else q.push_back(e[i].to);
				}
			}
		}
	}
	if (d[t] == DIS_inf) return 0;
	for (int i = t; i != s; i = pre[i]) {
		e[path[i]].cap -= incf[t];
		e[path[i] ^ 1].cap += incf[t];
	}
	maxflow += incf[t];
	return ans += incf[t] * d[t], 1;
}

void work(int id, int x, ll &res, vector<int> &ch) {
	len = 1; maxflow = 0;
	s = n + m + 2, t = s + 1;
	for (int i = 1; i <= t; i ++) head[i] = 0;
	for (int i = 1; i <= n; i ++)
		add(s, i, 1, 0);
	for (int i = 1; i <= m; i ++)
		if (i != id && x != 1)
			add(i + n, t, x - 1, 0);
	add(id + n, t, SPFA_inf, 0);
	add(id + n, t, x, -inf);
	add(m + 1 + n, t, SPFA_inf, 0);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m + 1; j ++)
			add(i, j + n, 1, a[i][j]);
	ans = inf * x;
	while(spfa());
	if (ans < res) {
		res = ans;
		ch.clear(); ch.resize(n + 1);
		for (int i = 1; i <= n; i ++)
			for (int j = head[i]; j; j = e[j].next) {
				if (n < e[j].to && e[j].to <= n + m + 1 && e[j].cap == 0)
					ch[i] = e[j].to - n;
			}
	}
	//printf("%d %lld %lld\n", x, maxflow, ans);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	ll ans = 1e18;
	vector <int> ch;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m + 1; j ++)
			cin >> a[i][j];
	for (int x = 1; x <= n; x ++) 
		work(k, x, ans, ch);
	cout << ans << endl;
	for (int i = 1; i <= n; i ++)
		cout << ch[i] << (i  == n ? '\n' : ' ');
	return 0;
}