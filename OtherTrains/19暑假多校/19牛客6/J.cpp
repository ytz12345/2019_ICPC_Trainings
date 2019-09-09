#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int t, n, m;

ll a[N][N], s[N][N], c[N][N];

ll b[N];

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt ++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf("%lld", &a[i][j]);
				s[i][j] = s[i][j - 1] + a[i][j];
			}
			ll minv = 1e18;
			for (int j = m; j >= 0; j --) {
				minv = min(minv, s[i][j]);
				c[i][j] = minv - s[i][j];

				//printf("%d %d  %lld\n", i, j, c[i][j]);
			}
		}

		for (int i = 1; i <= m; i ++)
			scanf("%lld\n", &b[i]);

		ll ans = 0, tmp = 0, sum, maxv;
		for (int i = 0; i <= m; i ++) {
			tmp += b[i];
			for (int j = 1; j <= n; j ++)
				tmp -= a[j][i];

			sum = 0, maxv = -1e18;
			for (int j = 1; j <= n; j ++) {
				sum += c[j][i];
				maxv = max(maxv, c[j][i]);
			}
			sum -= maxv;
			ans = max(ans, tmp - sum);	

			//printf("%d %lld %lld\n", i, tmp, ans);
		}

		printf("Case #%d: %lld\n", tt, ans);
	}

	return 0;
}