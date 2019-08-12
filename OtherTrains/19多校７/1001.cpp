#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int A, B, C;

void cpy(char *a, char *b) {
	for (int i = 0; i < N; i ++)
		a[i] = b[i];
}

bool dq(char *aa, char *bb, char *cc) {
	static const int L = 2e5 + 2019;
	static char a[N], b[N], c[N], d[N];
	cpy(a, aa), cpy(b, bb), cpy(c, cc);
	int la = strlen(a);
	int lb = strlen(b);
	int lc = strlen(c);
	for (int i = la; i < L; i ++) a[i] = '0';
	for (int i = lc; i < L; i ++) c[i] = '0';
	for (int i = 0; i < L; i ++) {
		if (a[i] == c[i]) continue;
		if (a[i] > c[i]) return 0;
		break;
	}
	for (int i = L - 1; i >= 0; i --) {
		if (c[i] < a[i]) {
			c[i - 1] --;
			c[i] += 10;
		}
		d[i] = c[i] - a[i] + '0';
	}
	int pos = 0;
	while (pos < L && d[pos] == '0') pos ++;
	for (int i = 0; i < lb; i ++) {
		if (pos >= L || d[pos] != b[i])
			return 0;
		pos ++;
	}
	A = L - la, B = L - pos, C = L - lc;
	while (pos < L) if (d[pos ++] != '0') return 0;
	return 1;
}

bool cy(char *aa, char *bb, char *cc) {
	static const int L = 2e5 + 2019	;
	static char a[N], b[N], c[N], d[N];
	cpy(a, aa), cpy(b, bb), cpy(c, cc);
	int la = strlen(a);
	int lb = strlen(b);
	int lc = strlen(c);
	for (int i = la; i > 0; i --) a[i] = a[i - 1];
	for (int i = la + 1; i < L; i ++) a[i] = '0';
	a[0] = '0';
	for (int i = lc; i < L; i ++) c[i] = '0';
	for (int i = 0; i < L; i ++) {
		if (a[i] == c[i]) continue;
		if (a[i] > c[i]) return 0;
		break;
	}
	int last = 0;
	for (int i = L - 1; i >= 0; i --) {
		if (c[i] < a[i]) {
			c[i - 1] --;
			c[i] += 10;
		}
		d[i] = c[i] - a[i] + '0';
	}
	int pos = 0;
	while (pos < L && d[pos] == '0') pos ++;
	for (int i = 0; i < lb; i ++) {
		if (pos >= L || d[pos] != b[i])
			return 0;
		pos ++;
	}
	A = L - la - 1, B = L - pos, C = L - lc;
	while (pos < L) if (d[pos ++] != '0') return 0;
	return 1;
}

char a[N], b[N], c[N];

int t;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> a >> b >> c;
		if (dq(a, b, c) || cy(a, b, c)) printf("%d %d %d\n", A, B, C);
		else if (dq(b, a, c) || cy(b, a, c)) printf("%d %d %d\n", B, A, C);
		else puts("-1");
	}
	return 0;
}