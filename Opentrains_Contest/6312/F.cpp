#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll n, m;

ll a[N], b[N];

int q[N], r;

vector <int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> b[i];
	ll p1 = 0, p2 = 0, s1 = 0, s2 = 0;
	for ( ; ; s1 += a[++ p1]) 
		if (p1 + 1 > n || s1 + a[p1 + 1] > m) 
			break;
	for ( ; ; s2 += b[++ p2]) 
		if (p2 + 1 > n || s2 + b[p2 + 1] > m)
			break;
	//return 0;
	if (p1 > p2) return puts("0"), 0;
	if (p1 == 0) return puts("-1"), 0;
	//puts("!!!");
	ll sum = 0;
	for (int i = 1; i <= p1; i ++) sum += b[i];
	sum --; sum = m - sum;//least waste time
	r = 0;
	for (int i = 1; i <= p1; i ++) {
		while (r > 0 && b[q[r]] <= b[i]) r --;
		q[++ r] = i;
	}
	
	//printf("%lld %lld %lld\n", p1, p2, sum);

	int ia = 1, ib = 1; ll tim = 0, tt = 0;
	for (int i = 1; i <= r; i ++) {
		while (ib <= q[i]) tim += b[ib], tt += b[ib], ib ++;
		while (1) {
			if (!(ia <= n && tim >= a[ia] && tt <= m)) break;
			while (ia <= n && tim >= a[ia] && tt <= m) {
				sum -= b[q[i]];
				tim += b[q[i]], tim -= a[ia];
				ans.push_back(tt), tt += b[q[i]];
				ia ++; 
			}
		}
	}

	if (sum > 0) return puts("-1"), 0;

	printf("%d\n", int(ans.size()));
	for (int i : ans)
		printf("%d ", i);
} 