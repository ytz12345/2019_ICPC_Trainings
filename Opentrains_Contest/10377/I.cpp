#include <bits/stdc++.h>

using namespace std;

const int N = 5e7 + 5;

typedef unsigned int uint;

int n, m, q;

uint x0, x1, a, b, c;

uint d[N >> 1], f1, pw;

uint mmin, pos;

inline uint calc() {
	static uint t;
	t = x0 * a + x1 * b + c;
	x0 = x1, x1 = t;
	return x0 >> 2;
}

inline void update(const int &i, const uint &x) {
	if (x < mmin) mmin = d[i] = x, pos = i;
	else {
		d[i] = x;
		if (pos == i) {
			pos = 0, mmin = f1 + 1;
			for (int j = 1; j <= n; j ++)
				if (d[j] < mmin) 
					mmin = d[j], pos = j;		
		}
	}
}

int main() {
	uint p, x, ans = 0;
	f1 = pw = 1, f1 <<= 31, f1 --; mmin = f1, pos = 1;
	cin >> n >> q >> x0 >> x1 >> a >> b >> c;
	for (int i = 1; i <= n; i ++) d[i] = f1;
	for (int i = 1; i <= q; i ++) {
		p = calc() % n + 1, x = calc();
		update(p, x);
		ans += mmin * (pw *= 10099); 
	}	
	cout << ans << endl;
	return 0;
}