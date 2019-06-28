#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110;

int n1, l1, b1, a[N];

int n2, l2, b2, b[N];

int n, pre[N * 2];

struct node{
	int p, s;
}c[N * 2];

int main() {
	ios::sync_with_stdio(false);
	cin >> n1 >> l1 >> b1;
	for (int i = 1; i <= n1; i ++) cin >> a[i], a[i] += a[i - 1];
	cin >> n2 >> l2 >> b2;
	for (int i = 1; i <= n2; i ++) cin >> b[i], b[i] += b[i - 1];
	if (a[n1] != b[n2]) return puts("No"), 0;
	for (int i = 0; i <= n1; i ++) 
		c[n ++] = (node){l1 + b1 * i, a[i]};
	for (int i = 0; i <= n2; i ++)
		c[n ++] = (node){l2 + b2 * i, b[i]};
	sort (c, c + n, [&](node x, node y){
		return x.p < y.p;
	});
	for (int i = 1; i < n; i ++) {
		pre[i] = c[i].s - c[i - 1].s;
		if (pre[i] < 0) return puts("No"), 0;
		if (c[i].p == c[i - 1].p && pre[i] != 0) return puts("No"), 0;
	}
	return puts("Yes"), 0;
}