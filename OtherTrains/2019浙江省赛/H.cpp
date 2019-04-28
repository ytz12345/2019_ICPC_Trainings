#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, m, ans;

int a[N],b[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> n; m = 0; ans = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for (int i = 2; i < n; i ++)
			if (a[i - 1] < a[i] && a[i] > a[i + 1])
				b[i] = 1, m ++;
			else 
				b[i] = 0;
		if (n == 3) {
			ans = b[2];
		}
		else {
			for (int i = 2; i < n; i ++) {
				if (i == 2) {
					ans = max(ans, b[2] + b[3] - (a[3] > a[1] && a[3] > a[4]));
				}
				else if (i == n - 1) {
					ans = max(ans, b[n - 1] + b[n - 2] - (a[n - 2] > a[n] && a[n - 2] > a[n - 4]));
				}
				else {
					ans = max(ans, b[i] + b[i - 1] + b[i + 1] 
						- (a[i - 1] > a[i - 2] && a[i - 1] > a[i + 1]) 
						- (a[i + 1] > a[i + 2] && a[i + 1] > a[i - 1]));
				}
			}
		}
		printf("%d\n", m - ans);
	}
	return 0;
}