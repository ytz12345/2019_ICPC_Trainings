#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 130000;

const int M = N * 20;

int n, m, k, s, t, len;

int a[N], d[N], add[N], de[N];

double ans;

void dfs(int i, int c1, int c2, int c3, double s) {
	if (i > t) {ans = max(ans, s); return;}
	if (c1 < len) dfs(i + 1, c1 + 1, c2, c3, s + a[i]);
	if (c2 < len) dfs(i + 1, c1, c2 + 1, c3, s + (a[i] + d[i]) / 2.0);
	if (c3 < len) dfs(i + 1, c1, c2 ,c3 + 1, s + d[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; 
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> d[i];
	cin >> m;
	for (int i = 0; i < m; i ++) {
		cin >> s >> t, len = (t - s + 1) / 3;
		ans = 0, dfs(s, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}