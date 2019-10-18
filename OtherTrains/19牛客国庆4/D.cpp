#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;

char s[12][12];

inline void print(int i, int j) {
	putchar(s[i / a][j / b]);
	if (j + 1 == m * b) puts("");
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> a >> b) {
		for (int i = 0; i < n; i ++)
			cin >> s[i];
		for (int i = 0; i < n * a; i ++)
			for (int j = 0; j < m * b; j ++)
				print(i, j);
	}
}