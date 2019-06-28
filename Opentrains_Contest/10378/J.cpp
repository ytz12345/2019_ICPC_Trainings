#include <bits/stdc++.h>

using namespace std;

const int N = 2019;

typedef pair<int, int> piir;

int n, m, s;

map <char, int> p;

struct road{
	char str[3];
	int a, b, c, d;
	int len[N], rl[N];
}a[60];

int dis[N], vis[N];

char str[N];

vector <piir> e[N];

struct node {
	int u, dis;
	bool operator < (const node &a) const {
		return dis > a.dis;
	}
};

priority_queue <node> q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i ++) {
		cin >> a[i].str >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
		for (int j = 0; j < a[i].c; j ++)
			a[i].len[j] = ((a[i].a * j + a[i].b) % a[i].c) + a[i].d;
		for (int j = 0; j < a[i].c; j ++) {
			a[i].rl[j] = a[i].len[j];
			for (int k = 1; k < a[i].c; k ++)
				a[i].rl[j] = min(a[i].rl[j], k + a[i].len[(j + k) % a[i].c]);
		}
		p[a[i].str[0]] = i;
	}
	memset (dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i ++) {
		cin >> str;
		for (int j = 0; j < n; j ++) {
			if (str[j] == '.') continue;
			e[i].push_back(piir(j + 1, p[str[j]]));
		}
	}
	q.push((node){1, dis[1] = s});
	node now;
	while (!q.empty()) {
		now = q.top(), q.pop();
		if (vis[now.u]) continue;
		vis[now.u] = 1;
		for (piir v : e[now.u]) {
			if (vis[v.first] || now.dis + a[v.second].rl[now.dis % a[v.second].c] > dis[v.first]) continue;
			q.push((node){v.first, dis[v.first] = now.dis + a[v.second].rl[now.dis % a[v.second].c]});
		}
	}
	if (dis[n] == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", dis[n] - dis[1]);
	return 0;
}