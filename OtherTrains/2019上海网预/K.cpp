#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pr;

const ll inf = 1e18;

struct pos {
	ll x[4];

	void print() {
		for (int i = 0; i < 4; i ++)
			printf("%lld%c", x[i], i == 3 ? '\n' : ' ');
	}

	bool operator < (const pos &a) const {
		for (int i = 0; i < 4; i ++)
			if (x[i] != a.x[i])
				return x[i] < a.x[i];
		return 0;
	}

	bool operator == (const pos &a) const {
		for (int i = 0; i < 4; i ++)
			if (x[i] != a.x[i])
				return 0;
		return 1;
	}
};

vector <pos> ans;

ll t, a, b, c;

vector <pr> as, bs;

ll sqr(ll x) {return x * x;}

void check(pr a, pr b, ll d = c) {
	if (sqr(a.first - b.first) + sqr(a.second - b.second) != sqr(d)) return;
	ans.push_back((pos){a.first, a.second, b.first, b.second});
	ans.push_back((pos){a.second, -a.first, b.second, -b.first});
	ans.push_back((pos){-a.first, -a.second, -b.first, -b.second});
	ans.push_back((pos){-a.second, a.first, -b.second, b.first});
}

bool check(ll x, ll y, ll z) {
	return sqr(x) + sqr(y) == sqr(z);
}

void calc(ll a, ll k, vector<pr> &v) {
	for (ll i = 0, j = int(sqrt(a)) + 5; i * i <= a; i ++) {
		while (i * i + j * j > a) j --;
		if (i * i + j * j == a && check(i * j * 2, abs(j * j - i * i), a)) {
			v.push_back(pr(i * j * 2 * k, abs(j * j - i * i) * k));
			v.push_back(pr(abs(j * j - i * i) * k, i * j * 2 * k));
		}
	}
}
void calc(ll a, vector<pr> &v) {//计算所有有序对(x,y)使得x^2+y^2=a^2
	v.clear();
	for (ll k = 1; k * k <= a; k ++)
		if (a % k == 0) {
			calc(a / k, k, v);
			calc(k, a / k, v);
		}
	v.push_back(pr(a, 0)), v.push_back(pr(0, a));
	sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
}

int main() {
	for (cin >> t; t --; ) {
		cin >> a >> b >> c, ans.clear();
		calc(a, as), calc(b, bs);
		for (auto &i : as) for (auto &j : bs) {
			check(i, pr(j.first, j.second));
			check(i, pr(j.second, j.first));
			check(i, pr(-j.first, j.second));
			check(i, pr(-j.second, j.first));
			check(i, pr(j.first, -j.second));
			check(i, pr(j.second, -j.first));
			check(i, pr(-j.first, -j.second));
			check(i, pr(-j.second, -j.first));
		}
		sort (ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
		printf("%d\n", (int)(ans.size()));
		for (auto &i : ans)
			i.print();
	}
}