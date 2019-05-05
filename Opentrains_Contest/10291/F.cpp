#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const int P = 1e9 + 9;

int p[N], v[N];

int n, a[N];

vector <int> yz[N];

double ans = 1e18;

vector <int> ans_path;

int tmp_path[N];

ll calc(ll x, ll k) {
	ll res = 1;
	for (x %= P; k > 0; x = x * x % P, k >>= 1)
		if (k & 1) res = res * x % P;
	return res;
}

void dfs(int now, int mmax, int id, double tmp) {
	if (tmp > ans) return;
	if (now == 1) {
		ans = tmp;
		ans_path.clear();
		for (int i = 0; i < id; i ++)
			ans_path.push_back(tmp_path[i]);
		return;
	}
	for (int i = yz[now].size() - 1; i > 0; i --) {
		if (yz[now][i] > mmax) continue;
 		tmp_path[id] = yz[now][i];
		dfs(now / yz[now][i], min(mmax, yz[now][i]), id + 1, tmp + (yz[now][i] - 1) * log(p[id + 2]));
	}
}

int main() {
	cin >> n;
	for (int i = 2; i < N; i ++) {
		if (!v[i]) {
			p[++ p[0]] = i;
			if (p[0] >= 30) break;
		}
		for (int j = 1; j <= p[0] && i * p[j] < N; j ++){
			v[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	for (int i = 1; i * i <= n; i ++) {
		if (n % i != 0) continue;
		a[++ a[0]] = i;
		if (i * i != n) a[++ a[0]] = n / i;
	}
	sort (a + 1, a + a[0] + 1);
	for (int i = 1; i <= a[0]; i ++) {
		for (int j = 1; j * j <= a[i]; j ++) {
			if (a[i] % j != 0) continue;
			yz[a[i]].push_back(j);
			if (j * j != a[i]) yz[a[i]].push_back(a[i] / j);
		}
		sort (yz[a[i]].begin(), yz[a[i]].end());
	}
	dfs(n, 1e9, 0, 0);
	ll res = 1;
	for (int i = 0; i < ans_path.size(); i ++) {
		res = res * calc(p[i + 2], (int)ans_path[i] - 1) % P;
	}
	cout << (res % P + P) % P << '\n';
	return 0;
} 