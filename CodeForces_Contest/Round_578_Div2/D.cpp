#include <bits/stdc++.h>

using namespace std;

typedef long log ll;

const int N = 1e5 + 5;

int m, n;

ll x, a[N];

int f[200][200];

int main() {
	ios::sync_with_stdio(false);
	cin >> m;
	for (int i = 0; i < m; i ++) {
		cin >> x;
		if (x != 0) a[++ n] = x;
	}
	if (n >= 180) puts("3");
	else {
		int ans = -1;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				f[i][j] = (a[i] & a[j]) != 0;
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= n; j ++)
				if (f[i][j] == -1)
	}
	return 0;
}