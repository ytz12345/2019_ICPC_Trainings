#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
typedef pair<int, int> P;
const int N = 1e6 + 7;
bool isp[N];
int pr[N], f[N], pre[N], mu[N];
set<int>s;
int sieve() {
	memset(isp, 1, sizeof(isp));
	f[1] = pre[1] = 1;
	bool flag = 1;
	rep(i, 2, N - 1) {
		if (isp[i]) {
			pr[++ pr[0]] = i; 
			if (!f[i]) f[i] = (pr[0] & 1)? -1: 1;
		}
		pre[i] = pre[i - 1] + f[i];
		if (abs(pre[i]) > 20) flag = 0;
		rep(j, 1, pr[0]) {
			if (1ll * i * pr[j] >= N) break;
			isp[i * pr[j]] = 0;
			f[i * pr[j]] = f[i] * f[pr[j]];
			if (i % pr[j] == 0) {
				break;
			}
		}
	}
	return flag;
}
int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
	31, 37, 41, 53, 57};
void dfs(int x) {
	if (x == 15) {
		memset(f, 0, sizeof(f));
		sieve();
		int l = -1e9, r = 1e9;
		rep(i, 1, N - 1) r = min(r, pre[i]), l = max(l, pre[i]);
		cout << r << ' ' << l << endl;
		return;
	}
	f[a[x]] = -1;
	dfs(x + 1);
	f[a[x]] = 1;
	dfs(x + 1);
}
int main() {
	dfs(0);
}