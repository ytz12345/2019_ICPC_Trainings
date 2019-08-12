#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

char s[N];

char st[N];

int top, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	int n = strlen(s);
	for (int i = 0; i < n; i ++) {
		st[++ top] = s[i];
		while (top >= 3 && st[top] == st[top - 1] && st[top] == st[top - 2]) top -= 3, cnt ++;
	}
	cout << cnt << endl;
	return 0;
}