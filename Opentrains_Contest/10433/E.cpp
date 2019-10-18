#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef __int128 ll;

int n, x;

void pt(ll x) {
	if (x == 0) {
		putchar('0');
		return;
	}
	int tmp[100], cnt = 0, flag = 0;
	if (x < 0) flag = 1, x = -x;
	while (x > 0) tmp[cnt ++] = '0' + x % 10, x /= 10;
	if (flag) putchar('-');
	while (cnt > 0) putchar(tmp[-- cnt]);
}

struct node {
	ll x, y;

	node():x(0), y(1) {}
	node(ll x):x(x), y(1) {}
	node(ll x, ll y):x(x), y(y) {
		ll z = __gcd(x, y);
		x /= z, y /= z;
	}

	node operator +(const node &a) const {
		node res(x * a.y + y * a.x, y * a.y);
		ll z = __gcd(res.x, res.y);
		res.x /= z, res.y /= z;
		return res;
	}

	node operator -(const node &a) const {
		return (*this) + node(-a.x, a.y);
	}

	node operator *(const node &a) const {
		node res(x * a.x, y * a.y);
		ll z = __gcd(res.x, res.y);
		res.x /= z, res.y /= z;
		return res;
	}

	node operator /(const node &a) const {
		return (*this) * node(a.y, a.x); 
	}

	node operator =(const ll &z) {
		x = z, y = 1;
		return (*this);
	}

	node operator * (const ll &z) {
		return node(x * z, y);
	}

	bool operator == (const node &a) const {
		return x == a.x && y == a.y;
	}

	bool operator == (const ll &a) const {
		return (*this) == node(a);
	}

	bool operator != (const ll &a) const {
		return !((*this) == a);
	}

	void print() {
		ll z = __gcd(x, y);
		x /= z, y /= z;
		if (x < 0 && y < 0) x = -x, y = -y;
		pt(x), putchar('/'), pt(y);
		puts("");
	}
};

node a[4][N], A[2], B[2], C[2];

node sqr(node x) {
	return x * x;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 4; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> x, a[i][j] = x;

	for (int i = 1; i <= n; i ++) {
		A[0] = A[0] + (a[0][i] - a[1][i]) * (a[0][i] - a[1][i])* 2;
		B[0] = B[0] + (a[3][i] - a[2][i]) * (a[0][i] - a[1][i])* 2;
		C[0] = C[0] + (a[1][i] - a[3][i]) * (a[0][i] - a[1][i])* 2;

		A[1] = A[1] + (a[0][i] - a[1][i]) * (a[3][i] - a[2][i])* 2;
		B[1] = B[1] + (a[3][i] - a[2][i]) * (a[3][i] - a[2][i])* 2;
		C[1] = C[1] + (a[1][i] - a[3][i]) * (a[3][i] - a[2][i])* 2;
	}

	node x, y, ans;
	if (A[0] == 0) swap(A[0], A[1]), swap(B[0], B[1]), swap(C[0], C[1]);
	if (A[1] != 0) B[1] = B[1] - (A[1] / A[0] * B[0]), C[1] = C[1] - (A[1] / A[0] * C[0]);

	if (B[1] != 0) y = C[1] / B[1], y.x = -y.x;
	else y = 0;
	C[0] = C[0] + B[0] * y;
	if (A[0] != 0) x = C[0] / A[0], x.x = -x.x;
	else x = 0; 

	node one = 1;
	for (int i = 1; i <= n; i ++)  {
		ans = ans + sqr(x * a[0][i] + (one - x) * a[1][i] - a[2][i] * y - a[3][i] * (one - y));
	}
	
	ans.print();
}