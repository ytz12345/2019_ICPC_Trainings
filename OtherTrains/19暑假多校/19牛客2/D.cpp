#include <bits/stdc++.h>

using namespace std;

typedef bitset<103> bs;

typedef long long ll;

const int N = 103;

struct node {
	bs x;
	ll s;

	bool operator < (const node &a) const {
		return s > a.s;
	}
};

priority_queue <node> q;

bs a[N];

int n, k;

int w[N];

char s[N];

ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i ++) 
		cin >> w[i];
	for (int i = 0; i < n; i ++) {
		cin >> s;
		for (int j = 0; j < n; j ++)
			a[i][j] = s[j] == '1';
	}
	bs t; t.reset(); q.push((node){t, 0});
	node tmp, temp; int maxId;
	while (k --) {
		if (q.empty()) {
			puts("-1");
			return 0;
		}
		tmp = q.top(); q.pop(); ans = tmp.s; maxId = -1;
		for (int i = 0; i < n; i ++)
			if (tmp.x[i] == 1)
				maxId = i;
		for (int i = maxId + 1; i < n; i ++) {
			if ((tmp.x & a[i]) == tmp.x) {
				temp = tmp; temp.x[i] = 1; temp.s += w[i];
				q.push(temp);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}