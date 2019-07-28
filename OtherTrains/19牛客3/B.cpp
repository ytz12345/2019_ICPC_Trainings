#include <bits/stdc++.h>

using namespace std;

int n;

char s[100010];

map <int, int> p;

int x, a, b;

int ans;

int main() {
	scanf("%d %s", &n, s + 1);
	p[0] = 0; 
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '1') {
			a ++;
			x ++;
		}
		else {
			b ++;
			x --;
		}
		if (p.find(x) != p.end()) {
			ans = max(ans, i - p[x]);
		}
		else {
			p[x] = i;
		}
	}
	printf("%d %d\n", ans, min(a, b) * 2);
	return 0;
}
