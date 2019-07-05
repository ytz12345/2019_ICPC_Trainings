#include <bits/stdc++.h>

using namespace std;

int n, m, k;

char s[233][233];

vector <int> h, v;

void no() {
	puts("NO");
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i ++) 
		cin >> s[i];
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cnt += s[i][j] == '1';
		}
		if (cnt > k) no();
		if (cnt == k) h.push_back(i + 1), cnt = 0;
	}
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) {
			cnt += s[j][i] == '1';
		}
		if (cnt > k) no();
		if (cnt == k) v.push_back(i + 1), cnt = 0;
	}
	printf("YES\n");
	for (int i = 0; i + 1 < k; i ++)
		printf("%d%c", h[i], i + 2 == k ? '\n' : ' ');
	for (int i = 0; i + 1 < k; i ++)
		printf("%d%c", v[i], i + 2 == k ? '\n' : ' ');
	return 0;
}