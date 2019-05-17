#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
const int N = 1e5 + 7;
typedef vector<int> VI;
int n;
inline bool check(const VI &a) {
	rep(i, 1, n) 
		if (a[i] != i && a[a[i]] != i) return 1;
	return 0;
}
inline void getV(const VI &a, VI &b) {
	static int c[N];
	static bool vis[N];
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, n) 
	if (!vis[i]) {
		VI tmp;
		tmp.push_back(i);
		int k = a[i];
		while (k != i) {
			tmp.push_back(k);
			k = a[k];
		}
		for (int x: tmp) vis[x] = 1;
		int l = tmp.size();
		for (int i = 0; i < l; i ++) b[tmp[i]] = tmp[i];
		for (int i = 0; i + 2 < l; i += 3) {
			b[tmp[i]] = tmp[i + 2];
			b[tmp[i + 2]] = tmp[i]; 
		}
		// for (int i = 0; i < l; ++ i) cout << tmp[i] << ' '; cout << endl;
	}
}
inline void mul(VI &a, const VI &b) {
	static int c[N];
	rep(i, 1, n) c[i] = a[b[i]];
	rep(i, 1, n) a[i] = c[i];	
}
int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		VI a(n + 1), b(n + 1);
		vector<VI> ans;
		rep(i, 1, n) scanf("%d", &a[i]);
		while (check(a)) {
			// cout << "??" << endl;
			getV(a, b);
			mul(a, b);
			ans.push_back(b);
		}
		ans.push_back(a);
		int num = ans.size();
		printf("%d\n", num);
		for (int i = num - 1; i >= 0; -- i) {
			rep(j, 1, n) printf("%d%c", ans[i][j], j == n? '\n': ' ');
		}
	}
}