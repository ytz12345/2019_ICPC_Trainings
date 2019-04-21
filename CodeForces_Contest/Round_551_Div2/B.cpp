#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int h[110][110];

int a[110];

int main(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			h[i][j] = k;
	for (int i = 1; i <= m; i ++) {
		cin >> a[i];
		for (int j = 1; j <= n; j ++)
			h[j][i] = min(h[j][i], a[i]);
	}
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		for (int j = 1; j <= m; j ++)
			h[i][j] = min(h[i][j], a[i]);
	}
	for (int x, i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> x;
			if (!x) h[i][j] = 0;
			printf("%d ", h[i][j]);
		}
		puts("");
	}
	return 0;	
}
