#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int Mod = 1e9 + 7;

int n, m;

ll h, ans, cnt, f[N], c2, c1;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		ans = cnt = 0, f[0] = 0, c1 = c2 = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> h, f[0] += (h + 2) / 3;
			if (h % 3 == 1) {
				if (h == 1) cnt ++, h -= 1;
				else cnt += 2, h -= 4;
			}
			else if (h % 3 == 2) {
				cnt ++, h -= 2;
			}
			c2 += h / 6;
			if (h % 6 == 3) c1 ++;
		}
		//cout << cnt << ' ' << f[0] << endl;
		if (cnt >= m) {
			for (int i = 1; i <= m; i ++)
				f[i] = f[i - 1] - 1;
		}
		else {
			for (int i = 1; i <= cnt; i ++)
				f[i] = f[i - 1] - 1;
			int i;
			for (i = cnt + 1; i <= m && (c2 -- > 0); i += 3) {
				f[i] = f[i - 1];
				f[i + 1] = f[i] - 1;
				f[i + 2] = f[i] - 2;
			}
			for (; i <= m && (c1 -- > 0); i += 2)
				f[i] = f[i - 1], f[i + 1] = f[i] - 1;
		}
		for (int i = 0; i <= m; i ++)
			ans += max(f[i], 0ll), ans %= Mod;
		cout << ans % Mod << '\n';
	}
}