#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2019;

const ll inf = 1e18;

int n, m;

int a[N][N], b[N][N];

ll calc(int x, int y) {
	ll res = 0;
	memset (a, 0, sizeof a);
	if (!b[0][0]) a[0][0] = x == 1 ? 1 : 2;
	else a[0][0] = b[0][0];
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			if (i == 0 && j == 0) continue;
			if (b[i][j]) {a[i][j] = b[i][j]; continue;}
			if (i != 0) a[i][j] = max(a[i][j], a[i - 1][j] + 1);
			if (j != 0) a[i][j] = max(a[i][j], a[i][j - 1] + 1);
			if ((a[i][j] & 1) != ((((i + j) & 1) ? y : x) ^ (i & 1))) a[i][j] ++;
		}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			res += a[i][j];
			if (i != 0 && a[i][j] <= a[i - 1][j]) return inf;
			if (j != 0 && a[i][j] <= a[i][j - 1]) return inf;
			if ((a[i][j] & 1) != ((((i + j) & 1) ? y : x) ^ (i & 1))) return inf;
		}

	/*for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			printf("%d%c", a[i][j], j + 1== m ? '\n' : ' ');*/
	return res;
}

ll work() {
	ll res = 0;
	memset (a, 0, sizeof a);
	if (!b[0][0]) a[0][0] = 1;
	else a[0][0] = b[0][0];
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			if (i == 0 && j == 0) continue;
			if (b[i][j]) {a[i][j] = b[i][j]; continue;}
			if (i != 0) a[i][j] = max(a[i][j], a[i - 1][j] + 1);
			if (j != 0) a[i][j] = max(a[i][j], a[i][j - 1] + 1);
		}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			res += a[i][j];
			if (i != 0 && a[i][j] <= a[i - 1][j]) return inf;
			if (j != 0 && a[i][j] <= a[i][j - 1]) return inf;
		}

	/*for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			printf("%d%c", a[i][j], j + 1== m ? '\n' : ' ');*/
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				cin >> b[i][j];
		ll ans = inf;
		ans = min(ans, calc(0, 0));
		ans = min(ans, calc(0, 1));
		ans = min(ans, calc(1, 0));
		ans = min(ans, calc(1, 1));
		if (n == 1 || m == 1) ans = min(work(), ans);
		if (ans >= inf) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}