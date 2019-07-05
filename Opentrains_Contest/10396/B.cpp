#include <bits/stdc++.h>

using namespace std;

int n, m, k, cnt, maxm;

map <int, int> p;

int judge(int x) {
	if (x < k) return 0;
	if (n / x < maxm) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int x, i = 1; i <= m; i ++) {
		cin >> x;
		p[x] ++;
	}
	for (auto i : p) {
		k = max(k, i.first);
		maxm = max(maxm, i.second);
	}
	for (int i = 1; i * i <= n; i ++) {
		if (n % i == 0) {
			cnt += judge(i);
			if (i * i != n) cnt += judge(n / i);
		}
	}
	return puts(cnt == 1 ? "YES" : "NO"), 0;
}