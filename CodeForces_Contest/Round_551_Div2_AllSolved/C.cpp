#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

int n, p[N], pl[N];

int main() {
	scanf("%d%s", &n, s);
	if ((n & 1) || (s[0] == ')') || (s[n - 1] == '(')) {
		puts(":(");
		return 0;
	}
	s[0] = '(', s[n - 1] = ')';
	int l = 0, c = 0;
	for (int i = 1; i + 1 < n; i ++) {
		if (s[i] == '(') {
			pl[++ l] = i;
		}
		else if (s[i] == ')') {
			if (l > 0) l --;
			else if (c > 0) s[p[c --]] = '(';
			else {
				puts(":(");
				return 0;
			}
		}
		else {
			p[++ c] = i;
		}
	}
	if (l > c) {
		puts(":(");
		return 0;
	}
	for (int i = l, j = c; i > 0; i --, j --) {
		if (pl[i] > p[j]) {
			puts(":(");
			return 0;
		}
		s[p[j]] = ')';
	}
	for (int i = 1; i <= c - l; i ++) 
		s[p[i]] = i & 1 ? '(' : ')';
	puts(s);
	return 0;
}