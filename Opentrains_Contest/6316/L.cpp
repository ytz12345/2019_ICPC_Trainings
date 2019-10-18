#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

const char *s1 = "Petyr";
const char *s2 = "Varys";

int n, a, b;

int c[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> a >> b; int mx = 0, sum = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		mx = max(mx, c[i]);
		sum ^= c[i] % (a + 1);
	}
	if (a != b) {
		if (mx > min(a, b)) {
			if (a > b) puts(s1);
			else {
				int cnt = 0, ss = 0; sum = 0;
				for (int i = 1; i <= n; i ++) {
					if (c[i] > a)
						cnt ++, ss += c[i];
					sum ^= c[i];
				}
				if (cnt > 1) puts(s2);
				else {
					sum ^= ss;
					puts((sum < ss && ss - sum <= a) ? s1 : s2); 
				}
			}
		}
		else puts(sum ? s1 : s2);
	}
	else puts(sum ? s1 : s2);
	return 0;
}