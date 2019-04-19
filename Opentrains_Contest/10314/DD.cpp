#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

const int P = 1e6 + 5;

const int inf = 1e9 + 7;

int p[N], v[N];

int f[P][8];

int main() {
	ios::sync_with_stdio(false);
	memset (f, 0, sizeof f);
	cout << f[1][2] << endl;
	for (int i = 2; i < P; i ++) {
		if (!v[i]) {
			p[++ p[0]] = i;
		}
		for (int j = 1; j <= p[0] && 1ll * i * p[j] < P; j ++) {
			v[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	cout << f[1][2] << endl;
	return 0;
}