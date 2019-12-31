#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int Mod = 998244353;
const int N = 1e6 + 5;
const int K = 233;

char ans[N], s[N];

ll hh[N], hs[N], pw[N];

int n, p;

int main() {
	scanf("%d", &n); pw[0] = 1;
	for (int i = 1; i < N; i ++) pw[i] = pw[i - 1] * K % Mod;
	for (int t = 0; t < n; t ++) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for (int i = 1, j = len; i <= j; i ++)
			hs[i] = (hs[i - 1] * K % Mod + s[i]) % Mod;
		int pos = 1;
		for (int i = min(p, len); i >= 1; i --) {
			if (hs[i] == ((hh[p] - hh[p - i] * pw[i] % Mod) % Mod + Mod) % Mod) {
				pos = i + 1;
				break;
			}
		}
		for (int i = pos; i <= len; i ++) {
			ans[++ p] = s[i];
			hh[p] = (hh[p - 1] * K % Mod + s[i]) % Mod;
		}
	}
	ans[p + 1] = 0;
	puts(ans + 1);
	return 0;
}