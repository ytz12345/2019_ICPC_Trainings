#include <bits/stdc++.h>

using namespace std;

char s[100010];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0, j = n - 1; i < j; )
		swap(s[i ++], s[j --]);
	for (int i = 0, j = 0; i < n; i ++) {
		j ++;
		if (i + 1 == n || s[i] != s[i + 1]) {
			if (s[i] == 'b') {
				if (j & 1) putchar('b');
			}
			else {
				j %= 6;
				if (j != 0) {
					j = 6 - j;
					while (j --) putchar(s[i]);
				}
			}
			j = 0;
		}
	}
}