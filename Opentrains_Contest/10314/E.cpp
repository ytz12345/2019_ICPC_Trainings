#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pr;

const ll inf = 1e18;

const int N = 1e5 + 5;

int n;

vector <pr> a, b;

int main() {
	ios::sync_with_stdio(false);
	cin >> n; a.resize(n);
	for (int i = 0; i < n; i ++)
		cin >> a[i].se >> a[i].fi;
	sort (a.begin(), a.end());
	//reverse(a.begin(), a.end());
	int p = -1;
	for (int i = 1; i < n; i ++)
		if (a[i].fi > a[0].fi + 1) {
			p = i;
			break;
		}
	if (p == -1) {
		cout << -1;
		return 0;
	}
	for (int i = n - 1; i > p; i --)
		b.push_back(a[i]);
	if (a[p].se != 1) b.push_back(pr(a[p].fi, a[p].se - 1));
	ll sum = a[p].fi, s2 = 1;
	for (int i = 0; i < p; i ++)
		sum += a[i].fi * a[i].se, s2 += a[i].se;
	ll tmp = a[p].fi - 1;
	while (s2 > 0) {
		tmp = min(tmp, sum - (s2 - 1));
		ll l = 1, r = s2, mid, cnt = 1;
		while (l <= r) {
			mid = l + r >> 1;
			if (mid <= inf / tmp && mid * tmp + (s2 - mid) <= sum) cnt = mid, l = mid + 1;
			else r = mid - 1;
		}
		b.push_back(pr(tmp, cnt));
		s2 -= cnt, sum -= tmp * cnt;	
	}
	/*if (n == 1) {
		cout << -1;
		return 0;
	}
	if (n == 2){
		if (a[0].fi == a[1].fi + 1) {
			cout << -1;
			return 0;
		}
		else {
			a[0].se --;
			a[1].se --;
			if (a[0].fi == a[1].fi + 2) {
				a.push_back(pr(a[0].fi - 1, 2));
			}
			else {
				a.push_back(pr(a[0].fi - 1, 1));
				a.push_back(pr(a[1].fi + 1, 1));
			}
		}
	}
	else {
		if (a[n - 2].fi == a[n - 1].fi + 1) {

		}
		else {
			a[n - 2].se --;
			a[n - 1].se --;
			if (a[n - 2].fi == a[n - 1].fi + 2) {
				a.push_back(pr(a[n - 2].fi - 1, 2));
			}
			else {
				a.push_back(pr(a[n - 2].fi - 1, 1));
				a.push_back(pr(a[n - 1].fi + 1, 1));
			}
		}
	}
	for (auto i : a)
		if (i.se != 0)
			ans.push_back(i);
	sort (ans.begin(), ans.end(), [&](pr x, pr y){return x > y;});*/
	cout << b.size() << endl;
	for (auto i : b)
		cout << i.se << ' ' << i.fi << '\n';
	return 0;
}
