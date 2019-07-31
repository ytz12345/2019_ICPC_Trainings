#include <bits/stdc++.h>

using namespace std;

int t, n;

int a[20];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		int cnt = 0;
		for (int i = 0; i < 16; i ++) {
			cin >> a[i];
			if (a[i] == 0) {
				a[i] = 16;
				cnt += i % 4 + i / 4;
			}
		}
		for (int i = 0; i < 16; i ++)
			for (int j = i + 1; j < 16; j ++)
				cnt += a[i] > a[j];
		puts(cnt & 1 ? "No" : "Yes");
	}
	return 0;
}