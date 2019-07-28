#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;

vector <int> e[N];

int d[N], a[N], b[N];

queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;

	if (m <= 1) {
		puts("0");
		return 0;
	}

	for (int u, v, i = 1; i < n; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i = 1; i <= m; i ++)
		cin >> a[i], b[a[i]] = 1;

	for (int i = 1; i <= n; i ++)
		d[i] = n + 2019;
	
	q.push(a[1]), d[a[1]] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	int maxDis = -1, pos = -1;
	for (int i = 1; i <= n; i ++) {
		if (b[i] && d[i] > maxDis) {
			maxDis = d[i], pos = i;
		}
	}

	for (int i = 1; i <= n; i ++)
		d[i] = n + 2019;
	
	q.push(pos), d[pos] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	maxDis = -1;
	for (int i = 1; i <= n; i ++) {
		if (b[i] && d[i] > maxDis) {
			maxDis = d[i];
		}
	}

	cout << (maxDis + 1) / 2 << endl;
	return 0;

}