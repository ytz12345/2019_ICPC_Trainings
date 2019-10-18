#include <bits/stdc++.h>

using namespace std;

const int N = 233;

int n, m;

int a[N], b[N], c[N];

char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++)
		a[i] = s[i - 1] - 'a';
	cin >> s;
	for (int i = 1; i <= m; i ++)
		b[i] = s[i - 1] - 'a';
	for (int i = m - n + 1, j = 1; i <= m; i ++)
		c[i] = a[j ++];
	for (int i = m - n; i >= 1; i --)
		c[i] = (b[i + n] - c[i + n] + 26) % 26;
	for (int i = 1; i <= m; i ++)
		putchar('a' + c[i]);
	puts("");
	return 0;
}