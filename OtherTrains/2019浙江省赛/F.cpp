#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n;

char s[N];

char *st = "aeiouy";

bool check(char ch) {
	for (int i = 0; i < 6; i ++)
		if (ch == st[i])
			return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> s;
		for (int i = 0, k = strlen(s); i < k; i ++) {
			if (!(i != 0 && check(s[i])))
				putchar(s[i]);
		}
		putchar('\n');
	}
	return 0;
}