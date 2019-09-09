#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

const int inf = 1e8;

int m, n;

ll x, a[N];

int c[100];

int d[200][200], f[200][200];

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	for (int i = 0; i < m; i ++) {
		cin >> x;
		if (x != 0) a[++ n] = x;
	}
	for (int i = 1; i <= n; i ++) {
		x = a[i];
		for (int j = 0; j < 60; j ++) 
			if (x & 1)
				c[j] ++; 
	}
	int flag = 0;
	for (int i = 0; i < 60; i ++)
		flag |= c[i] >= 3;
	if (flag) puts("3");
	else {
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (a[i] & a[j])
					d[i][j] = f[i][j] = 1;
				else
					d[i][j] = f[i][j] = 1e8;
		int ans = inf;
	    for (int k = 1; k <= n; k ++) {
	        for (int i = 1; i < k; i ++) 
	        	for (int j = i + 1; j < k; j ++) 
		            ans = min(ans, d[i][j] + f[i][k] + f[k][j]); 
	        for (int i = 1; i <= n; i ++) 
	        	for (int j = 1; j <= n; j ++) 
		            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	    }
		if (ans == inf) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}