#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

const char *alp = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

const int holes[] = {
	0, 1, 2, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

ll n, k;

char s[N];

int idx(char c) {
	for (int i = 0; i < 52; i ++)
		if (alp[i] == c)
			return i;
	return -1;
}

int d[100][2];

int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i < 52; i ++) {
		d[i][0] = d[i][1] = -1;
		for (int j = i, k = 0; k < 52; k ++, j ++) {
			if (j >= 52) j = 0;
			if (holes[j] == holes[i] && d[i][1] == -1) d[i][1] = k;
			if (holes[j] < holes)
		}
	}
	cin >> n >> k >> s;

	return 0;
}