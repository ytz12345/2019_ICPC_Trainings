#include <bits/stdc++.h>

using namespace std;

map <int, int> p;

int n;

int x[4], y[4], z[8], a[10][10];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int t = 0; t < n; t ++) {
		for (int i = 0; i < 4; i ++)
			cin >> x[i] >> y[i], z[i * 2] = x[i], z[i * 2 + 1] = y[i];
		sort (z, z + 8);
		int k = unique(z, z + 8) - z;
		p.clear();
		for (int i = 0; i < k; i ++)
			p[z[i]] = i + 1;
		memset (a, 0, sizeof a);
		for (int i = 0; i < 4; i ++)
			x[i] = p[x[i]], y[i] = p[y[i]];
		for (int i = x[0]; i <= x[1]; i ++)
			for (int j = y[0]; j <= y[1]; j ++)
				a[i][j] = 1;
		int sum = 0;
		for (int i = x[2]; i <= x[3]; i ++)
			for (int j = y[2]; j <= y[3]; j ++)
				sum += a[i][j];
		int s1 = (x[1] - x[0] + 1) * (y[1] - y[0] + 1);
		int s2 = (x[3] - x[2] + 1) * (y[3] - y[2] + 1);
		if (sum == min(s1, s2)) {
			if (s1 < s2) puts("A in B");
			else puts("B in A");
		}
		else if (sum == 0) puts("Separate");
		else puts("Intersect");
	}
	return 0;
}