#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, a[N], b[N];

vector <int> ans;

ll min(const ll &x, const ll &y) {
	return x < y ? x : y;
}

ll max(const ll &x, const ll &y) {
	return x > y ? x : y;
}

ll calc1(int x) {
	ll res = 0;
	int i = 0, j = n - 1;
	for (; i < n; i ++) {
		while (j >= 0 && a[i] + b[j] >= x) j --;
		res += j + 1;
	}
	return res;
}

ll calc2(int x) {
	ll res = 0;
	int i = 0, j = n - 1;
	for (; j >= 0; j --) {
		while (i < n && a[i] + b[j] <= x) i ++;
		res += n - i;
	}
	return res;
}

int calc3(int x) {
	int res = -1;
	int i = 0, j = n - 1;
	for (; i < n; i ++) {
		while (j >= 0 && a[i] + b[j] >= x) j --;
		if (j >= 0) res = max(res, a[i] + b[j]);
	}
	return res;
}

int calc4(int x) {
	int res = 2e9 + 7;
	int i = 0, j = n - 1;
	for (; j >= 0; j --) {
		while (i < n && a[i] + b[j] <= x) i ++;
		if (i < n) res = min(res, a[i] + b[j]);
	}
	return res;
}

void calc5(int l, int r) {
	int i = 0, j = n - 1;
	for (; i < n; i ++) {
		while (j >= 0 && a[i] + b[j] > r) j --;
		for (int t = j; t >= 0 && a[i] + b[t] >= l; ans.push_back(a[i] + b[t]), t --);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	if (n <= 0) return 0;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) cin >> b[i];
	if (n == 1) {
		printf("%d\n", a[0] + b[0]);
		return 0;
	}
	sort (a, a + n);	
	sort (b, b + n);
	ll l, r, mid, L, R = -1;
	l = 0, r = 2e9 + 7;
	while (l <= r) {
		mid = l + r >> 1;
		if (calc1(mid) >= 1ll * n * (n - 1) / 2) L = mid, r = mid - 1;
		else l = mid + 1;
	}
	l = 0, r = 2e9 + 7;
	while (l <= r) {
		mid = l + r >> 1;
		if (calc2(mid) >= 1ll * n * n - 1ll * n * (n + 1) / 2) R = mid, l = mid + 1;
		else r = mid - 1;
	}
	ll tl = calc1(L), tr = calc2(R);
	int tmp;
	if (L <= R) {
		tmp = calc3(L);
		for (int i = 0, j = tl - 1ll * n * (n - 1) / 2; i < j; i ++)
			ans.push_back(tmp);
		calc5(L, R);
		tmp = calc4(R);
		for (int i = 0, j = tr - (1ll * n * n - 1ll * n * (n + 1) / 2); i < j; i ++)
			ans.push_back(tmp);
	}
	else {
		if (tl >= 1ll * n * (n + 1) / 2) {
			tmp = calc3(L);
			for (int i = 0, j = (1ll * n * (n + 1) / 2 - 1ll * n * (n - 1) / 2); i < j; i ++)
				ans.push_back(tmp);
		}
		else {
			for (int i = 0, j = (tl - 1ll * n * (n - 1) / 2); i < j; i ++)
				ans.push_back(R);
			for (int i = 0, j = (tr - (1ll * n * n - 1ll * n * (n + 1) / 2)); i < j; i ++)
				ans.push_back(L);
		}
	}
	sort (ans.begin(), ans.end());
	for (int i = 0, j = ans.size(); i < j; i ++)
		printf("%d%c", ans[i], i + 1 == j ? '\n' : ' ');
	return 0;
}