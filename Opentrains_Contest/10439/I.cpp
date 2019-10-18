#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, dis, pre;

	bool operator < (const node &a) const {
		return dis > a.dis;
	}
};

priority_queue <node> q;

map <int, int> p, pre; 

void dfs(int u) {
	if (u == -1) return;
	dfs(pre[u]);
	printf("%d ", u);
}

int main() {
	int n, m; cin >> n;
	q.push((node){n, p[n] = 0, -1});
	while (1) {
		node now = q.top(); q.pop();
		if (now.dis > 25) continue;
		pre[now.x] = now.pre;
		if (now.x == 1) {
			printf("%d\n", now.dis);
			dfs(1);
			return 0;
		}
		m = now.x / 2;
		if (now.x % 2 == 0 && (p.find(m) == p.end() || p[m] > now.dis)) 
			q.push((node){m, p[m] = now.dis, now.x});
		m = now.x / 3;
		if (now.x % 3 == 0 && (p.find(m) == p.end() || p[m] > now.dis)) 
			q.push((node){m, p[m] = now.dis, now.x});
		m = now.x + 1;
		if (p.find(m) == p.end() || p[m] > now.dis + 1) 
			q.push((node){m, p[m] = now.dis + 1, now.x});
	}
}