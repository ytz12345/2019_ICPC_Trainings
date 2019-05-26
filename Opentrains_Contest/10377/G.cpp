#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int n = strlen(s);
	int ans = 0;
	if (s[0] == 'R') {
		if (s[n - 1] == 'L') ans = 1;
		else {
			for (int i = n - 1; i >= 0; i --) {
				ans ++;
				if (s[i] != 'R') break;
			}
		}
	}
	else {
		if (s[n - 1] == 'L') {
			for (int i = 0; i < n; i ++) {
				ans ++;
				if (s[i] != 'L') break;
			}
		}
		else {
			for (int i = 0; i < n; i ++) {
				if (s[i] != 'L') break;
				ans ++;
			}
			for (int i = n - 1; i >= 0; i --) {
				if (s[i] != 'R') break;
				ans ++;
			}
			if (ans != n) ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}