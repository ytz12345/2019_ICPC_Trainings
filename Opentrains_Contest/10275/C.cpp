#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

inline void ask(int i, int j) {
	printf("? %d %d\n", i, j);
	fflush(stdout);
}

struct node {
	int cmp_l, cmp_r, cmp_sma;
	int from_l, from_r;
}a[N];

int cnt, pos[N], pos_t[N];

char str[5];

void work(int *c, int n) {
	int last = cnt;
	for (int i = 1; i < n; i += 2) {
		cnt ++;
		a[cnt].from_l = a[cnt].from_r = -1;
		a[cnt].cmp_l = c[i], a[cnt].cmp_r = c[i + 1];
		ask(a[cnt].cmp_l, a[cnt].cmp_r);
		cin >> str;
		a[cnt].cmp_sma = str[0] == '<' ? a[cnt].cmp_l : a[cnt].cmp_r;
	}
	if (n & 1) {
		cnt ++;
		a[cnt].from_l = a[cnt].from_r = -1;
		a[cnt].cmp_l = a[cnt].cmp_r = a[cnt].cmp_sma = c[n];
	}
	n = (n + 1) / 2;
	
	while (n != 1) {
		int tmp_last = cnt;

		for (int i = 1; i < n; i += 2) {
			cnt ++;
			a[cnt].from_l = last + i;
			a[cnt].from_r = last + i + 1;
			a[cnt].cmp_l = a[a[cnt].from_l].cmp_sma;
			a[cnt].cmp_r = a[a[cnt].from_r].cmp_sma;
			ask(a[cnt].cmp_l, a[cnt].cmp_r);
			cin >> str;
			a[cnt].cmp_sma = str[0] == '<' ? a[cnt].cmp_l : a[cnt].cmp_r;
		}
		if (n & 1) {
			cnt ++;
			a[cnt].from_l = last + n;
			a[cnt].from_r = last + n;
			a[cnt].cmp_l = a[a[cnt].from_l].cmp_sma;
			a[cnt].cmp_r = a[a[cnt].from_r].cmp_sma;
			a[cnt].cmp_sma = a[cnt].cmp_l;
		}

		last = tmp_last;
		n = (n + 1) / 2;
	}
}

int c[N];

bool judge(int x, int t) {
	for (int i = 1; i <= t; i ++)
		if (x == pos[i])
			return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		c[i] = i;
	work(c, n);
	pos_t[1] = cnt;
	pos[1] = a[cnt].cmp_sma;
	/*printf("%d %d %d\n", 1, pos[1], pos_t[1]);
	for (int i = 1; i <= cnt; i ++)
		printf("%d %d %d\n", a[i].cmp_l, a[i].cmp_r, a[i].cmp_sma);*/

	for (int i = 2; i <= k; i ++) {
		n = 0;
		for (int j = 1; j < i; j ++) {
			for (int t = pos_t[j]; t > 0; ) {
				if (a[t].cmp_l == pos[j]) {
					c[++ n] = a[t].cmp_r;
					t = a[t].from_l;
				}
				else {
					c[++ n] = a[t].cmp_l;
					t = a[t].from_r;
				}
			}
		}
		sort (c + 1, c + 1 + n);
		n = unique(c + 1, c + 1 + n) - c - 1;
		int t = 0;
		for (int j = 1; j <= n; j ++)
			if (!judge(c[j], i - 1))
				c[++ t] = c[j];
		work(c, t);
		pos[i] = a[cnt].cmp_sma;
		for (int j = pos_t[1]; j > 0; j --) {
			//printf("%d %d\n", j, a[j].cmp_sma);
			if (a[j].cmp_sma == pos[i]) {
				pos_t[i] = j;
				break;
			}
		}
		//printf("%d %d %d\n", i, pos[i], pos_t[i]);
	}

	printf("!");
	for (int i = 1; i <= k; i ++)
		printf(" %d", pos[i]);
	fflush(stdout);
	return 0;
}