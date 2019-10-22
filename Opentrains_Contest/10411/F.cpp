#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

const int N = 1e6 + 6;

char s[N], t[N], p[N * 3];

int n, a[N], v[N];

int len[N], nxt[N * 3];

void no() {
	puts("-1");
	exit(0);
}

void work(int st) {
	int l = 0;
	for (int i = st; v[i] == 0; i = a[i])
		v[i] = 1, p[++ l] = s[i];
	for (int i = 1; i <= l; i ++)
		p[i + l] = p[i];

	nxt[1] = 0;
	for (int i = 2, j = 0; i <= l * 2; i ++) {
		while (j != 0 && p[j + 1] != p[i]) j = nxt[j];
		if (p[j + 1] == p[i]) j ++;
		nxt[i] = j;
		if (nxt[i] == l) {
			len[st] = i - l;
			return;
		} 
	}
}

int f1nd(int st) {
	int l = 0, ln = 0;
	for (int i = st; v[i] == 1; i = a[i])
		v[i] = 2, p[++ l] = t[i];
	ln = l, p[++ l]  = 0;
	for (int i = st; v[i] == 2; i = a[i])
		v[i] = 3, p[++ l] = s[i];
	for (int i = st; v[i] == 3; i = a[i])
		v[i] = 4, p[++ l] = s[i];

	nxt[1] = 0;
	for (int i = 2, j = 0; i <= l; i ++) {
		while (j != 0 && p[j + 1] != p[i]) j = nxt[j];
		if (p[j + 1] == p[i]) j ++;
		nxt[i] = j;
		if (nxt[i] == ln) 
			return i - ln - 1 - ln;
	}
	return -1;
}

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (!b) {
		d = a, x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, d, y, x);
	y -= a / b * x;
}

ll crt(ll *m, ll *a, int n) {
	ll A = a[1], M = m[1], d, x, y, m2;
	for (int i = 2; i <= n; i ++) {
		exgcd(M, m[i], d, x, y);
		if ((a[i] - A) % d) return -1;
		m2 = M / d * m[i];
		x = (a[i] - A) / d * x % m[i];
		A = (A + x * M % m2) % m2;
		if (A < 0) A += m2;
		M = m2;
	}
	return A;
}

int cnt;
ll A[N], m[N];

int main() {
	scanf("%s %s", s + 1, t + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i ++)
		if (i & 1) a[i] = (i + 1) >> 1;
		else       a[i] = (i >> 1) + n / 2;
	for (int i = 1; i <= n; i ++)
		if (!v[i]) {
			work(i);
			//printf("%d %d\n", i, len[i]);
		}
	for (int x, i = 1; i <= n; i ++) 
		if (v[i] != 4) {
			x = f1nd(i);
			if (x == -1) no();		
			cnt ++, m[cnt] = len[i], A[cnt] = len[i] - x;
		}
	ll ans = crt(m, A, cnt);
	if (ans == -1) no();
	cout << (long long)(ans) << endl;
	return 0;
}