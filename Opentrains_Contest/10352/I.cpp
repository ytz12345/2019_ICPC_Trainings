#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5;

ll n, a[N];

ll x;

ll c, b[N], f[1000100];

ll calc() {
	f[1] = 0; f[0] = 0;
	for (int i = 1; i <= c; i ++)
		for (int j = i + 1; j <= c; j ++)
			if (b[i] != b[j])
				f[++ f[0]] = b[i] - b[j];
	ll M = f[1];
	for (int i = 2; i <= f[0]; i ++)
		M = __gcd(M, f[i]);
	return M;
}

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	cin >> n; int nn = n;
	for (int i = 1; i < n; i ++) {
		cin >> a[i];
	}
	n --;
	ll M = 0;
	int p = 1;
	for (int j = 0; j < 9; j ++) {
		c = 0;
		x = rand() % 100000000 + 900000001;
		for (int i = 0; i < 111; i ++) {
			a[++ n] = x;
			cout << "? " << a[n] << '\n';
			cout.flush();
			cin >> a[++ n];
			if (i != 0) {
				b[++ c] = a[n - nn - 1] + a[n - nn - 2] + a[n] - a[n - 2] * 2;
			}
			p += 2;
		}
		M = __gcd(M, calc());
	}
	
	cout << "! " << abs(M);
	cout.flush();
	return 0;
}