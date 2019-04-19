#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

const int P = 1e6 + 5;

const int inf = 1e9 + 7;

int n, a[P], b[P], c[P], d[P];

int p[P], v[P];

int f[P][8];

vector <int> e[P];

int ans, l, r;

int lb(int x) {return x & (-x);}

void add(int i, int x) {while (i < P) c[i] = min(c[i], x), i += lb(i);}

int ask(int i) {int res = inf; while (i > 0) res = min(res, c[i]), i -= lb(i); return res;}

void recover(int i) {while (i < P) c[i] = inf, i += lb(i);}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	memset (f, 0, sizeof f);
	for (int i = 2; i < P; i ++) {
		if (!v[i]) {
			p[++ p[0]] = i;
			for (int j = i; j < P; j += i) {
				f[j][++ f[j][0]] = p[0];
			}
		}
		for (int j = 1; j <= p[0] && i * p[j] < P; j ++) {
			v[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		for (int j = 1; j <= f[a[i]][0]; j ++)
			e[f[a[i]][j]].push_back(i); 
	}
	for (int i = 0; i < P; i ++) c[i] = inf;
	for (int i = 1; i <= p[0]; i ++) {
		int cnt = 0, res, tmp;
		for (int j : e[i]) {
			cout << j << endl;
			cnt += 2;
			d[j] = cnt - j + 500001;
			res = ask(d[j]);
			cout << p[i] << ' ' << j << ' ' << res << endl;
			if (res == inf) {
				if (j == 1) {
					if (ans < 1) 
						ans = 1, l = 1, r = 1;
				}
				else {
					if (ans < 2) 
						ans = 2, l = i - 1, r = i;
				}
			}
			else {
				tmp = j - res + 1 + min(d[j] - d[res], res - 1 + n - j);
				if (tmp > ans) {
					//cout << p[i] << ' ' << tmp << endl;
					ans = tmp;
				}
			}
			add(d[j], j);
		}
		for (int j : e[i]) 
			recover(d[j]);
	}
	cout << ans;
	//cout << l << ' ' << r << endl;
	return 0;
}