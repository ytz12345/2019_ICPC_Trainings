#include <bits/stdc++.h>

using namespace std;

int t;

char s[2019], a[2019];

int c[3];// h d w

int f(char ch) {
	if (ch == 'h') return 0;
	if (ch == 'd') return 1;
	return 2;
}

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt ++) {
		c[0] = c[1] = c[2] = 0;
		scanf("%s %s", s, a);
		int len = strlen(s);
		for (int i = 0; i < len; i ++) {
			for (int j = 0; j < 26; j ++)
				if (s[i] == 'a' + j) 
					c[f(a[j])] ++;
		}
		if (c[0] * 4 >= len) printf("Case #%d: Harmful", tt);
		else if (c[0] * 10 <= len) printf("Case #%d: Recyclable", tt);
		else if (c[1] >= c[2] * 2) printf("Case #%d: Dry", tt);
		else printf("Case #%d: Wet", tt);

		puts("");
	}

	return 0;
}