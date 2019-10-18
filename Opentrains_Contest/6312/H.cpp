#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

int n, m, k;

int a[N], sum[N];

int b[N], p[N];

vector <piir> lim[N]; 

set <piir> s;

int lazy;

inline void no() {
	puts("Impossible");
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] == 0) b[++ k] = i;
		p[i] = k, sum[i] = sum[i - 1] + a[i];
	}
	for (int l, r, x, y, z, i = 1; i <= m; i ++) {
		cin >> l >> r >> x, x -= sum[r] - sum[l - 1];
		y = r - l + 1, z = p[r] - p[l - 1];//z个0
		if (z < x) no();
		if (z != 0) lim[a[l] == 0 ? p[l] : p[l] + 1].push_back(piir(min((z - x) / 2, z), p[r]));
	}

	s.insert(piir(k, k));
	for (int i = 1; i <= k; i ++) {
		for (piir j : lim[i]) s.insert(piir(j.first + lazy, j.second));
		while ((s.begin()) -> second < i) s.erase(s.begin());
		if ((s.begin()) -> first - lazy > 0) a[b[i]] = -1, lazy ++;
		else a[b[i]] = 1;
	}
	for (int i = 1; i <= n; i ++)
		printf("%d%c", a[i], i == n ? '\n' : ' ');
}