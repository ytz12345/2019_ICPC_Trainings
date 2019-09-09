#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int kmp(int n, char *a) {
	static int nxt[N], i, j;
	for (nxt[0] = j = -1, i = 1; i < n; nxt[i ++] = j) {
		while (~j && a[j + 1] != a[i]) j = nxt[j];
		if (a[j + 1] == a[i]) j ++;
	}
	return nxt[n - 1];
}

int n, p;

char str[N], ans[N];

string s[100010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	for (int i = 0; i < s[0].size(); i ++)
		ans[p ++] = s[0][i];
	for (int i = 1; i < n; i ++) {
		int j = 0, len = s[i].size();
		while (j < len) str[j] = s[i][j], j ++;
		str[len] = '*';
		int ll = s[i - 1].size(); 
		for (j = 0; j < ll; str[len + 1 + j] = s[i - 1][j], j ++);
		for (j = kmp(len + ll + 1, str) + 1; j < len; j ++)
			ans[p ++] = s[i][j];
	}
	ans[p] = 0;
	puts(ans);
	return 0;
}