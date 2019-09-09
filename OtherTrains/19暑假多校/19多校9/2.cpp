#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

typedef pair<int, int> piir;

int t, n, m, k;

int c1, c2;

int tot1, tot2;

struct cut {
	int x, y;
	char d[5];
}a[N], b[N], c;

int tot, d[N];

struct line {
	int st, ed, y;
}d1[N], d2[N];

vector <piir> e[N];

struct tree{
	int c[N];
	int lim;

	int lb(int x) {
		return x & (-x);
	}

	void add(int i, int x = 1) {
		while (i <= lim) c[i] += x, i += lb(i);
	}

	int ask(int i) {
		int res = 0;
		while (i> 0) res += c[i], i -= lb(i);
		return res;
	}

	void init(int n) {
		lim = n;
		for (int i = 1; i <= n; i ++)
			c[i] = 0;
	}
}tr;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		long long E = 0, V = 0;
		cin >> n >> m >> k;
		c1 = c2 = 0; tot = 0;
		for (int i = 0; i < k; i ++) {
			cin >> c.x >> c.y >> c.d;
			if (c.d[0] == 'L' || c.d[0] == 'R') a[++ c1] = c;
			else b[++ c2] = c;
			d[++ tot] = c.x;
			d[++ tot] = c.y;
		}
		a[++ c1] = (cut){0, 0, "R"};
		a[++ c1] = (cut){0, m, "R"};
		b[++ c2] = (cut){0, 0, "U"};
		b[++ c2] = (cut){n, 0, "U"};
		d[++ tot] = 0, d[++ tot] = n, d[++ tot] = m; 

		sort (d + 1, d + tot + 1);
		tot = unique(d + 1, d + tot + 1) - d - 1;

		for (int i = 1; i <= c1; i ++) {
			a[i].x = lower_bound(d + 1, d + tot + 1, a[i].x) - d;
			a[i].y = lower_bound(d + 1, d + tot + 1, a[i].y) - d;
		}

		for (int i = 1; i <= c2; i ++) {
			b[i].x = lower_bound(d + 1, d + tot + 1, b[i].x) - d;
			b[i].y = lower_bound(d + 1, d + tot + 1, b[i].y) - d;
		}

		n = lower_bound(d + 1, d + tot + 1, n) - d;
		m = lower_bound(d + 1, d + tot + 1, m) - d;

		tot1 = tot2 = 0; int l, r;
		sort (a + 1, a + c1 + 1, [&](cut a, cut b){
			return a.y < b.y;
		});
		a[0].y = a[1].y - 1;
		for (int j, i = 1; i <= c1; i = j) {
			l = 1, r = n;
			for (j = i; j <= c1 && a[j].y == a[i].y; j ++) {
				if (a[j].d[0] == 'L') l = max(l, a[j].x);
				else r = min(r, a[j].x);
 			}
 			if (l >= r) d1[++ tot1] = (line){1, n, a[i].y};
 			else {
 				if (l != 1) d1[++ tot1] = (line){1, l, a[i].y};
 				if (r != n) d1[++ tot1] = (line){r, n, a[i].y};
 			}
		}

		sort (b + 1, b + c2 + 1, [&](cut a, cut b){
			return a.x < b.x;
		});
		b[0].x = b[1].x - 1;
		for (int j, i = 1; i <= c2; i = j) {
			l = 1, r = m;
			for (j = i; j <= c2 && b[j].x == b[i].x; j ++) {
				if (b[j].d[0] == 'D') l = max(l, b[j].y);
				else r = min(r, b[j].y);
 			}
 			if (l >= r) d2[++ tot2] = (line){1, m, b[i].x};
 			else {
 				if (l != 1) d2[++ tot2] = (line){1, l, b[i].x};
 				if (r != m) d2[++ tot2] = (line){r, m, b[i].x};
 			}
		}

		for (int i = 1; i <= max(n, m); i ++)
			e[i].clear();

		for (int i = 1; i <= tot2; i ++) {
			e[d2[i].st].push_back(piir(d2[i].y, 1));
			e[d2[i].ed].push_back(piir(d2[i].y, -1));
		}

		tr.init(n);
		for (int i = 1,j = 1; i <= m; i ++) {
			for (piir k : e[i]) {
				if (k.second == 1) {
					tr.add(k.first);
				}
			}
			while (j <= tot1 && d1[j].y == i) {
				E += tr.ask(d1[j].ed - 1) - tr.ask(d1[j].st) + 1;
				V += tr.ask(d1[j].ed) - tr.ask(d1[j].st - 1);
				if (tr.ask(d1[j].st) - tr.ask(d1[j].st - 1) == 0) V ++;
				if (tr.ask(d1[j].ed) - tr.ask(d1[j].ed - 1) == 0) V ++;
 				j ++;
			}
			for (piir k : e[i]) {
				if (k.second == -1) {
					tr.add(k.first, -1);
				}
			}
		}

		for (int i = 1; i <= max(n, m); i ++)
			e[i].clear();

		for (int i = 1; i <= tot1; i ++) {
			e[d1[i].st].push_back(piir(d1[i].y, 1));
			e[d1[i].ed].push_back(piir(d1[i].y, -1));
		}

		//cout << E << ' ' << V << endl;
		tr.init(m);
		//cout << tot2 << endl;
		//cout << d2[tot2].y << endl;
		for (int i = 1,j = 1; i <= n; i ++) {
			for (piir k : e[i]) {
				if (k.second == 1) {
					tr.add(k.first);
				}
			}
			while (j <= tot2 && d2[j].y == i) {
				E += tr.ask(d2[j].ed - 1) - tr.ask(d2[j].st) + 1;
				if (tr.ask(d2[j].st) - tr.ask(d2[j].st - 1) == 0) V ++;
				if (tr.ask(d2[j].ed) - tr.ask(d2[j].ed - 1) == 0) V ++;
				j ++;
			}
			for (piir k : e[i]) {
				if (k.second == -1) {
					tr.add(k.first, -1);
				}
			}
			//cout << i << ' ' << j << ' ' << E << endl;
		}

		// << E << ' ' << V << endl;
		cout << E - V + 1 << endl;
	}
	return 0;
}