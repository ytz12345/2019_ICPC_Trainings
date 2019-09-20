#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Mod = 1025436931;

struct matrix {
	ll c[3][3];

	void clear() {
		memset (c, 0, sizeof c);
	}

	matrix() {clear();}

	matrix operator * (const matrix &a) const {
		matrix res;
		for (int k = 0; k < 3; k ++)
			for (int i = 0; i < 3; i ++)
				for (int j = 0; j < 3; j ++)
					res.c[i][j] = (res.c[i][j] + c[i][k] * a.c[k][j]) % Mod;
		return res;
	}

	matrix operator ^ (ll k) const {
		matrix x = *this, res;
		for (int i = 0; i < 3; i ++) res.c[i][i] = 1;
		for (; k > 0; k >>= 1, x = x * x)
			if (k & 1) res = res * x;
		return res; 
	}
};	

ll f(ll x) {
	static matrix a, b;
	a.clear(), b.clear();
	a.c[0][0] = a.c[0][1] = 1, a.c[0][2] = 2;
	b.c[0][1] = b.c[0][2] = b.c[1][0] = b.c[1][1] = b.c[1][2] = b.c[2][2] = 1;

	if (x == 0) return 0;
	if (x == 1) return 1;
	if (x == 2) return 2;
	return (a * (b ^ (x - 2))).c[0][2];
}

ll t, n, m, x[2], y[2];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m >> x[0] >> y[0] >> x[1] >> y[1];
		if (abs(x[0] - x[1]) + abs(y[0] - y[1]) == 1) cout << 1;
		else if (abs(x[0] - x[1]) == abs(y[0] - y[1])) {
			cout << (f(abs(x[0] - x[1]) * 2 - 1 + abs(x[0] - (x[0] < x[1] ? 1 : n)) + abs(y[0] - (y[0] < y[1] ? 1 : m))) + Mod) % Mod; 
		}
		else if  (abs(x[0] - x[1]) < abs(y[0] - y[1])) {
			cout << (f((abs(x[0] - x[1]) + abs(y[0] - y[1])) - 1 - ((abs(x[0] - x[1]) + abs(y[0] - y[1])) & 1) 
				+ max(abs(x[0] - 1), abs(x[0] - n)) + abs(y[0] - (y[0] < y[1] ? 1 : m))) + Mod) % Mod; 
		}
		else {
			cout << (f((abs(x[0] - x[1]) + abs(y[0] - y[1])) - 1 - ((abs(x[0] - x[1]) + abs(y[0] - y[1])) & 1) 
				+ abs(x[0] - (x[0] < x[1] ? 1 : n)) + max(abs(y[0] - 1), abs(y[0] - m))) + Mod) % Mod; 
		}

		cout << '\n';
	}
}