#include <bits/stdc++.h>

using namespace std;

const int N = 44;
const int D = 10;//数位
const int M = (1 << 21) + 2019;

long long ans;

int t, n, k;

int w[N];

int a[M], b[M];

int c[M];

vector <int> num[D][D];

void dfs(int now, int up, int sum,int *a) {
	if (now > up) {
		a[++ a[0]] = sum;
		return;
	}
	dfs(now + 1, up, sum, a);
	dfs(now + 1, up, sum + w[now], a);
}

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n; ans = 0;
		for (int i = 1; i <= n; i ++)
			cin >> w[i];
		k = min(n / 2, 19);
		a[0] = 0, dfs(1, k, 0, a);
		b[0] = 0, dfs(k + 1, n, 0, b);

		for (int i = 0; i < D; i ++)
			for (int j = 0; j < D; j ++)
				num[i][j].clear();

		//return 0;	

		for (int i = 1; i <= b[0]; i ++) {
			int x = b[i];
			long long y = 1;
			for (int j = 0; j < D; j ++) {
				num[j][x % 10].push_back(b[i] % y);
				x /= 10, y *= 10;
			}
		}

		for (int i = 0; i < D; i ++) {
			long long y = 10;
			for (int j = 1; j < D; j ++) {
				c[0] = 0;
				for (int k : num[i][j])
					c[++ c[0]] = k;
				int id = 0;
				for (int k = 1; k <= c[0]; k ++) {
					
				}
			}
		}

		for (int i = 1; i <= a[0]; i ++) {
			int x = a[i], z, pos, tmp;
			long long y = 1, r;
			for (int j = 0; j < D; j ++) {
				z = x % 10, r = a[i] % y;
				pos = (4 - z + 10) % 10;
				tmp = ub(num[j][pos], y - r);
				ans += tmp;	
				pos = (3 - z + 10) % 10;
				tmp = lb(num[j][pos], y - r);
				ans += num[j][pos].size() - tmp;
				x /= 10, y *= 10;
			}
		}

		cout << ans << '\n';
	}
}