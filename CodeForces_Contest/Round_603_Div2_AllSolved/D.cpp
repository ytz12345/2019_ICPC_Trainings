#include<bits/stdc++.h>

using namespace std;

char s[100];

int a[30], f[30];

int n, ans;

int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}

void un(int x, int y) {
	x = fa(x - 'a' + 1), y = fa(y - 'a' + 1);
	if (y != x) f[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= 26; i ++)
		f[i] = i;
	for (int i = 0; i < n; i ++) {
		cin >> s;
		for (int j = 0; s[j]; j ++) a[s[j] - 'a' + 1] = 1;
		for (int j = 1; s[j]; j ++) un(s[j - 1], s[j]);
	}
	for (int i = 1; i <= 26; i ++)
		ans += a[i] == 1 && fa(i) == i;
	cout << ans << endl;
	return 0;
}