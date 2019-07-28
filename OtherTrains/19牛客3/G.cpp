#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

int t, n;

ll a[N], s[N], ans;

ll maxv[N], sum[N];

void solve(int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;

	maxv[mid] = sum[mid] = a[mid];
	maxv[mid + 1] = sum[mid + 1] = a[mid + 1];

	for (int i = mid - 1; i >= l; i --) {
		maxv[i] = max(maxv[i + 1], a[i]);
		sum[i] = sum[i + 1] + a[i];
	}

	for (int i = mid + 2; i <= r; i ++) {
		maxv[i] = max(maxv[i - 1], a[i]);
		sum[i] = sum[i - 1] + a[i];
	}

	for (int i = mid, j = mid + 1; i >= l; i --) {
		while (j <= r && maxv[j] <= maxv[i]) j ++;
		
		int L = mid + 1, R = j - 1, Mid, pos = j;

		while (L <= R) {
			Mid = L + R >> 1;
			if (sum[i] + sum[Mid] >= maxv[i] * 2) pos = Mid, R = Mid - 1;
			else L = Mid + 1;
		}

		ans += j - pos;
	}
	//printf("%lld\n", ans);

	for (int i = mid, j = mid + 1; j <= r; j ++) {
		while (i >= l && maxv[j] > maxv[i]) /*printf("? %d %lld %d %lld\n", i, maxv[i], j, maxv[j]), */i --;
		
		int L = i + 1, R = mid, Mid, pos = i;
 
		while (L <= R) {
			Mid = L + R >> 1;
			if (sum[j] + sum[Mid] >= maxv[j] * 2) pos = Mid, L = Mid + 1;
			else R = Mid - 1;
		}

		//printf("%d %d %d\n", j, i, pos);
		ans += pos - i;
	}

	//printf("%d %d %d %lld\n", l, r, mid, ans);
	solve (l, mid);
	solve (mid + 1, r);
}

int main() {
	ios::sync_with_stdio(false);
	
	for (cin >> t; t --; ) {
		cin >> n; ans = 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i], s[i] = s[i - 1] + a[i];

		solve(1, n);
		cout << ans << '\n';
	}

	//cout << clock() << endl;
	return 0;
}