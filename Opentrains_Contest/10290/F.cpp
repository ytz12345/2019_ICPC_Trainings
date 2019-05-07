#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, int> piir;

const int N = 1010;

const int M = N * N * 2;

int n, m;

char s[N][N];

int a[N][N];

int f[M], v[M];

vector <int> e[M];

struct node {
	int u, v, w;

	bool operator < (const node &a) const {
		return w < a.w;
	}
};

vector <node> edges;

inline int pos(int i, int j) {
	return (i * m + j) * 2;
}

int fa(int x) {
	return x == f[x] ? x : (f[x] = fa(f[x]));
}

void un(int x, int y) {
	f[fa(y)] = fa(x);
}

void bfs(int st) {
	queue <int> q;
	q.push(st), v[st] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int x : e[now])
			if (!v[x]) 
				un(x, st), v[x] = 1, q.push(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++)
			scanf("%d", &a[i][j]);
	}
	int T = n * m * 2 + 1;
	for (int i = 1; i <= T; i ++)
		f[i] = i;
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j ++) {
			if (j + 1 != m) {
				e[pos(i, j) + (s[i][j] == '/' ? 2 : 1)].push_back(pos(i, j + 1) + (s[i][j + 1] == '/' ? 1 : 2));
				e[pos(i, j + 1) + (s[i][j + 1] == '/' ? 1 : 2)].push_back(pos(i, j) + (s[i][j] == '/' ? 2 : 1));
			}
			if (i + 1 != n) {
				e[pos(i, j) + 2].push_back(pos(i + 1, j) + 1);
				e[pos(i + 1, j) + 1].push_back(pos(i, j) + 2);
			}
		}
	}
	for (int i = 1; i <= n * m * 2; i ++) {
		if (!v[i])
			bfs(i);
	}
	for (int i = 0; i < m; i ++)
		un(T, pos(0, i) + 1), un(T, pos(n - 1, i) + 2);
	for (int i = 0; i < n; i ++)
		un(T, pos(i, 0) + (s[i][0] == '/' ? 1 : 2)), un(T, pos(i, m - 1) + (s[i][m - 1] == '/' ? 2 : 1));
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (fa(pos(i, j) + 1) != fa(pos(i, j) + 2))
				edges.push_back((node){fa(pos(i, j) + 1), fa(pos(i, j) + 2), a[i][j]});
	int sumN = 0, ans = 0;
	for (int i = 1; i <= T; i ++) {
		sumN += fa(i) == i;
	}
	sort (edges.begin(), edges.end());
	for (int u1, u2, i = 0, j = 1; j < sumN; i ++) {
		u1 = fa(edges[i].u);
		u2 = fa(edges[i].v);
		if (u1 == u2) continue;
		ans += edges[i].w, j ++;
		un(u1, u2);
	}
	cout << ans << endl;
	return 0;
}