#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

map <int, bool> used;

int n, a[N], d[N];

int u[N], v[N];

int X, id[N];

int b[N], c[N];

void no() {
	puts("-1");
	exit(0);
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i];
	for (int i = 1; i < n; i ++)
		cin >> u[i] >> v[i], d[u[i]] ++, d[v[i]] ++;

	X = n;
	for (int i = 1; i <= n; i ++)
		if (a[i] == 0) {
			used[id[i] = i] = 1;
			if (d[i] % 2 == 1) X ^= i;
		} 
		else {
			if (d[i] % 2 == 1) b[++ b[0]] = i;
			else c[++ c[0]] = i;
		}

	if (b[0] == 0) {
		if (X == 0);
		else no();
	}
	else if (b[0] == 1) {
		if (X == 0) no();
		else if (used[X]) no();
		else used[id[b[1]] = X] = 1;
	}
	else if (b[0] == 2) {
		if (X == 0) no();
		else {
			used[id[b[1]] = (1 << 20) + (1 << 21) + X] = 1;
			used[id[b[2]] = (1 << 20) + (1 << 21)] = 1;
		}
	} 
	else {
		for (int i = 4; i <= b[0]; i ++)
			used[id[b[i]] = b[i]] = 1, X ^= b[i];
		used[id[b[1]] = (1 << 21) + (1 << 20) + X] = 1;
		used[id[b[2]] = (1 << 21)] = 1;
		used[id[b[3]] = (1 << 20)] = 1;
	}

	for (int x, i = 1; i <= c[0]; i ++) {
		do {x = rand() % inf + 1;} while (used.find(x) != used.end() && used[x] == 1);
		used[id[c[i]] = x] = 1;
	}

	printf("%d\n", n);
	for (int i = 1; i < n; i ++)
		printf("%d %d\n", id[u[i]], id[v[i]]);
	return 0;
}