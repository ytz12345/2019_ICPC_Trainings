#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

priority_queue <ll, vector<ll>, greater<ll> > q;

int cnt;

int a[100];

bool isp(ll x) {
	for (ll i = 2; i * i <= x; i ++)
		if (x % i == 0)
			return 0;
	return 1;
}

bool calc(ll x) {
	
	char str[20];
	int cnt = 0;
	while (x) str[cnt++] = x%10, x/=10;
	for(int i=cnt-1;i >=0; i--) {
		x = 0;
		for (int j = i; j >= 0; j --) {
			x = x * 10 + str[j];
			if (!isp(x)) return 0;
		}
	}
	return 1;
}

int main() {
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(7);
	while (!q.empty()) {
		ll now = q.top(); q.pop();
		if (!calc(now)) continue;
		//printf("%d %lld\n", ++ cnt, now);
		a[++ cnt] = now;
		ll tmp = now, pw = 1;
		int x = 0;
		while (tmp > 0) {
			x = tmp;
			pw *= 10;
			tmp /= 10;
		}
		if (x == 2 || x == 5) continue;
		q.push(pw * 2 + now);
		q.push(pw * 3 + now);
		q.push(pw * 5 + now);
		q.push(pw * 7 + now);
	}
	int x;
	cin >> x;
	if (x > cnt) puts("-1");
	else printf("%d\n", a[x]); 
	return 0;
}