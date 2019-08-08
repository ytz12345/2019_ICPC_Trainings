#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

ll a[30];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n;
		for (int i = n; i >= 0; i --)
			cin >> a[i];
		if (n > 2) puts("No");
		else if (n < 2) puts("Yes");
		else puts(a[1] * a[1] - a[0] * a[2] * 4 >= 0 ? "No" : "Yes");
	}
	return 0;
}