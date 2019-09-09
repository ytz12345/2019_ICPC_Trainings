#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;

char s[N][N];

int a[N][N];

struct node {
	int lx, ly, rx, ry;

	int siz;

	bool operator < (const node &a) const {
		return siz < a.siz;
	} 

	bool operator == (const node &a) const {
		if (siz != a.siz) return 0;
		return !(lx != a.lx ||
			     rx != a.rx || 
			     ly != a.ly || 
			     ry != a.ry);
	} 

	void print() {
		cout << ' ' << lx << ' ' << ly << ' ' << rx << ' ' << ry <<' ' << siz << endl;
	}
}max1, max2;

int l[N], r[N], q[N], top;

void upd(node x) {
	//x.print();
	if (x == max1 || x == max2 || x.siz <= max2.siz) return;
	//x.print();
	if (x.siz > max1.siz) max2 = max1, max1 = x;
	else max2 = x;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);

	max1.siz = 0;
	max2.siz = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++)
			if (s[i][j] == '0') a[i][j] = 0;
			else a[i][j] = a[i - 1][j] + 1;

		top = 0;
		for (int j = 1; j <= m; j ++) {
			while (top > 0 && a[i][j] < a[i][q[top]]) r[q[top]] = j - q[top], top --;
			q[++ top] = j;
		}
		while (top > 0) r[q[top]] = m + 1 - q[top], top --;

		top = 0;
		for (int j = m; j >= 1; j --) {
			while (top > 0 && a[i][j] < a[i][q[top]]) l[q[top]] = q[top] - j, top --;
			q[++ top] = j;
		}
		while (top > 0) l[q[top]] = q[top] - 0, top --;

		for (int j = 1; j <= m; j ++) {
			//cout << i << ' ' << j << ' ' << a[i][j] << ' ' << l[j] << ' ' << r[j] << endl;
			upd((node){i - a[i][j], j - l[j], i, j + r[j], (l[j] + r[j] - 1) * a[i][j]});
			upd((node){i - a[i][j], j - l[j] + 1, i, j + r[j], (l[j] + r[j] - 2) * a[i][j]});
			upd((node){i - a[i][j], j - l[j], i, j - 1 + r[j], (l[j] + r[j] - 2) * a[i][j]});
			upd((node){i - a[i][j] + 1, j - l[j], i, j + r[j], l[j] * (a[i][j] - 1)});
		}
	}

	cout << max2.siz << endl;

	return 0;
}