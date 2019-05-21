#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

const int M = 2e5 + 5;

const int L = 50;

int n, m;

struct node {
	char s[L];
	int len;
	int id;

	void scan() {
		scanf("%s", s);
		len = strlen(s);
	}

	void s0rt() {
		sort (s, s + len);
	}

	bool operator < (const node &a) const {
		if (len != a.len) return len < a.len;
		for (int i = 0; i < len; i ++)
			if (s[i] != a.s[i])
				return s[i] < a.s[i];
		return 0;
	}

	bool operator == (const node &a) const {
		if (len != a.len) return 0;
		for (int i = 0; i < len; i ++)
			if (s[i] != a.s[i])
				return 0;
		return 1;
	}
}a[N], d[M], b[M];

set <node> s[L];

int to[M], leng[M];

int path[L];

bool cmp(const node &a, const node &b) {
	for (int i = 0, j = min(a.len, b.len); i < j; i ++)
		if (a.s[i] != b.s[i])
			return a.s[i] < b.s[i];
	return a.len < b.len;
} 

int f1nd(const node &a) {
	int l = 0, r = m - 1, mid;
	while (l <= r) {
		mid = l + r >> 1;
		if (a == d[mid]) return mid;
		if (cmp(a, d[mid])) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) 
		a[i].scan();
	scanf("%d", &m);
	for (int i = 0; i < m; i ++) {
		d[i].scan();
		d[i].id = i;
		b[i] = d[i];
		b[i].s0rt();
		s[b[i].len].insert(b[i]);
	}
	sort (b, b + m);
	node tmp;
	for (int i = 0; i < m; i ++) {
		to[b[i].id] = -2;
		if (b[i].len == 1) to[b[i].id] = -1, leng[b[i].id] = 1;
		else {
			int last = -1, lg = -1;
			tmp.len = b[i].len - 1;
			for (int j = 0; j < b[i].len; j ++) {
				int t = 0;
				for (int k = 0; k < b[i].len; k ++) {
					if (k == j) continue;
					tmp.s[t ++] = b[i].s[k];
				}
				auto it = s[tmp.len].find(tmp);
				if (it != s[tmp.len].end()) {
					if (leng[(*it).id] > lg) {
						lg = leng[(*it).id];
						last = (*it).id;
					}
				}
			}
			if (last != -1) {
				to[b[i].id] = last;
				leng[b[i].id] = lg + 1;
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		path[0] = 0;
		path[++ path[0]] = f1nd(a[i]);
		while (path[path[0]] != -1) {
			if (to[path[path[0]]] < -1) break;
			path[path[0] + 1] = to[path[path[0]]];
			path[0] ++;
		}
		printf("%d\n%s", path[0], d[path[1]].s);
		for (int i = 2; i <= path[0]; i ++) 
			printf(" -> %s", path[i] < 0 ? "." : d[path[i]].s);
		puts("");
	}
	return 0;
}