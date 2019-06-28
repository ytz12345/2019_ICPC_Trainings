#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int n, L, R;

int m[N], c[N], d[N], f[10010];

bool judge(int k) {
	for (int i = 1; i <= n; i ++)
		d[i] = c[i] / k;
	memset (f, 0, sizeof f); f[0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int t = 1, s = d[i]; s > 0; t <<= 1) {
			t = min(s, t), s -= t;
			if (1ll * t * m[i] > R) continue;
			for (int j = R, w = t * m[i]; j >= w; j --)
				f[j] |= f[j - w];
		}
	}
	for (int i = L; i <= R; i ++)
		if (f[i])
			return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i ++) {
		cin >> m[i] >> c[i];
	}
	int l = 1, r = 1e6, mid, ans = 0;
	while (l <= r) {
		mid = l + r >> 1;
		if (judge(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}