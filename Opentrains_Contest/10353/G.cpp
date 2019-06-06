#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

namespace my_hash {
	const int N = (1 << 23) - 1;

	struct E {
		ll v;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;

	int vis[N + 1], T, cnt;

	void ins(ll v) {
		ll u = v & N;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return;
		p = cur ++; p -> v = v; p -> nxt = g[u]; g[u] = p, cnt ++; 
	}
}

int main() {
	int t = 1e4;
	ll x;
	ios::sync_with_stdio(false);
	for (int i = 0; i < t; i ++) {
		printf("+\n");
		fflush(stdout);
		scanf("%llx", &x);
		//printf("%lld\n", x);
		my_hash::ins(x);
	}
	//printf("%d\n", my_hash::cnt);
	int a[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
	int b[] = {10, 100, 1000, 8000, 9700, 9970};
	for (int i = 0; i < 6; i ++) {
		if (my_hash::cnt <= b[i]) {
			printf("= %d\n", a[i]);
			//printf("%d\n", clock());
			return 0;
		}
	}
	printf("= %d\n", a[6]);
	return 0;
}