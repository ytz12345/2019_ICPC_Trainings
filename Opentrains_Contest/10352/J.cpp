#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n, a[N];

struct point{ll x, y;}p[N];

void work(ll &ans) {
	ans = 0;
	for (int i = 0; i < n; i ++)
		a[i] = p[i].y;
	sort (a, a + n);
	for (int i = 0, j = n - 1; i < j; i ++, j --)
		ans += a[j] - a[i];
	for (int i = 0; i < n; i ++)
		a[i] = p[i].x;
	sort (a, a + n);
	for (int i = 0; i < n; i ++)
		a[i] -= i;
	sort (a, a + n);
	for (int i = 0, j = n - 1; i < j; i ++, j --)
		ans += a[j] - a[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	ll ans1, ans2;
	for (int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	work(ans1);
	for (int i = 0; i < n; i ++)
		swap(p[i].x, p[i].y);
	work(ans2);
	cout << min(ans1, ans2);
	return 0;
}