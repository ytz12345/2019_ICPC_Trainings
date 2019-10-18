#include <bits/stdc++.h>

using namespace std;

int n, k, q;

char str[111][111];

char s[111], t[111];

int main() {
	cin >> n >> k >> q;
	for (int i = 0; i < q; i ++) {
		puts("?");
		fflush(stdout);
		cin >> str[i];
	}
	int last = -1;
	for (int i = 0; i < n; i ++) {
		int c = 0;
		for (int j = 0; j < q; j ++)
			if (str[j][i] == '1') c ++;
			else c --;
		if (abs(c) > 40) {
			if (c > 0) s[i] = t[i] = '1';
			else       s[i] = t[i] = '0';
		}
		else {
			if (last < 0) {
				s[i] = '0';
				t[i] = '1';
			}
			else {
				c = 0;
				for (int j = 0; j < q; j ++)
					if (str[j][last] == s[last])
						if (str[j][i] == '1') c ++;
						else c --;
				s[i] = '0' + (c >= 0);
				t[i] = s[i] ^ 1; 
			}
			last = i;
		}
	}
	s[n] = t[n] = 0;
	printf("! %s %s\n", s, t);
	fflush(stdout);
	return 0;
}