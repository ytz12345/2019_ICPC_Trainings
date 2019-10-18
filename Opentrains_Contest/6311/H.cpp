#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int t, n, m;

int a[N], cnt;

int u[N], v[N];

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m;
		for (int i = 0; i < m; i ++)
			cin >> u[i] >> v[i];
		do {
			cnt = 0;
			for (int i = 1; i <= n; i ++)
				a[i] = rand() & 1;
			for (int i = 0; i < m; i ++)
				cnt += a[u[i]] == 1 && a[v[i]] == 0;
		} while (cnt < m / 4 + 1);
		printf("%d\n", cnt);
		for (int i = 0; i < m; i ++)
			if (a[u[i]] && !a[v[i]])
				printf("%d%c", i + 1, (-- cnt > 0) ? ' ' : '\n');
	}
}