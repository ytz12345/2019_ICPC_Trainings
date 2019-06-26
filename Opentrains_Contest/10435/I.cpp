#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int sg[N], used[N];

int main() {
	ios::sync_with_stdio(false);
	sg[0] = 0, sg[1] = 0;
	for (int c, i = 2; i < N; i ++) {
		memset (used, 0, sizeof used), c = 0;
		for (int j = 0; j <= i - 2; j ++) {
			used[sg[j] ^ sg[i - 2 - j]] = 1;
			while (used[c]) c ++;
		}
		sg[i] = c;
 	}
 	int t, n;
 	for (cin >> t; t --; ) {
 		cin >> n;
 		puts(sg[n] ? "First" : "Second");
 	}
 	return 0;
}