#include <bits/stdc++.h>

using namespace std;

int c[3];

char s[100010];

long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int n = strlen(s);
	int x = 0; c[0] = 1;
	for (int i = 0; i + 2 < n; i ++) {
		x = (x + s[i] - '0') % 3;
		c[x] ++;
		if (s[i + 1] == '0' && s[i + 2] == '0') ans += c[x];
	}
	for (int i = 0; i < n; i ++)
		ans += s[i] == '0';
	if (s[0] == '0' && s[1] == '0') ans ++;
	cout << ans << endl;
	return 0;
}