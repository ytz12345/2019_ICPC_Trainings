#include <bits/stdc++.h>

using namespace std;

typedef vector<char> vc;

const int dx[] = {1, -1, 0, 0};

const int dy[] = {0, 0, 1, -1};

int n, m, k;

char s[200][200];

int vis[200][200];

int r, c;

struct node {
	vector <vc> v;

	bool operator == (const node &a) const {
		for (int i = 0; i < r; i ++)
			for (int j = 0; j < c; j ++)
				if (v[i][j] != a.v[i][j])
					return 0;
		return 1;
	}
}a[60 * 60];

queue <int> qx, qy;

int f[60 * 60];

int fa(int x) {return x == f[x] ? x : (f[x] = fa(f[x]));}

int un(int x, int y) {x = fa(x), y = fa(y); if (x != y) f[y] = x;}

void work(int x, int y) {
	if (r == 0) {
		int i = x, j = y;
		for (; i < n && s[i][y] != '#'; i ++)
			r ++;
		for (; j < m && s[x][j] != '#'; j ++)
			c ++;
	}
	int i, j, nx, ny;
	a[++ k].v.resize(r);
	for (vc &i : a[k].v) i.resize(c);
	qx.push(x), qy.push(y), vis[x][y] = 1;
	while (!qx.empty()) {
		i = qx.front(), j = qy.front();
		qx.pop(), qy.pop();
		a[k].v[i - x][j - y] = s[i][j];
		for (int t = 0; t < 4; t ++) {
			nx = i + dx[t], ny = j + dy[t];
			if (s[nx][ny] == '#' || vis[nx][ny]) continue;
			qx.push(nx), qy.push(ny);
			vis[nx][ny] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] != '#' && !vis[i][j]) {
				work(i, j);
			}
		}
	}
	for (int i = 1; i <= k; i ++) f[i] = i;
	node tmp, temp;
	tmp.v.resize(r);
	for (vc &i : tmp.v) i.resize(c);
	temp = tmp;
	for (int i = 1; i <= k; i ++) 
		for (int j = i + 1; j <= k; j ++) {
			if (fa(i) == fa(j)) continue;
			if (a[i] == a[j]) {un(i, j); continue;}
			else {
				int p = i;
				for (int i = 0; i < r; i ++)
					for (int j = 0; j < c; j ++)
						tmp.v[i][j] = a[p].v[r - 1 - i][c - 1 - j];
				if (tmp == a[j]) un(i, j);
				else if (r == c) {
					for (int i = 0; i < r; i ++)
						for (int j = 0; j < c; j ++)
							tmp.v[i][j] = a[p].v[j][r - i - 1];
					if (tmp == a[j]) un(i, j);
					else {
						for (int i = 0; i < r; i ++)
							for (int j = 0; j < c; j ++)
								temp.v[i][j] = tmp.v[r - 1 - i][c - 1 - j];
						if (temp == a[j]) un(i, j);
					}
				}
			}
		}
	int ans = 0;
	for (int i = 1; i <= k; i ++)
		ans += fa(i) == i;
	cout << ans << endl;
	return 0;
}