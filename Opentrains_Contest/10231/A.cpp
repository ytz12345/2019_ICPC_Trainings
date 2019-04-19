#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

long long dfs(int l, int r) {
	if (l > r) return 1;
	int c = 0;
	for (int i = l; i <= r; i ++) {
		if (s[i] == '(') c ++;
		else {
			c --;
			if (c == 0) 
				return (dfs(l + 1, i - 1) + 1) * dfs(i + 1, r);
		}
	}
}

int main() {
	freopen("bracket-expression.in","r",stdin);
	freopen("bracket-expression.out","w",stdout);
	cin >> s;
	cout << dfs(0, strlen(s) - 1);
	return 0;
}