#include <bits/stdc++.h>

using namespace std;

const int N = 44;
const int D = 10;//数位
const int M = (1 << 21) + 2019;

long long ans;

int t, n, k;

int w[N];

int a[M], b[M];

vector <int> num[D][D];

void dfs(int now, int up, int sum,int *a) {
	if (now > up) {
		a[++ a[0]] = sum;
		return;
	}
	dfs(now + 1, up, sum, a);
	dfs(now + 1, up, sum + w[now], a);
}

int lb(const vector<int> &a, long long y) {//>=y
	if (a.size() == 0) return 0;
	static int l, r, mid, res;
	l = 0, r = a.size() - 1;
	if (a[0] >= y) return r + 1;
	if (a[r] <  y) return 0;
	while (l <= r) {
		mid = l + r >> 1;
		if (a[mid] >= y) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	return res + 1;
}

int ub(const vector<int> &a, long long y) {//<y
	if (a.size() == 0) return 0;
	static int l, r, mid, res;
	l = 0, r = a.size() - 1;
	if (a[0] >= y) return 0;
	if (a[r] <  y) return r + 1;
	while (l <= r) {
		mid = l + r >> 1;
		if (a[mid] < y) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	return res + 1;
}

int main() {
	/*vector <int> o;
	o.push_back(1);
	o.push_back(2);
	cout << lower_bound(o.begin(), o.end(), 2) - o.begin();
	return 0;*/
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
				//printf("insert %d %d %d\n", j, x % 10, b[i] % y);
				x /= 10, y *= 10;
			}
		}

		for (int i = 0; i < D; i ++)
			for (int j = 0; j < D; j ++)
				sort (num[i][j].begin(), num[i][j].end());

		//return 0;

		for (int i = 1; i <= a[0]; i ++) {
			int x = a[i], z, pos, tmp;
			long long y = 1, r;
			for (int j = 0; j < D; j ++) {
				z = x % 10, r = a[i] % y;
				pos = (4 - z + 10) % 10;
				tmp = ub(num[j][pos], y - r);
				/*lower_bound(num[j][pos].begin(), num[j][pos].begin(), y - r) 
					- num[j][pos].begin();
				printf("ask z=%d %d %d %d %d %d siz=%d\n", z, i, j, pos, y - r, tmp,num[j][pos].size());
				for (int tt:num[j][pos])
					printf("%d ",tt);
				puts("");*/
				ans += tmp;	
				pos = (3 - z + 10) % 10;
				tmp = lb(num[j][pos], y - r); 
				/*lower_bound(num[j][pos].begin(), num[j][pos].begin(), y - r) 
					- num[j][pos].begin();*/
				ans += num[j][pos].size() - tmp;
				x /= 10, y *= 10;
			}
		}

		cout << ans << '\n';
	}
}