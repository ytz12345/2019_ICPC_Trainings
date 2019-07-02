#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;

struct opt {
	char str[10];
	int i, j;
}a[N];

int f[N], ans;

int bel[N], flag[N], ckd[N];

vector <int> e[N], as;

int fa(int x) {return x == f[x] ? x : (f[x] = fa(f[x]));}

void un(int x, int y) {
	//cout << x << ' ' << y << endl;
	x = fa(x), y = fa(y);
	if (x < y) f[y] = x;
	else f[x] = y;
}

void no() {
	puts("inconsistent");
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n * 2; i ++) f[i] = i;
	for (int x, y, i = 0; i < m; i ++) {
		cin >> a[i].str >> a[i].i;
		if (a[i].str[0] == 'p') {
			cin >> a[i].j;
			if (a[i].str[1] == 'a') {
				x = fa(a[i].i), y = fa(a[i].j);
				if (x == y) ans ++, as.push_back(i + 1);
				else un(a[i].i, a[i].j), un(a[i].i + n, a[i].j + n);
			}
			else {
				x = fa(a[i].i), y = fa(a[i].j + n);
				if (x == y) ans ++, as.push_back(i + 1);
				else un(a[i].i, a[i].j + n), un(a[i].i + n, a[i].j);
			}
		}
	}
	for (int i = 1; i <= n; i ++)
		if (fa(i) == fa(i + n))
			no();
	//cout << ans << endl;
	for (int af, fg, i = 1; i <= n; i ++) {
		if (fa(i) < fa(i + n)) af = fa(i), fg = 0;
		else af = fa(i + n), fg = 1;
		e[af].push_back(i), ckd[af] = -1;
		bel[i] = af, flag[i] = fg;
	}
	/*for (int i = 1; i <= n; i ++) {
		cout << i << ' ' << bel[i] << endl;
	}*/
	for (int i = 0; i < m; i ++) {
		if (a[i].str[0] == 'p') continue;
		if (a[i].str[0] == 'h') {
			if (ckd[bel[a[i].i]] != -1) {
				if (ckd[bel[a[i].i]] == flag[a[i].i]) ans ++, as.push_back(i + 1);
				else no();
			}
			else ckd[bel[a[i].i]] = flag[a[i].i];
		}
		else {
			if (ckd[bel[a[i].i]] != -1) {
				if (ckd[bel[a[i].i]] == !flag[a[i].i]) ans ++, as.push_back(i + 1);
				else no();
			}
			else ckd[bel[a[i].i]] = !flag[a[i].i];
		}
	}
	printf("consistent\n%d\n", ans);
	for (int i = 0; i < as.size(); i ++) {
		printf("%d%c", as[i], (i + 1) == as.size() ? '\n' : ' ');
	}
	return 0;
}