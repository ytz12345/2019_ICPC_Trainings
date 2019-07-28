#include <bits/stdc++.h>

using namespace std;

const int M = 5e5 + 5;

typedef long long ll;

struct node {
	int name;
	int val;
	int pri;

	bool operator < (const node &a) const {
		return pri > a.pri;
	}

	bool operator == (const node &a) const {
		return pri == a.pri;
	}
};

namespace my_hash {
	const int N = (1 << 20) - 1;

	struct E {
		ll v;
		int p;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;

	int vis[N + 1], T, cnt;

	int ins(ll v) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return p -> p;
		p = cur ++; p -> v = v; p -> p = ++ cnt; p -> nxt = g[u]; g[u] = p;
		return p -> p;
	}

	int ask(ll v) {
		int u = v & N;
		if (vis[u] < T) return 0;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return p -> p;
		return 0;
	}

	void init() {
		T ++;
		cnt = 0;
		cur = pool;
	}
}

ll getname(char *s) {
	ll res = 0;
	
	for (int i = 0, len = strlen(s); i < len; i ++) 
		res = (res * 11 + s[i] - '0' + 1);

	return res;
}

int t, m, n;

int cnt;

int pri[M]; // =0/>0 in/not in

set <node> s;

int main() {
	ios::sync_with_stdio(false);

	node tmp;
	char str[20]; 
	int name, opt, v;

	for (cin >> t; t --; ) {
		my_hash::init();
		cin >> m >> n;

		while (m --) {
			cin >> opt >> str >> v;
			name = my_hash::ins(getname(str));
			
			if (opt == 0) {
				if (pri[name] == 0) {
					s.insert((node){name, v, pri[name] = ++ cnt});
					printf("%d\n", v);

					if (s.size() > n) {
						auto ptr = s.end();
						ptr --;
						pri[(*ptr).name] = 0;
						s.erase(ptr);
					}
				}

				else {
					tmp = (node){name, 0, pri[name]};
					auto ptr = s.find(tmp);
					printf("%d\n", tmp.val = (*ptr).val);

					s.erase(ptr);
					tmp.pri = pri[name] = ++ cnt;
					s.insert(tmp);
				}
			}

			else {
				if (pri[name] == 0) {
					puts("Invalid");
					continue;
				}

				tmp = (node){name, 0, pri[name]};
				auto ptr = s.find(tmp);

				if (v == 0) {
					printf("%d\n", (*ptr).val);
				}
				else if (v == -1) {
					ptr ++;
					if (ptr == s.end()) puts("Invalid");
					else printf("%d\n", (*ptr).val);
				}
				else {
					if (ptr == s.begin()) puts("Invalid");
					else {
						ptr --;
						printf("%d\n", (*ptr).val);
					}
				}
			}
		}

		while (!s.empty()) {
			pri[(*s.begin()).name] = 0;
			s.erase(s.begin());
		}

		cnt = 0;
	}

	return 0;
}