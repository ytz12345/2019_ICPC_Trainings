#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

typedef pair<piir, int> pr;

typedef long long ll;

const int N = 2e6 + 5;

int n;

ll c[N], ans;

int main() {
	scanf("%d", &n);
	for (int x; n --; ) {
		scanf("%d", &x);
		c[x] += 1;
	}
	for (int i = 1; i < N; i ++) {
		if (!c[i]) continue;
		for (int j = i + i; j < N; j += i)
			ans += c[i] * c[j];
		ans += c[i] * (c[i] - 1);
	}
	cout << ans;
	return 0;
}