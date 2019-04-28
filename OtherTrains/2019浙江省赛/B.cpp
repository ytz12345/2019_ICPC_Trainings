#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

inline int get_char() {
	static const int SIZE = 1 << 20;
	static char *S, *T = S, buf[SIZE];
	if (S == T) {
		T = fread(buf, 1, SIZE, stdin) + (S = buf);
		if (S == T) return -1;
	}
	return *S ++;
}

inline void in(ll &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

ll t, n, x, y, z, xx, yy, ans, a[N];

int calc(int i, ll ai) {
	ll tmp = z - ai;
	ll xxx = xx - x - i * ai + i * tmp;
	if (tmp == ai) return 0;
	if (xxx % (tmp - ai) != 0) return 0;
	ll p1 = xxx / (tmp - ai);
	if (p1 > n || p1 <= 0) return 0;
	if (a[p1] != tmp) return 0;
	ll yyy = yy - y - i * ai * ai + i * tmp * tmp;
	if (yyy % (tmp * tmp - ai * ai) != 0) return 0;
	ll p2 = yyy / (tmp * tmp - ai * ai);
	if (p2 > n || p2 <= 0) return 0;
	if (a[p2] != tmp) return 0;
	if (p1 != p2) return 0;
	return 1;
}

map <ll, ll> p;

int main() {
	auto st = clock();
	srand(time(NULL));
	ios::sync_with_stdio(false);
	in(t);
	while (t --) {
		xx = 0, yy = 0, ans = 0;
		in(n), in(x), in(y);
		for (ll i = 1; i <= n; i ++)
			in(a[i]), xx += i * a[i], yy += i * a[i] * a[i];
		if (x == xx) {
			if (y == yy) {
				p.clear();
				for (int i = 1; i <= n; i ++)
					p[a[i]] ++;
				for (auto i : p)
					ans += (i.second * (i.second - 1)) / 2;
				cout << ans << '\n';
			}
			else {
				cout << "0\n";
			}
		}
		else {
			if ((y - yy) % (x - xx) != 0) {
				cout << "0\n";
			}
			else {
				z = (y - yy) / (x - xx);
				for (int i = 1; i <= n; i ++) 
					ans += calc(i, a[i]);	
				cout << ans / 2 << '\n';	
			}
		}
	}
	return 0;
}
