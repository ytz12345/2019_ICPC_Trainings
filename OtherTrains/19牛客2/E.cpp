#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7;

const int N = 5e4 + 5;

const int K = 10;

struct matrix {
	int c[K][K];

	void clear() {
		memset (c, 0, sizeof c);
	}

	matrix() {
		memset (c, 0, sizeof c);
	}

	matrix operator * (const matrix &a) const {
		matrix res;
		for (int k = 0; k < K; k ++)
			for (int i = 0; i < K; i ++)
				for (int j = 0; j < K; j ++)
					(res.c[i][j] += 1ll * c[i][k] * a.c[k][j] % Mod) %= Mod;
		return res;
	}
};

struct node {
	matrix v;
}tr[N << 2];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1)

int n, m, q;

char s[N][15];

void update(matrix &v, char *str) {
	v.clear();
	for (int i = 0; i < m; i ++) {
		for (int j = i; j < m; j ++) { 
			if (str[j] == '1') break;
			v.c[i][j] = 1;
			v.c[j][i] = 1;
		}
	}
}

void pushup(int o) {
	tr[o].v = tr[lc].v * tr[rc].v;
}

void build(int o, int l, int r) {
	if (l == r) {
		update(tr[o].v, s[r]);
		return;
	}
	build(lc, l, mid);
	build(rc, 1 + mid, r);
	pushup(o);
}

void change(int o, int l, int r, int p) {
	if (l == r) {
		update(tr[o].v, s[r]);
		return;
	}
	if (p <= mid) change(lc, l, mid, p);
	else          change(rc, mid + 1, r, p);
	pushup(o);
} 

int main() {
	ios::sync_with_stdio(false);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i]);
	build(1, 1, n);
	for (int op, a, b; q --; ) {
		scanf("%d %d %d", &op, &a, &b); b --;
		if (op == 1) {
			s[a][b] ^= 1;
			change(1, 1, n, a);
		}
		else {
			printf("%d\n", (tr[1].v.c[a - 1][b] % Mod + Mod) % Mod);
		}
	}
	return 0;
}