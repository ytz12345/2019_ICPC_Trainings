#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 4e5 + 5;

int n, s, a[N], vis[N];

vector <int> e[N];

piir b[N];

void dfs(int u) {
	if (vis[u]) return; 
	vis[u] = 1, s --;
	for (int v : e[u]) dfs(v);
}

bool judge(int k) {
	memset (vis, 0, sizeof vis);
	for (int i = n; i >= 1; i --) {
		if (i == n) s = k - b[i].first + 1;
		else s += b[i + 1].first - b[i].first; 
		dfs(b[i].second);
		if (s < 0) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; int l = n, r = 0, mid, ans;
	for (int j, i = 1; i <= n; i ++) {
		cin >> a[i] >> j; e[i].resize(j);
		for (int k = 0; k < j; k ++)
			cin >> e[i][k];
		r = max(r, a[i]);
		b[i] = piir(a[i], i);
	}
	r += n; sort (b + 1, b + n + 1);
	while (l <= r) {
		mid = l + r >> 1;
		if (judge(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}