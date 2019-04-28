#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n;

int a[N], b[N], c[N], d[N];

struct node {
	int i, cnt;
	bool operator < (const node &a) const {
		if (cnt != a.cnt) return cnt > a.cnt;
		return i < a.i;
	}
};

set <int> s1;

set <node> s2;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> n; s1.clear(), s2.clear();
		for (int i = 1; i <= n; i ++)
			cin >> a[i], c[i] = 0;
		for (int i = 1; i <= n; i ++) 
			c[a[i]] ++;
		for (int i = 1; i <= n; i ++) {
			if (c[i] == 0) continue;
			d[i] = c[i], s1.insert(i), c[i] *= 2;
			s2.insert((node){i, c[i]});
		}
		int flag = 1;
		//printf("%d\n", s1.size());
		for (int i = 1; i <= n; i ++) {
			if ((*s2.begin()).cnt > n + 1 - i) {
				flag = 0;
				break;
			}
			auto p = s1.begin();
			if (*p == a[i]) p ++;
			/*printf("%d %d %d %d\n", i, s1.size(), s2.size(), *p);
			for (auto i : s1)
				printf("! %d\n", i);
			for (auto i :s2)
				printf("? %d %d\n", i.i, i.cnt);*/
			s2.erase((node){a[i], c[a[i]]});
			c[a[i]] --;
			if (c[a[i]] > 0) s2.insert((node){a[i], c[a[i]]});
			s2.erase((node){*p, c[*p]});
			c[*p] --;
			if (c[*p] > 0) s2.insert((node){*p, c[*p]});
			if (!s2.empty() && (*s2.begin()).cnt > n - i) {
				int x = (*s2.begin()).i;
				if (x == a[i]) {
					flag = 0;
					break;
				}
				if (c[*p] > 0) s2.erase((node){*p, c[*p]});
				s2.insert((node){*p, ++ c[*p]});
				s2.erase((node){x, c[x]});
				c[x] --;
				if (c[x] > 0) s2.insert((node){x, c[x]});
				b[i] = x, d[x] --;
				if (d[x] == 0) s1.erase(x);
			}
			else {
				d[*p] --, b[i] = *p;
				if (d[*p] == 0) s1.erase(*p);
			}
			//printf("  %d\n", b[i]);
		}
		if (!flag) puts("Impossible");
		else {
			for (int i = 1; i <= n; i ++)
				printf("%d%c", b[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}