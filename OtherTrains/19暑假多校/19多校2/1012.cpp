#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef pair<int, int> piir;

int n, c, k, ans;

int a[N], lastk[N], pre[N], head[N];

struct l1st {
	int last, next;
}lst[N];

struct node {
	int mins, lazy, id;
}tr[N << 2];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1)

void pushdown(int o) {
	if (!tr[o].lazy) return;
	tr[lc].mins += tr[o].lazy;
	tr[lc].lazy += tr[o].lazy;
	tr[rc].mins += tr[o].lazy;
	tr[rc].lazy += tr[o].lazy;
	tr[o].lazy = 0;
}

void pushup(int o) {
	if (tr[lc].mins <= tr[rc].mins) tr[o].mins = tr[lc].mins, tr[o].id = tr[lc].id;
	else tr[o].mins = tr[rc].mins, tr[o].id = tr[rc].id;
}

void build(int o, int l, int r) {
	if (l == r) {tr[o].mins = tr[o].lazy = 0, tr[o].id = r; return;}
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(o);
}

void add(int o, int l, int r, int s, int t, int v) {
	//if (l == 1 && r == n) cout << "+ " << s << ' ' << t << ' ' << v << endl;
	if (s <= l && r <= t) {
		tr[o].lazy += v;
		tr[o].mins += v;
		return;
	}
	pushdown(o);
	if (s <= mid) add(lc, l, mid, s, t, v);
	if (mid <  t) add(rc, mid + 1, r, s, t, v);
	pushup(o);
}

piir askmin(int o, int l, int r, int s, int t) {
	if (s <= l && r <= t) return piir(tr[o].mins, tr[o].id);
	pushdown(o);
	if (s > mid) return askmin(rc, mid + 1, r, s, t);
	if (t <= mid) return askmin(lc, l, mid, s, t);
	return min(askmin(rc, mid + 1, r, s, t), askmin(lc, l, mid, s, t));
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> c >> k) {
		for (int i = 1; i <= c; i ++)
			pre[i] = head[i] = 0;
		for (int i = 1; i <= n; i ++)
			lst[i].last = lastk[i] = 0, lst[i].next = n + 1;

		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			if (!pre[a[i]]) head[a[i]] = i;
			lst[i].last = pre[a[i]];
			pre[a[i]] = i;
		}
		for (int i = 1; i <= c; i ++)
			pre[i] = n + 1;

		for (int i = n; i >= 1; i --) {
			lst[i].next = pre[a[i]];
			pre[a[i]] = i;
		}

		for (int i = 1; i <= c; i ++) {
			if (head[i] == 0) continue;
			for (int j = head[i], cnt = 1; j <= n; j = lst[j].next) {
				if (cnt == k) {
					lastk[j] = head[i];
					break;
				}
				cnt ++;
			}
		}

		ans = 0;
		piir tmp;
		//memset (tr, 0, sizeof tr);
		for (int i = 0; i <= n * 4; i ++)
			tr[i].mins = tr[i].id = tr[i].lazy = 0;
		build(1, 1, n);
		for (int p, i = 1; i <= n; i ++) {

			if (lst[i].last != 0) add(1, 1, n, 1, lst[i].last, -1);

			add(1, 1, n, 1, i, 1);

			if (lastk[lst[i].last] != 0) lastk[i] = lst[lastk[lst[i].last]].next;
			if (lastk[i] != 0) {
				add(1, 1, n, 1, lastk[i], -1);
				if (lst[lastk[i]].last != 0) add(1, 1, n, 1, lst[lastk[i]].last, 1);
			}

			tmp = askmin(1, 1, n, 1, i);
			//cout << ' ' << i << ' ' << tmp.first << ' '  << tmp.second << endl;
			if (tmp.first == 0) ans = max(ans, i - tmp.second + 1);
		}	

		cout << ans << '\n';
	}
	return 0;
}