#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) 
		printf("1/%lld\n", n * m / __gcd(n, m) * 2);
}