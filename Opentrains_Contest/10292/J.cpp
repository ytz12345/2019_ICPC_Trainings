#include <bits/stdc++.h>

using namespace std;

int n, m;

char s[100010];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		m = (n + 24) / 25 + 1; s[m] = 0; s[0] = 'a';
		for (int i = 1; i + 1 < m; i ++) {
			for (int j = 'a'; j <= 'z'; j ++) {
				if (abs(j - s[i - 1]) + max('z' - j, j - 'a') + (m - 1 - (i + 1)) * 25 >= n) {
					n -= abs((s[i] = j) - s[i - 1]);
					break;
				}
			}
		}
		if (s[m - 2] - n >= 'a') s[m - 1] = s[m - 2] - n;
		else s[m - 1] = s[m - 2] + n;
		puts(s); 
	}
	return 0;
}