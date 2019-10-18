#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dx[] = {0, 1, -1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};

ll calc(ll x, ll y, ll &i, ll &j) {
	if ((x - y * 2) % 5 == 0) {
		j = (x - y * 2) / 5;
		if ((x - j) % 2 == 0) {
			i = (x - j) / 2;
			return 1;
		}
	}
	return 0;
}

ll x[4], y[4];

int main() {
	ios::sync_with_stdio(false);
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	for (int i = 0; i < 5; i ++)
		if (calc(x[0] + dx[i], y[0] + dy[i], x[2], y[2]))
			break;
	for (int i = 0; i < 5; i ++)
		if (calc(x[1] + dx[i], y[1] + dy[i], x[3], y[3]))
			break;
	cout << abs(x[2] - x[3]) + abs(y[2] - y[3]) << endl;
}