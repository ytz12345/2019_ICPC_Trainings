#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

const int N = 5e5; 

typedef pair<int, int> piir;

piir a[N], b[N];

int n, m;

int c[N];

void solve(int l, int r) {//[l, r]
	int mid = l + r >> 1, pos = a[mid].x;
	for (int i = l; i <= r; i ++)
		if (a[i].x == a[mid].x)
			c[a[i].y] = 1;
	for (int i = l; i <= r; i ++) 
		if (!c[a[i].y])
			b[m ++] = piir(pos, a[i].y), c[a[i].y] = 1;
	for (int i = l; i <= r; i ++)
		c[a[i].y] = 0;
	int lr = mid - 1;
	while (lr >= l && a[lr].x == a[mid].x) lr --;
	int rl = mid + 1;
	while (rl <= r && a[rl].x == a[mid].x) rl ++;
	if (l <= lr) solve(l, lr);
	if (rl <= r) solve(rl, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i].x >> a[i].y;
	sort (a, a + n);
	solve(0, n - 1);
	printf("%d\n", m);
	for (int i = 0; i < m; i ++)
		printf("%d %d\n", b[i].x, b[i].y);
	return 0;
}