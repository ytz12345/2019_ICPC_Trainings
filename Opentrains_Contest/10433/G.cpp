#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, m, d, k;

char ans[N];

int main() {
	cin >> n >> d;
	if (n == d) {
		cout << 10 + d - 1 << endl;
		return 0;
	}
	k = d == 9 ? 8 : 9;
	m = (n + k - 1) / k;
	if (m == 1) {
		cout << n << endl;
		return 0;
	}
	for (int i = m - 1; i >= 0; i --) {
		if (n >= k) ans[i] = '0' + k, n -= k;
		else        ans[i] = '0' + n, n = 0;
	}
	if (ans[0] == '8' && d == 8) {
		ans[m] = 0;
		ans[0] --;
		putchar('1');
		puts(ans);
		return 0;
	}
	for (int i = 0; i < m; i ++) {
		if (ans[i] == '0' + d) {
			ans[i] ++;
			ans[i + 1] --;
			break;
		}
	}
	ans[m] = 0;
	puts(ans);
}