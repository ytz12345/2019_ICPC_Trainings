#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int s[N][N], p[N][N];

char ans[N];

int n, l[3], x[3][1010], y[3][1010], t;

int main() {
	//#define DEBUG
	#ifndef DEBUG
		freopen("snakes2.in","r",stdin);
		freopen("snakes2.out","w",stdout);
	#endif
	cin >> n;
	for (int j = 0; j < n; j ++) {
		cin >> l[j];
		for (int i = 0; i < l[j]; i ++) {
			cin >> x[j][i] >> y[j][i];
			s[x[j][i]][y[j][i]] ++;
		}
	}
	for (int j = 0; j < n; j ++) {
		t = 0;
		for (int i = 0; i < l[j]; i ++) {
			if (s[x[j][i]][y[j][i]] == 2) {
				if (!p[x[j][i]][y[j][i]]) {
					p[x[j][i]][y[j][i]] ++;
					ans[t ++] = '+';
				}
				else{
					ans[t ++] = '-';
				}
			}
		}
		ans[t] = 0;
		puts(ans);
	}
	return 0;
}