#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int P = 31, D = 1000173169, M = 262143;

char t[N], s[N];

int n, pw[N];

int h[N], g[N];

int haaa(int *f, int l, int r) {
	return ((f[r] - 1ll * f[l - 1] * pw[r - l + 1] % D) % D + D) % D;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t >> n;
	int lt = strlen(t);
	pw[0] = 1; h[0] = 0;
	for (int i = 1; i < N; i ++) pw[i] = 1ll * pw[i - 1] * P % D;
	for (int i = 1; i <= lt; i ++) h[i] = (1ll * h[i - 1] * P + t[i - 1]) % D;
	while (n --) {
		cin >> s;
		int ls = strlen(s);
		g[0] = 0;
		for (int i = 1; i <= ls; i ++)
			g[i] = (1ll * g[i - 1] * P + s[i - 1]) % D;
		if (lt > ls) {
			int flag = 0;
			for (int i = ls; i <= lt; i ++) {
				if (haaa(h, i - ls + 1, i) == g[ls]) {
					flag = 1;
					break;
				}
			}
			puts(flag ? "my child!" : "oh, child!");
		}
		else if (lt < ls) {
			int flag = 0;
			for (int i = lt; i <= ls; i ++) {
				if (haaa(g, i - lt + 1, i) == h[lt]) {
					flag = 1;
					break;
				}
			}
			puts(flag ? "my teacher!" : "senior!");
		}
		else {
			puts(g[lt] == h[lt] ? "jntm!" : "friend!");
		}
	}
}
/*
jntm!
friend!
my child!
oh, child!
my teacher!
senior!
*/