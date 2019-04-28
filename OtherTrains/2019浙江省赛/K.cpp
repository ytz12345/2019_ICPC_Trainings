#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

typedef long long ll;
typedef unsigned long long ull;

int T, n;

char s[N], t[N];
char t1[2 * N];
int p[2 * N];
int f[2 * N];

bool check() {
	for (int i = 0; i < n; i ++)
		if (s[i] != t[i])
			return 0;
	return 1;
}

ll calc() {
	int tot = 0;
	t1[tot ++] = '$';
	for (int i = 0; i < n; i ++) {
		t1[tot ++] = s[i];
		t1[tot ++] = '#';
	}
	t1[tot - 1] = '%';
	int mx = 0, id = 0;
	for (int i = 0; i < n; ++ i) f[i] = 0;
	for (int i = 1; i <= tot; i ++) {
		if (mx > i) p[i] = min(mx - i, p[2 * id - i]);
		else p[i] = 1;
		while (t1[i + p[i]] == t1[i - p[i]]) p[i] ++;
		if (mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
	}
	for (int i = 1; i <= tot - 2; i ++) {
		int x = i - p[i] + 1, y = i + p[i] - 1;
		if ((x & 1) == 0) x ++;
		if ((y & 1) == 0) y --;
		if (x > y) continue;
		f[i / 2] ++;
		f[y / 2 + 1] --;
	}
	for (int i = 1; i < n; i ++)
		f[i] += f[i - 1];
	ll res = 0;
	for (int i = 0; i < n; i ++) 
		res += f[i];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &T);
	while (T --) {
		scanf("%s %s", s, t);
		n = strlen(s);
		if (check()) cout << calc() << '\n';
		else {
			int l = 0, r = n - 1;
			for (int i = 0; i < n; i ++)
				if (s[i] != t[i]) {
					l = i;
					break;
				}
			for (int i = n - 1; i >= 0; i --) 
				if (s[i] != t[i]) {
					r = i;
					break;
				}
			bool flag = 1;
			for (int i = l, j = r; i <= r; ++ i, -- j)
				if (s[i] != t[j]) {
					flag = 0;
					break;
				}
			if (!flag) {
				cout << 0 << '\n'; continue;
			}
			int ans = 1; l --; r;  ++;
			while (l >= 0 && r < n) {
				if (s[l] != t[r]) break;
				ans ++;
				l --; r ++;
			}
			cout << ans << '\n';
 		}
	}
}