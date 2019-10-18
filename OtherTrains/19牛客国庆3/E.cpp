#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

typedef long long ll;

const int N = 1e5 + 5;

int n, m, q;

struct node {
	set <piir> s;
	ll sum;

	void reset() {
		sum = 0;
		s.clear();
	}

	void insert(int a, int b) {
		auto it = s.lower_bound(piir(a, b));
		if (it != s.begin()) {
			it --;
			if (it -> second + 1 < a) it ++;  
		}
		if (it != s.end()) a = min(a, it -> first);
		auto st = it, ed = it;
		for (; ed != s.end() && ed -> first <= b; ed ++) 
			b = max(b, ed -> second);
		for (it = st; it != ed; it ++)
			sum -= it -> second - it -> first + 1;
		s.erase(st, ed);
		s.insert(piir(a, b));
		sum += b - a + 1;
	}
}t[3];

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> q) {
		t[1].reset(), t[2].reset();
		for (int op, a, b; q --; ) {
			cin >> op >> a >> b;
			t[op].insert(a, b);
			if (t[1].sum && t[2].sum) printf("%lld\n", 1ll * (n - t[1].sum) * (m - t[2].sum) + 1);
			else if (t[1].sum) printf("%lld\n", 1ll * (n - t[1].sum) * m + t[1].sum);
			else printf("%lld\n", 1ll * n * (m - t[2].sum) + t[2].sum);
		}
	}
}