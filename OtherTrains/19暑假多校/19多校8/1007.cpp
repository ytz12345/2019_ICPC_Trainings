#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 3e5 + 15;

const int B = 500;

const int D = 20;

int t, n, m;

vector <int> e[N];

vector <int> sma[B][B], blk[B][B], val[B][B];

int dfsCnt, dfsDfn[N], dfsEd[N], dfsId[N];

int bfsCnt, bfsDfn[N], bfsId[N];

int lMost[N], rMost[N], bel[N];

int dep[N], pos[B][N];

void dfs(int u) {
	dfsDfn[u] = ++dfsCnt, dfsId[dfsCnt] = u;
	for (int v : e[u])
		dep[v] = dep[u] + 1, dfs(v);
	dfsEd[u] = dfsCnt;
}

void getDfs() {
	static int minDfn[N], maxDfn[N];
	dfsCnt = 0;
	dfs(1);

	for (int i = 1; i <= n; i ++)
		minDfn[i] = maxDfn[i] = -1;
	for (int u, i = n; i >= 1; i --) {
		u = dfsId[i];
		lMost[u] = minDfn[dep[u] + 1];
		rMost[u] = maxDfn[dep[u] + 1];
		minDfn[dep[u]] = u;
		if (maxDfn[dep[u]] == -1) 
			maxDfn[dep[u]] = u;
	}
}

void getBfs() {
	static int q[N], l, r, x;
	q[l = r = 1] = 1;
	while (l <= r) {
		x = q[l], bfsDfn[x] = l;
		bfsId[l] = x, l ++;
		for (int v : e[x]) {
			q[++ r] = v;
		}
	}
}

void getSma() {
	for (int i = 1; i <= n; i ++)
		bel[i] = (i - 1) / B + 1;

	for (int i = 1; i < B; i ++) 
		for (int j = 0; j < i; j ++) 
			sma[i][j][0] = 0;

	for (int i = 1; i < B; i ++)
		for (int x, j = 1; j <= n; j ++) {
			x = dep[dfsId[j]] % i;
			pos[i][dfsId[j]] = ++ sma[i][x][0];
			sma[i][x][sma[i][x][0]] = j;
			val[i][x][sma[i][x][0]] = 0;
			blk[i][x][bel[sma[i][x][0]]] = 0;
		}
}

void add(int a, int x, int y, int z) {
	y = (y + dep[a]) % x;
	int l = lower_bound(sma[x][y].begin() + 1, sma[x][y].begin() + sma[x][y][0] + 1, dfsDfn[a]) 
		- sma[x][y].begin();
	int r = upper_bound(sma[x][y].begin() + 1, sma[x][y].begin() + sma[x][y][0] + 1, dfsEd[a]) 
		- sma[x][y].begin() - 1;

	if (bel[l] == bel[r]) {
		for (int i = l; i <= r; i ++) 
			val[x][y][i] += z;
	}
	else {
		for (int i = l, up = bel[l] * B; i <= up; i ++)
			val[x][y][i] += z;
		for (int i = bel[r] * B - B + 1, up = r; i <= r; i ++)
			val[x][y][i] += z;
		for (int i = bel[l] + 1; i < bel[r]; i ++)
			blk[x][y][i] += z;
	}
}

int askSma(int x) {
	int res = 0;
	for (int i = 1; i < B; i ++) {
		int j = dep[x] % i;
		res += val[i][j][pos[i][x]] + blk[i][j][bel[pos[i][x]]];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	
	for (int i = 1; i < B; i ++) 
		for (int j = 0; j < i; j ++) {
			sma[i][j].resize(N / i + 5);
			val[i][j].resize(N / i + 5);
			blk[i][j].resize(N / i / B + 5);
		}

	int cnt = 0;
	for (int i = 1; i < B; i ++) {
		for (int j = 0; j < i; j ++)
		cnt += sma[i][j].size() * 2 + blk[i][j].size();
	}
	cout << B * N << endl;
	cout << cnt << endl;
	return 0;

	for (cin >> t; t --; ) {
		cin >> n >> m;
		for (int i = 0; i < n; i ++) {
			e[i].clear();
		}
		for (int u, i = 2; i <= n; i ++) {
			cin >> u;
			e[u].push_back(i);
		}
		getDfs(), getBfs(), getSma();
		for (int op, a, x, y, z; m --; ) {
			cin >> op;
			if (op == 1) {
				cin >> a >> x >> y >> z;
				if (x < B) add(a, x, y, z);
				else {

				}
			}
			else {
				cin >> x;
			}
		}
	}

	return 0;
}