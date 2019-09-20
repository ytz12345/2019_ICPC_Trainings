#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//typedef __int128 lll;

typedef pair<double, double> pr;

pr calc(double A, double B, double C) {
	double d = B * B - A * C * 4;
	if (d < 0) return pr(0, -1);
	d = sqrt(d);
	double x1 = (-B + d) / (A * 2), x2 = (-B - d) / (A * 2);
	if (x1 > x2) swap(x1, x2);
	return pr(x1, x2);
}

ll solve(ll n, ll k) {
	ll x = -1;
	pr pl = calc(1, -1, -2 * k), p = calc(-1, n * 2 + 1, -2 * k);
	pr ans = pr(max(pl.first, p. first), min(pl.second, p.second));
	x = ll(min(n + 1.0, ans.second));
	if (x < 0) return -1;
	if (x < ans.first) return -1;
	if (x == n + 1) return n * (n - 1) / 2;
	if (x == 0)     return n * (n - 1) / 2;
	return x * (x - 1) / 2 + (n - 1 - x) * (n - x) / 2;
}

int main() {
	ll n, k;
	cin >> n >> k;
	cout << max(solve(n, k), solve(n, (n + 1) * n / 2 - k));
	return 0;
}