#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

struct node {
	int u, v, id;
}a[N], c[N];

int n, b[N], d[N], f[N], used[N], flag[N];

int tim;

bool judge(int k) {
	for (int i = 1, j = n - k + 1; i <= k; i ++, j ++)
		if (a[i].u >= b[j])
			return 0;
	return 1;
}

bool ok(int sum, int k) {
	//cout << sum << ' ' << k << endl;
	int i = 0, j = sum + 1;
	for (int ii = 1; ii <= k; ii ++) {
		j --;
		while (flag[j]) j --;
	}
	//cout << j << ' '<< tim << endl;
	for (int ii = 1; ii <= k; ii ++) {
		i ++;
		while (c[i].id <= tim) i ++;
		while (flag[j]) j ++;
		//cout << i << ' ' << j << endl;
		if (c[i].u >= d[j]) return 0;
		j ++;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].u, a[i].id = i;
	for (int i = 1; i <= n; i ++)
		cin >> b[i];
	sort (a + 1, a + n + 1, [&](node a, node b){
		return a.u < b.u;
	});
	sort (b + 1, b + n + 1);
	int l = 0, r = n, mid, ans = 0, pos;
	while (l <= r) {
		mid = l + r >> 1;
		if (judge(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	for (int i = 1; i <= n; i ++)
		c[i] = a[i];
	sort (a + 1, a + n + 1, [&](node a, node b){
		return a.id < b.id;
	});
	//cout << ans << endl;
	for (int i = 1; i <= n; i ++) {
		int k = 0; tim = i;
		for (int j = 1; j <= n; j ++)
			if (!used[j])
				d[++ k] = b[j], f[k] = j;
		l = upper_bound(d + 1, d + k + 1, a[i].u) - d, r = k, pos = -1;
		//cout << "i = " << i << endl;
		while (l <= r) {
			mid = l + r >> 1; 
			flag[mid] = 1;
			//cout << "mid = " << mid << endl;
			if (ok(k, ans - 1)) pos = mid, l = mid + 1;
			else r = mid - 1;
			flag[mid] = 0;
		}
		if (pos != -1) {
			ans --;
		}
		else {
			l = 1, r = upper_bound(d + 1, d + k + 1, a[i].u) - d - 1, pos = 1;
			while (l <= r) {
				mid = l + r >> 1;
				flag[mid] = 1;
				if (ok(k, ans)) pos = mid, l = mid + 1;
				else r = mid - 1;
				flag[mid] = 0;
			}
		}
		printf("%d%c", d[pos], i == n ? '\n' : ' ');
		used[f[pos]] = 1;
		
	}
	return 0;
}