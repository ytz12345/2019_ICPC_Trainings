#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

const int Mod = 1e9 + 7;

int n;

int f[N], s[N];

int main() {
	f[1] = s[1] = 1;
	for (int i = 2; i < N; i ++) {
		f[i] = (s[i / 2] + 1) % Mod;
		s[i] = (s[i - 1] + f[i]) % Mod;
	}
	cin >> n;
	cout << f[n];
	return 0;
}