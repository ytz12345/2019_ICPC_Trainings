#include <bits/stdc++.h>

using namespace std;

int main() {
	int x;
	char s[5];
	ios::sync_with_stdio(false);
	for (int i = 1; ; i ++) {
		printf("%d\n", i);
		fflush(stdout);
		cin >> s;
		if (s[0] == 'y') {
			if (i == 1) return 0;
			else {
				printf("%d\n", 1);
				fflush(stdout);
				cin >> s;
				if (s[0] == 'y') return 0;
			}
		}
	}
}
