#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int t, n, m, k;

int a[N], b[N];

struct node {
	ll sum, siz;
}tr[600000];

namespace IO {//only for int!!!
	static const int SIZE = 1 << 20;
	inline int get_char() {
		static char *S, *T = S, buf[SIZE];
		if (S == T) {
			T = fread(buf, 1, SIZE, stdin) + (S = buf);
			if (S == T) return -1;
		}
		return *S ++;
	}
	inline void in(int &x) {//for int
		static int ch;
		while (ch = get_char(), ch < 48);x = ch ^ 48;
		while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
	}
	char buffer[SIZE];
	char *s = buffer;
	void flush() {//最后需要 flush!!
		fwrite(buffer, 1, s - buffer, stdout);
		s = buffer;
		fflush(stdout);
	}
	inline void print(const char ch) {
		if(s - buffer > SIZE - 2) flush();
		*s++ = ch;
	}
	inline void print(char *str) {//for string
		while(*str != 0)
		print(char(*str ++));
	}
	inline void print(int x) {
		static char buf[25];
		static char *p = buf;
		if (x < 0) print('-'), x = -x;
		if (x == 0) print('0');
		while(x) *(++ p) = x % 10, x /= 10;
		while(p != buf) print(char(*(p --) ^ 48));
	}
};

using IO::in;

#define lc (o<<1)
#define rc (lc|1)
#define mid (l+r>>1)

void build(int o, int l, int r) {
	tr[o].sum = tr[o].siz = 0;		
	if (l == r) return;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}

int ask(int o, int l, int r, ll sum) {
	if (tr[o].sum <= sum) return tr[o].siz;
	if (l == r) return min(sum / b[r], tr[o].siz);
	if (sum >= tr[lc].sum) return tr[lc].siz + ask(rc, mid + 1, r, sum - tr[lc].sum);
	else return ask(lc, l, mid, sum);
}

void add(int o, int l, int r, int p) {
	tr[o].sum += b[p], tr[o].siz ++;
	if (l == r) return;
	if (p <= mid) add(lc, l, mid, p);
	else add(rc, mid + 1, r, p);
}

int main() {
	for (in(t); t --; ) {
		in(n), in(m);
		for (int i = 1; i <= n; i ++)
			in(a[i]), b[i] = a[i];

		sort (b + 1, b + n + 1);
		k = unique(b + 1, b + n + 1) - b - 1;
		for (int i = 1; i <= n; i ++)
			a[i] = lower_bound(b + 1, b + k + 1, a[i]) - b;

		build(1, 1, k);
		for (int i = 1; i <= n; i ++) {
			printf("%d ", i - 1 - ask(1, 1, k, m - b[a[i]]));
			add(1, 1, k, a[i]);
		}
		puts("");
	}
	return 0;
} 