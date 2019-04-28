#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n;

char s1[N], s2[N];

int calc(char *str, int sum = 0) {
	for (char *s = str; *s; s ++)
		sum += (*s) - '0';
	return (sum % 3) == 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> s1 >> s2;
		printf("%d\n", calc(s1, -1) ^ calc(s2));
	}
	return 0;
}