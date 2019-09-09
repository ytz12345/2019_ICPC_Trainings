#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*
struct rec {
	ll x1, x2, y1, y2, s;

	void scan() {
		cin >> x1 >> y1 >> x2 >> y2;
		s = (x2 - x1) * (y2 - y1);
	}

	bool operator == (const rec &a) const {
		return x1 == a.x1 && x2 == a.x2 && y1 == a.y1 && y2 == a.y2;
	}
}a, b;

int checkIn(const rec &p, ll x, ll y) {
	if (p.x1 < x && x < p.x2 && p.y1 < y && y < p.y2) return 1;
	if (x < p.x1 || x > p.x2 || p.y1 > y || y > p.y2) return -1;
	return 0;
}//-1/0/1 out/on/in

int t, c[4];*/

const int N = 10;

int t, a[10], b[10];

int c[12][12], v[12][12];

queue <int> qx, qy;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void bfs(int x, int y) {
	while (!qx.empty()) qx.pop();
	while (!qy.empty()) qy.pop();
	qx.push(x), qy.push(y), v[x][y] = 1;
	while (!qx.empty()) {
		x = qx.front(), y = qy.front();
		qx.pop(), qy.pop();
		for (int i = 0; i < 4; i ++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || v[nx][ny] || c[nx][ny] != c[x][y]) continue;
			qx.push(nx), qy.push(ny), v[nx][ny] = 1;
		}
	}	
}

int main() {
	//freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		int cnt = 0;
		memset (c, 0, sizeof c);
		memset (v, 0, sizeof v);
		for (int i = 0; i < 8; i ++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort (b, b + 8);
		int k = unique(b, b + 8) - b;
		for (int i = 0; i < 8; i ++) {
			a[i] = lower_bound(b, b + k, a[i]) - b + 1;
			//printf("%d ", a[i]);
		}
	//	puts("");
		for (int i = a[0] + 1; i <= a[2]; i ++)
			for (int j = a[1] + 1; j <= a[3]; j ++)
				c[i][j] += 1;
		for (int i = a[4] + 1; i <= a[6]; i ++)
			for (int j = a[5] + 1; j <= a[7]; j ++)
				c[i][j] += 2;
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N; j ++)
				if (!v[i][j])
					bfs(i, j), cnt ++;
		//for (int i = 0; i < N; i ++)
		//	for (int j = 0; j < N; j ++)
		//		printf("%d%c",c[i][j], j + 1 == N?'\n':' ');
		printf("%d\n", cnt);
		/*
		a.scan(), b.scan();
		if (a.s < b.s) swap(a, b); // a >= b
		c[0] = checkIn(a, b.x1, b.y1);
		c[1] = checkIn(a, b.x2, b.y1);
		c[2] = checkIn(a, b.x2, b.y2);
		c[3] = checkIn(a, b.x1, b.y2);
		if (a == b) puts("2");
		else if (c[0] < 1 && c[1] < 1 && c[2] < 1 && c[3] < 1) {
			if (a.x1 < b.x1 && b.x2 < a.x2) {
				if (a.y1 == b.y1 && a.y2 == b.y2) puts("4");
				else if (a.y1 == b.y1 || a.y2 == b.y2) puts("5");
				else puts("6");
			}
			else if (a.y1 < b.y1 && b.y2 < a.y2) {
				if (a.x1 == b.x1 && a.x2 == b.x2) puts("4");
				else if (a.x1 == b.x1 && a.x2 == b.x2) puts("5");
				else puts("6");
			}
			else if (a.x1 < b.x1 && b.x1 < a.x2) {
				
			}
			else puts("3");
		}
		else if (c[0] == -1 || c[1] == -1 || c[2] == -1 || c[3] == -1) puts("4");
		else puts("3");
		*/
	}
}
