#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, len;

char pk[20];

int f(char ch) {
	if (ch == 'A') return 1;
	if (ch == 'J') return 11;
	if (ch == 'Q') return 12;
	return 13; 
}

int shun(int *c) {
	for (int i = 1; i < 5; i ++)
		if (c[i] - c[i - 1] != 1)
			return 0;
	return 1;
}

int isEqual(int *c, int l, int r) {
	for (int i = l + 1; i < r; i ++)
		if (c[i] != c[l])
			return 0;
	return 1;
}

int isRoyal(int *c) {
	return c[0] == 1 && c[1] == 10 && c[2] == 11 &&
		c[3] == 12 && c[4] == 13;
}

struct node {
	char s[15];
	int c[10];
	map <int, int> p;
	int val;

	void init() {
		cin >> s >> pk;
		len = strlen(pk);
		for (int i = 0, j = 0; i < len; i ++, j ++) {
			if (!isdigit(pk[i])) c[j] = f(pk[i]);
			else if (pk[i] == '1') c[j] = 10, i ++;
			else c[j] = pk[i] - '0';
		}
		sort (c, c + 5);

		if (isRoyal(c)) val = 8000000;
		else if (shun(c)) val = 7000000 + c[0];
		else if (isEqual(c, 0, 4)) val = 6000000 + c[0] * 100 + c[4];
		else if (isEqual(c, 1, 5)) val = 6000000 + c[4] * 100 + c[0];
		else if (isEqual(c, 0, 3)) {
			if (isEqual(c, 3, 5)) val = 5000000 + c[0] * 100 + c[3];
			else val = 4000000 + c[0] * 100 + c[3] + c[4];
		}
		else if (isEqual(c, 2, 5)) {
			if (isEqual(c, 0, 2)) val = 5000000 + c[2] * 100 + c[0];
			else val = 4000000 + c[2] * 100 + c[0] + c[1];
		}
		else if (isEqual(c, 1, 4)) val = 4000000 + c[1] * 100 + c[0] + c[4];
		else {
			p.clear(); int sum = 0;
			for (int i = 0; i < 5; i ++)
				p[c[i]] ++, sum += c[i];
			if (p.size() == 3) {
				int cnt = 0; val = 3000000;
				for (int i = 4; i >= 0; i --) {
					if (i != 4 && c[i] == c[i + 1]) continue;
					if (p[c[i]] == 2) {
						if (cnt == 0) {
							val += c[i] * 10000;
							cnt = 1;
						}
						else {
							val += c[i] * 100;
						}
					}
					else {
						val += c[i];
					}
				}
			}
			else if (p.size() == 4) {
				for (int i = 4; i >= 0; i --)
					if (p[c[i]] == 2) {
						val = 2000000 + c[i] * 100 + sum - c[i];
						break;
					}
			}
			else val = 1000000 + sum;
		}
	}
 
	bool operator < (const node &a) const {
		if (val != a.val) return val > a.val;
		return strcmp(s, a.s) < 0;
	}
}a[N];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 0; i < n; i ++)
			a[i].init();
		sort (a, a + n);
		for (int i = 0; i < n; i ++) 
			puts(a[i].s);
	}
	return 0;
}