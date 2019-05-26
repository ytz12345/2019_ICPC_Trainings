#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

struct node {
	int l, r;

	bool operator < (const node &a) const {
		return l < a.l;
	}

	int calc() {
		return (r - l) / 2 + 1;
	}
}a[N];

map <int, int> p;

vector <node> e[N * 3];

priority_queue <int, vector<int>, greater<int> > q;

int n, k, t, tp, cnt, now;

long long ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int j, i = 1; i <= n; i ++) {
		cin >> a[i].l >> a[i].r;
		if (p.find(a[i].l) == p.end()) p[a[i].l] = ++ cnt, q.push(a[i].l);
		j = p[a[i].l];	
		e[j].push_back((node){a[i].r, a[i].r});
	}
	while (!q.empty()) {
		now = q.top(), k = p[now], q.pop();
		if (e[k].size() == 0) continue;
		sort (e[k].begin(), e[k].end()); t = 0;
		for (int i = 1; i < e[k].size(); i ++) {
			if (e[k][i].l <= e[k][t].r + 2)
				e[k][t].r = max(e[k][t].r, e[k][i].r);
			else 
				e[k][++ t] = e[k][i];
		}
		now ++;
		if (p.find(now) == p.end()) p[now] = ++ cnt, q.push(now);
		tp = p[now];
		for (int j, i = 0; i <= t; i ++) {
			j = e[k][i].calc(), ans += j;
			if (j != 1) e[tp].push_back((node){e[k][i].l + 1, e[k][i].r - 1});
		}
		/*cout << now - 1 << ' ' << k << ' ' << ans << ' ' endl;
		for (int j, i = 0; i <= t; i ++) {
			cout << e[k][i].l << ' '<< e[k][i].r << endl;
		}*/
	}
	cout << ans << endl;
	return 0;
}