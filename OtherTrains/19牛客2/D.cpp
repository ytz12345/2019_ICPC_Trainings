/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int n, k;

ll w[N];

bitset <100> a[N], temp;

char s[N];

struct node {
	bitset
	ll w;

	bool operator < (const node &x) const {
		if (w != a.w) return w < x.w;
	}

	void print() {
		for (int i = 0; i <= a[0]; i  ++)
			cout << a[i] << ' ';
		cout << endl << w << endl;
	}
};

set <node> Q;

ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i ++)
		cin >> w[i];
	for (int i = 0; i < n; i ++) {
		cin >> s;
		for (int j = 0; j < n; j ++) {
			a[i][j] = s[j] == '1';
		}
	}
	node tmp, tmp0;
	for (int i = 0; i < n; i ++) {
		tmp.a[0] = 1;
		tmp.a[1] = i;
		tmp.w = w[i];
		Q.push(tmp);
	}
	//Q.push(q[0].top()), q[0].pop();
	//bitset <100> temp;
	//cout << typeid(a[0]).name() << endl;return 0;
	if (k == 1) {
		cout << "0\n";
		return 0;
	}
	else {
		k --;
	}
	while (k) {
		if (Q.empty()) break;
		k --, ans = Q.top().w;
		tmp = Q.top(), Q.pop();
		//tmp.print();
		if (tmp.a[0] == 19) continue;
		temp.reset();
		for (int i = 1; i <= tmp.a[0]; i ++)
			temp[tmp.a[i]] = 1;while (k) {
		if (Q.empty()) break;
		k --, ans = Q.top().w;
		tmp = Q.top(), Q.pop();
		//tmp.print();
		if (tmp.a[0] == 19) continue;
		temp.reset();
		for (int i = 1; i <= tmp.a[0]; i ++)
			temp[tmp.a[i]] = 1;
		for (int i = tmp.a[tmp.a[0]] + 1; i < n; i ++) {
			if ((a[i] & temp) != temp) continue;
			tmp0 = tmp, tmp0.a[++ tmp0.a[0]] = i;
			tmp0.w += w[i];
			Q.push(tmp0);
		}
	}
		for (int i = tmp.a[tmp.a[0]] + 1; i < n; i ++) {
			if ((a[i] & temp) != temp) continue;
			tmp0 = tmp, tmp0.a[++ tmp0.a[0]] = i;
			tmp0.w += w[i];
			Q.push(tmp0);
		}
	}

	if (k) cout << "-1\n";
	else cout << ans << endl;
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

int main() {
	//long long long x;
	short short short x;
}