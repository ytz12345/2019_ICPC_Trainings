#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> n; 
		while(1) {
			if (n % 7 == 0 && n % 4 != 0) {
				printf("%d\n", n);
				break;
			}
			n ++;
		}
	}
	return 0;
}