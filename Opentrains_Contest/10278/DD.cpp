#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef pair<int, int> P;
const int inf = 2e9;
pair<P, int> a[N];
int gcd(int a, int b) {
	if (!b) return a; return gcd(b, a % b);
}
P x[N], y[N], t1[N], t2[N]; int c[N], d[N];
vector<int> g[N];
int f[N], b[N];
int find(int u) {
	for (int v: g[u]) if (!b[v]) {
		b[v] = 1;
		if (!f[v] || find(f[v])) return f[v] = u, 1;
	}
	return 0;
}
map<P, int> mp;
int main() {
	int T, n;
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d%d%d", &a[i].first.first, &a[i].first.second, &a[i].second);
		}
		int id = -1;
		rep(i, 1, n) {
			int A = a[i].first.first, B = a[i].first.second, C = a[i].second;
			int d = gcd(A, B);
			if (B == 0) x[i] = P(inf, 0);
			else x[i] = P(A / d, B / d);
			d = gcd(C, B);
			if (B == 0) {
				if (C == 0) id = i;
				y[i] = P(inf, 0);
			}
			else y[i] = P(C / d, B / d);
			t1[i] = x[i];
			t2[i] = y[i];
		}
		
		sort(x + 1, x + 1 + n);
		int m1 = unique(x + 1, x + 1 + n) - x - 1;

		sort(y + 1, y + 1 + n);
		int m2 = unique(y + 1, y + 1 + n) - y - 1;
		
		rep(i, 1, n) {
			c[i] = lower_bound(x + 1, x + 1 + m1, t1[i]) - x;
			d[i] = lower_bound(y + 1, y + 1 + m2, t2[i]) - y; 
		}


		mp.clear();
		rep(i, 1, m1) g[i].clear();
		rep(i, 1, n) {
			if (a[i].first.second == 0 && a[i].second == 0) continue; 
			mp[P(c[i], d[i])] = i;
			g[c[i]].push_back(d[i]);
		}
		int ans = 0;
		rep(j, 1, m2) f[j] = 0;
		rep(i, 1, m1) {
			rep(j, 1, m2) b[j] = 0;
			if (find(i)) ans ++;
		}
		if (ans <= 1 && id != -1) {
			printf("1\n%d\n", id);
		}
		else {
			printf("%d\n", ans);
			vector<int>  v;
			rep(i, 1, m2) 
				if (f[i]) {
					v.push_back(mp[P(f[i], i)]);
				}
			for (int i = 0, l = v.size(); i < l; ++ i) printf("%d%c", v[i], i + 1 == l? '\n': ' ');
		}
	}
}

/*
2 2 
1 1 0
1 1 1
2
-1 1 1
-2 1 1
*/