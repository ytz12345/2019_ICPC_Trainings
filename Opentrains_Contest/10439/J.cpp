#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull one = 1;

const int st[] = {0, 2, 3, 5, 8, 14, 27};

int n, lim;

vector <int> e[100];

int ans[100], path[100];

int dfs(int now, int num, ull used) {
	path[now] = num; 
	if (now >= lim) return 1;
	ull tmp = used;
	for (int i : e[num]) tmp |= one << i;
	for (int i : e[num])
		if ((used & (one << i)) == 0)
			if (dfs(now + 1, i, tmp))
				return 1;
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < (1 << n); i ++)
		for (int j = 0; j < (1 << n); j ++) {
			int k = i ^ j;
			if (k != 0 && k == (k & (-k))) e[i].push_back(j);
		}
	lim = st[n];
	dfs(1, 0, 1);
	cout << lim << endl;
	for (int i = 1; i <= lim; i ++) {
		for (int j = n - 1; j >= 0; j --)
			cout << (path[i] >> j & 1);
		cout << endl;
	}
}