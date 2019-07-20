#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;

typedef long long ll;

struct line {
	ll l, r, y, v;
}b[N];

struct node {
	ll lazy, maxs;
}tr[N << 2];

ll tot, c[N];

ll ans;

#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)

void pushdown(int o) {
	if (!tr[o].lazy) return;
	tr[lc].lazy += tr[o].lazy;
	tr[lc].maxs += tr[o].lazy;
	tr[rc].lazy += tr[o].lazy;
	tr[rc].maxs += tr[o].lazy;
	tr[o].lazy = 0;
}

void pushup(int o) {
	tr[o].maxs = max(tr[lc].maxs, tr[rc].maxs); 
}

void modify(int o, int l, int r, int s, int t, ll v) {
	if (s <= l && r <= t) {
		tr[o].maxs += v;
		tr[o].lazy += v;
		return;
	}
	pushdown(o);
	if (s <= mid) modify(lc, l, mid, s, t, v);
	if (t >  mid) modify(rc, mid + 1, r, s, t, v);
	pushup(o);
}

ll ask(int p, int o = 1, int l = 1, int r = tot) {
	if (l == r) return tr[o].maxs;
	pushdown(o);
	return p <=mid ? ask(p, lc, l, mid) : ask(p, rc, mid + 1, r); 
}

ll n, l, r;

void print() {
	for (int i = 1; i <= tot; i ++)
		printf("%d ", ask(i));
	puts("");
}

int main() {
	//ios::sync_with_stdio(false);
	cin >> n >> l >> r;
	for (int x, y, v, i = 0; i < n; i ++) {
		cin >> x >> y >> v;
		b[i * 4 + 0] = (line){x - r, x + r, y - r, v};
		b[i * 4 + 1] = (line){x - r, x + r, y + r + 1, -v};
		b[i * 4 + 2] = (line){x - l + 1, x + l - 1, y - l + 1, -v};
		b[i * 4 + 3] = (line){x - l + 1, x + l - 1, y + l, v};
		c[i * 4 + 0] = x - r; 
		c[i * 4 + 1] = x - l + 1; 
		c[i * 4 + 2] = x + l - 1; 
		c[i * 4 + 3] = x + r; 
	}
	sort (c, c + n * 4);
	tot = unique(c, c + n * 4) - c;
	sort (b, b + n * 4, [&](line x, line y){
		return x.y < y.y;
	});
	for (int x, y, i = 0; i < n * 4; ) {
		do {
			x = lower_bound(c, c + tot, b[i].l) - c + 1;
			y = lower_bound(c, c + tot, b[i].r) - c + 1;
			modify(1, 1, tot, x, y, b[i].v);
			printf("%d %d %d %d\n", i, x, y, b[i].v);
			print();
			i ++;
		}while (i < n * 4 && b[i].y == b[i - 1].y);
		//cout << b[i -1].y << ' ' << tr[1].maxs << endl;
		
		ans = max(ans, tr[1].maxs);
	}
	cout << ans << endl;
	return 0;
}
/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int Z = 1 << 19;

struct intv{
	int y,l,r,s;
	bool operator <(const intv &t) const{return y < t.y;}
}I[Z];
int V[Z];

int N,L,R;

int A[Z*2],X[Z*2];

void in(int n, int l, int r, int s, int x = 0, int y = Z-1)
{
	l = max(x,l);
	r = min(y,r);
	if (l > r) return;
	if (l == x && r == y) A[n] += s;
	else{
		A[n*2] += A[n];
		A[n*2+1] += A[n];
		in(n*2,l,r,s,x,(x+y)/2);
		in(n*2+1,l,r,s,(x+y+1)/2,y);
		A[n] = 0;
		X[n] = max(A[n*2]+X[n*2],A[n*2+1]+X[n*2+1]);
	}
}

int main()
{
	scanf ("%d %d %d",&N,&L,&R);
	for (int i=0;i<N;i++){
		int x,y,s; scanf ("%d %d %d",&x,&y,&s);

		V[i] = x - R;
		V[i+N] = x + R + 1;
		V[i+N*2] = x - L + 1;
		V[i+N*3] = x + L;
		I[i] = intv{y-R,x-R,x+R,s};
		I[i+N] = intv{y-L+1,x-L+1,x+L-1,-s};
		I[i+N*2] = intv{y+L,x-L+1,x+L-1,s};
		I[i+N*3] = intv{y+R+1,x-R,x+R,-s};
	}

	int v = 4 * N;
	sort(V,V+v);
	v = unique(V,V+v) - V;
	sort(I, I+4*N);
	
	int ans = 0;
	for (int i=0,j=0;i<4*N;i=j){
		while (j < 4*N && I[i].y == I[j].y){
			int p = lower_bound(V,V+v,I[j].l) - V;
			int q = lower_bound(V,V+v,I[j].r) - V;
			in(1,p,q,I[j].s);
			j++;
		}
		ans = max(ans,A[1]+X[1]);
	}
	printf ("%d\n",ans);

	return 0;
}*/
/*
10 2 7

4 -8 5
-8 -7 4
-7 -7 -6
-2 -5 0
-4 -4 2
-4 0 8
-4 1 -6
-7 4 -6
6 5 -7
-3 9 2

*/