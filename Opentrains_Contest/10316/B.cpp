#include <bits/stdc++.h>

using namespace std;

int n, m;

string s[1010], t, r;

int c[1010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int p, i = 1; i <= n; i ++) {
		cin >> t, p = 0;
		r = t.substr(t.find('.') + 1);
		for (int j = 0; j < m; j ++)
			if (s[j] == r) {
				c[j] ++;
				p = 1;
				break;
			}
		if (p) continue;
		s[m] = r, c[m] = 1, m ++;
	}
	for (int i = 0; i < m; i ++)
		cout << s[i] << ": " << c[i] << '\n';
	return 0;
}