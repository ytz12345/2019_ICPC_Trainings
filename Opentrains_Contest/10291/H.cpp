#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, s, t;
	cin >> n >> s >> t;
	if (s > t) swap(s, t);
	if (s != 1 && t != n && s + 1 == t) {
		puts("-1");
	}
	else {
		int ans = 0; int x = s, y = t;
		if (s != 1) ans ++, s ++;
		if (t != n) ans ++, t --;
		if (x != y) printf("%d\n", ans + (t - s) / 3 + (t - s) % 3);
		else puts("-1");
		/*if (s == 1) {
			t --;
			printf("%d\n",  + 1);
		}
		else if (t == n) {
			s ++;
			printf("%d\n", (t - s) / 3 + (t - s) % 3 + 1);
		}
		else if (s != t) {
			s ++, t --;
			printf("%d\n", (t - s) / 3 + (t - s) % 3 + 2);
		}
		else {
			puts("-1");
		}*/
	}
}