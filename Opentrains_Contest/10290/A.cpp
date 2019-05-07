#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, int> piir;

const int N = 2e5 + 5;

ll n, m, x, y;

ll a[N], b[N];

priority_queue <piir, vector<piir>, greater<piir>> q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if(i != 0) q.push(piir(a[i], i));
	}
	ll ans = a[0] + y;
	if (n == 1) {cout << ans + m * x << endl; return 0;}
	ll z = a[0] + y + m * x;
	piir now;
	int last = -1;
	for (int i = 0; i < m; i ++) {
		if (z - q.top().first > x) {
			now = q.top(); q.pop();
			last = now.first;
			q.push(piir(now.first + x, now.second));
			z -= x; b[now.second] ++;
		}
		else break;
	}
	ans = max(ans, z);
	if (last != -1 && y >= z - last);
		ans = max(ans, last + x);
	cout << ans << endl;
	return 0;
}