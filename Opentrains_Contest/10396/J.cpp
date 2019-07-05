#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

typedef long long ll;

const int N = 1e7 + 4;

uint s;

uint getNext() {
	s = s ^ (s << 13);
	s = s ^ (s >> 17);
	s = s ^ (s << 5);
	return s;
}

int n, m, k;

int f[N];

bitset<N>used;

int fa(int x) {return x == f[x] ? x : (f[x] = fa(f[x]));}

struct edge{
	int u, v, id;
	ll w;

	bool operator < (const edge &a) const {
		return w < a.w;
	}
}e[N * 5 / 6];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	if (m <= 5e6) {
		for (int i = 0; i < m; i ++) {
			e[i].u = getNext() % n;
			e[i].v = getNext() % n;
			e[i].w = getNext() / 4;
			e[i].w = e[i].w * getNext();
			e[i].id = i;
		}
		k = m;
	}
	else {
		int blk = 1e5, last = 0;
		for (int i = 0; i < m; i ++) {
			e[k].u = getNext() % n;
			e[k].v = getNext() % n;
			e[k].w = getNext() / 4;
			e[k].w = e[k].w * getNext();
			e[k].id = i;
			k ++;
			if (i % blk == 0) {
				sort (e + last, e + k);
				k = last + blk * 5 / 7;
				last = k;
			}
		}
	}
	sort (e, e + k);
	for (int i = 0; i < n; i ++) f[i] = i;
	for (int i = 0, j = 0; i < k && j * 2 <= n; i ++) {
		if (fa(e[i].u) == fa(e[i].v)) continue;
		used[e[i].id] = 1, j ++;
		f[fa(e[i].u)] = fa(e[i].v);
	}
	uint ot = 0, one = 1;
	for (int i = 0; i < m; i ++) {
		if (i % 32 == 0 && i != 0) {
			printf("%u ", ot);
			ot = 0;
		}
		if (!used[i]) continue;
		ot = ot | (one << (i % 32));
	}
	printf("%u", ot);
	//printf("\n%d", clock());
	return 0;
}