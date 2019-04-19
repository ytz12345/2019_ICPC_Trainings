#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int p[N], v[N], n;

long long ans, c[N];

int main() {
	freopen("fourprimes.in","r",stdin);
	freopen("fourprimes.out","w",stdout);
	for (int i = 2; i < N; i ++) {
		if(!v[i]) p[++ p[0]] = i;
		for (int j = 1; j <= p[0] && i * p[j] < N; j ++) {
			v[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	cin >> n;
	for (int i = 1; i <= p[0]; i ++)
		for (int j = 1, k = n - p[i]; j <= p[0] && p[j] <= k; j ++)
			c[p[i] + p[j]] ++;
	for (int i = 0; i <= n; i ++)
		ans += c[n - i] * c[i];
	cout << ans << endl;
	return 0;
}