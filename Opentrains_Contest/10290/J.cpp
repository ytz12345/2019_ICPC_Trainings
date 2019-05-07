#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 2e5 + 5;

int ans, n, m, a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	for (int k = 29; k >= 0; k --) {
		int sum = 0;
		for (int i = 0; i < n; i ++)
			sum ^= a[i] >> k & 1;
		if (!sum) {
			int t = 0;
			for (int i = 0; i < n; ) {
				b[t] = a[i];
				int j = i + 1;
				while (b[t] >> k & 1)
					b[t] ^= a[j ++];
				t ++;
				i = j;
			}
			if (t >= m) {
				n = t;
				for (int i = 0; i < n; i ++)
					a[i] = b[i];
			}
		}
	}
	for (int i = 0; i < n; i ++)
		ans |= a[i];
	cout << ans << endl;
	return 0;
}