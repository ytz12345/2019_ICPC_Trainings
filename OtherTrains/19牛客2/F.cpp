#include <bits/stdc++.h>

using namespace std;

const int N = 30;

typedef long long ll;

int a[20], b[20];

int n, c[N][N];

ll ans, tmp;

void dfs(int id) {
	if (id >= n * 2) {
		ans = max(ans, tmp);
		return;
	}
	ll temp;
	if (a[0] < n) {
		a[++ a[0]] = id;
		temp = 0;
		for (int i = 1; i <= b[0]; i ++) 
			temp+=c[id][b[i]];
		tmp += temp;
		dfs(id + 1);
		tmp -= temp;
		a[0] --;
	} 
	if (b[0] < n) {
		b[++ b[0]] = id;
		temp = 0;
		for (int i = 1; i <= a[0]; i ++)
			temp+=c[id][a[i]];
		tmp += temp;
		dfs(id + 1);
		tmp -= temp;
		b[0] --;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n * 2; i ++)
		for (int j = 0; j < n * 2; j ++)
			cin >> c[i][j];
	a[++ a[0]] = 0;
	dfs(1);
	cout << ans << endl;
	//cout << clock() << endl;
	return 0;
}