#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

const int N = 3e5 + 5;

int t, n, k;

int a[N], c[N], pre[N];

int q[N], l, r;

int st[N];

int main() {
	for (scanf("%d", &t); t --; ) {
		scanf("%d %d", &n, &k); ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			c[i] = 0;
		}
		for (int i = 1; i <= n; i ++){
			pre[i] = c[a[i]];
			c[a[i]] = i;
		}	
		int last = 0; l = 1; r = 0;
		for (int i = 1; i <= n; i ++) {
			last = max(last, pre[i]);
			while (l <= r && q[l] <= last) l ++;
			st[q[l]] = last;
			while (l <= r && a[q[r]] <= a[i]) r --;
			//st[q[++ r] = i] = 
		}
	}
	return 0;
}