#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 6;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (!b) {
		d = a, x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, d, y, x);
	y -= a / b * x;
}

ll crt(ll *a, ll *m, int n) {//n个式子: y = mx + a, 下标从1开始
	ll A = a[1], M = m[1], d, x, y, m2;
	for (int i = 2; i <= n; i ++) {// k1 * m1 - k2 * m2 = a2 - a1
		exgcd(M, m[i], d, x, y);
		if ((a[i] - A) % d) return -1;
		m2 = M / d * m[i];
		x = (a[i] - A) / d * x % m[i];
		A = (A + x * M % m2) % m2;
		if (A < 0) A += m2;//保证A>=0
		M = m2;
	}  
	return A;//y = Mx + A
}

int nxt[N];

int kmp(int n, char *a, int m, char *b, ll &k, ll &bb) {
	//长度为m的b中找a,下标从0开始,得到的是匹配成功的末尾位置
	static int i, j, cnt, tmp[2]; cnt = 0;
	for (nxt[0] = j = -1, i = 1; i < n; nxt[i ++] = j) {
		while (~j && a[j + 1] != a[i]) j = nxt[j];
		if (a[j + 1] == a[i]) j ++;
	}
	for (j = -1, i = 0; i < m; i ++) {
		while (~j && a[j + 1] != b[i]) j = nxt[j];
		if (a[j + 1] == b[i]) j ++;
		if (j == n - 1) {
			tmp[cnt ++] = i;
			if (cnt == 2) break; 
			//printf("%d ", i);
			j = nxt[j];
		}
	}
	if (cnt == 0) return -1;
	else {
		if (cnt == 1) k = n;
		else k = tmp[1] - tmp[0];
		bb = tmp[0] - n + 1;
		return 1;
	}
}

char s[N], t[N];

int n, m, a[N], vis[N];

vector <int> lop[N];

ll k[N], b[N];

char s1[N * 2], s2[N];

int work(int id) {
	int len = lop[id].size();
	if (kmp(len, s2, len * 2, s1, k[id], b[id]) == -1) return -1;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n / 2; i ++) {
		a[i] = i * 2 - 1;
		a[i + n / 2] = i * 2;
	}
	for (int i = 1; i <= n; i ++) {
		if (vis[i]) continue;
		m ++;
		for (int j = i; ; j = a[j]) {
			if (vis[j]) break;
			vis[j] = 1;
			lop[m].push_back(j);
		}
	}
	for (int i = 1; i <= m; i ++) {
		for (int j = 0; j < lop[i].size(); j ++) {
			s1[j] = s1[j + lop[i].size()] = s[lop[i][j]];
			s2[j] = t[lop[i][j]];
		}
		if (work(i) == -1) return puts("-1"), 0;
	}
	printf("%lld\n", crt(b, k, m));
	return 0;
}