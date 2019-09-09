#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

typedef pair<int, int> piir;

struct pr1 {//small
	int len, pos, flag;

	bool operator < (const pr1 &a) const {
		if (len != a.len) return len < a.len;
		return pos > a.pos;
	}
};

struct pr2 {//large
	int len, pos, flag;

	bool operator < (const pr2 &a) const {
		if (len != a.len) return len < a.len;
		return pos < a.pos;
	}
};

int n, k, a[N], b[N];

int dp[N][2];

piir pre[N][2];

#define lc (o << 1)
#define rc (lc | 1)
#define mid (l + r >> 1)

namespace IO {
	static const int SIZE = 1 << 20;

	inline int get_char() {
		static char *S, *T = S, buf[SIZE];
		if (S == T) {
			T = fread(buf, 1, SIZE, stdin) + (S = buf);
			if (S == T) return -1;
		}
		return *S ++;
	}

	inline void in(int &x) {
		static int ch;
		while (ch = get_char(), ch < 48) {
			if (ch == -1) {
				x = -1; 
				return;
			}
		}
		x = ch ^ 48;
		while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
	}
}

namespace SMA {

	struct node {
		pr1 v;
	}tr1[N << 2], tr2[N << 2];

	void pushup(node *tr, int o) {
		tr[o].v = max(tr[lc].v, tr[rc].v);
	}

	void build(int o, int l, int r) {
		tr1[o].v = tr2[o].v = (pr1){0, 0, n + 1};
		if (l == r) return;
		build(lc, l, mid);
		build(rc, mid + 1, r);
	}

	void update(node *tr, int o, int l, int r, int p, pr1 v) {
		if (l == r) {
			tr[o].v = max(tr[o].v, v);
			return;
		}
		if (p <= mid) update(tr, lc, l, mid, p, v);
		if (p >  mid) update(tr, rc, mid + 1, r, p, v);
		pushup(tr, o);
	}

	pr1 ask(node *tr, int o, int l, int r, int s, int t) {
		if (s <= l && r <= t) return tr[o].v;
		if (s >  mid) return ask(tr, rc, mid + 1, r, s, t);
		if (t <= mid) return ask(tr, lc, l, mid, s, t);
		return max(ask(tr, rc, mid + 1, r, s, t), ask(tr, lc, l, mid, s, t));
	}

	void dfs(int pos, int flag) {
		//cout << "? " << pos << endl;
		if (pos > n || pos < 1) return;
		printf("%d ", pos);
		dfs(pre[pos][flag].first, pre[pos][flag].second);
	}

	void getSmall() {
		for (int i = 1; i <= n; i ++) 
			for (int j = 0; j < 2; j ++)
				dp[i][j] = 0, pre[i][j] = piir(n + 1, 0);

		pr1 t1, t2;
		int res[N];
		memset (tr1, 0, sizeof tr1);
		memset (tr2, 0, sizeof tr2);
		build(1, 1, n);
		for (int i = n; i >= 1; i --) {
			if (1 <= a[i] - 1) {
				t1 = ask(tr1, 1, 1, k, 1, a[i] - 1);
				dp[i][0] = t1.len + 1;
				pre[i][0] = piir(t1.pos, t1.flag);
			}
			else {
				dp[i][0] = 1;
			}
			if (a[i] + 1 <= k) {
				t2 = ask(tr2, 1, 1, k, a[i] + 1, k);
				dp[i][1] = t2.len + 1;
				pre[i][1] = piir(t2.pos, t2.flag);
			}
			else {
				dp[i][1] = 1;
			}
			update(tr1, 1, 1, k, a[i], (pr1){dp[i][0], i, 0});
			update(tr2, 1, 1, k, a[i], (pr1){dp[i][0], i, 0});
			update(tr2, 1, 1, k, a[i], (pr1){dp[i][1], i, 1});
		}

		int maxLen = 0;
		for (int i = 1; i <= n; i ++) {
			if (dp[i][0] > maxLen) maxLen = dp[i][0];
			if (dp[i][1] > maxLen) maxLen = dp[i][1];
		}

		if (maxLen == 1) {
			puts("1");
		}
		else {
			//cout << maxLen << endl;
			for (int i = 1; i <= n; i ++) {
				//cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << max(dp[i][0], dp[i][1]) << endl;
				if (max(dp[i][0], dp[i][1]) != maxLen) continue;
				if (dp[i][0] == dp[i][1]) {
					if (pre[i][0].first < pre[i][1].first) dfs(i, 0);
					else dfs(i, 1);
				}
				else if (dp[i][0] == maxLen) dfs(i, 0);
				else dfs(i, 1);
				break;
			}
			puts("");
		}
	}
}

namespace LAR {

	struct node {
		pr2 v;
	}tr1[N << 2], tr2[N << 2];

	void pushup(node *tr, int o) {
		tr[o].v = max(tr[lc].v, tr[rc].v);
	}

	void build(int o, int l, int r) {
		tr1[o].v = tr2[o].v = (pr2){0, 0, n + 1};
		if (l == r) return;
		build(lc, l, mid);
		build(rc, mid + 1, r);
	}

	void update(node *tr, int o, int l, int r, int p, pr2 v) {
		if (l == r) {
			tr[o].v = max(tr[o].v, v);
			return;
		}
		if (p <= mid) update(tr, lc, l, mid, p, v);
		if (p >  mid) update(tr, rc, mid + 1, r, p, v);
		pushup(tr, o);
	}

	pr2 ask(node *tr, int o, int l, int r, int s, int t) {
		if (s <= l && r <= t) return tr[o].v;
		if (s >  mid) return ask(tr, rc, mid + 1, r, s, t);
		if (t <= mid) return ask(tr, lc, l, mid, s, t);
		return max(ask(tr, rc, mid + 1, r, s, t), ask(tr, lc, l, mid, s, t));
	}

	void dfs(int pos, int flag) {
		//cout << "? " << pos << endl;
		if (pos > n || pos < 1) return;
		printf("%d ", pos);
		dfs(pre[pos][flag].first, pre[pos][flag].second);
	}

	void getLarge() {
		for (int i = 1; i <= n; i ++) 
			for (int j = 0; j < 2; j ++)
				dp[i][j] = 0, pre[i][j] = piir(n + 1, 0);

		pr2 t1, t2;
		int res[N];
		memset (tr1, 0, sizeof tr1);
		memset (tr2, 0, sizeof tr2);
		build(1, 1, n);
		for (int i = n; i >= 1; i --) {
			if (1 <= a[i] - 1) {
				t1 = ask(tr1, 1, 1, k, 1, a[i] - 1);
				dp[i][0] = t1.len + 1;
				pre[i][0] = piir(t1.pos, t1.flag);
			}
			else {
				dp[i][0] = 1;
			}
			if (a[i] + 1 <= k) {
				t2 = ask(tr2, 1, 1, k, a[i] + 1, k);
				dp[i][1] = t2.len + 1;
				pre[i][1] = piir(t2.pos, t2.flag);
			}
			else {
				dp[i][1] = 1;
			}
			update(tr1, 1, 1, k, a[i], (pr2){dp[i][0], i, 0});
			update(tr2, 1, 1, k, a[i], (pr2){dp[i][0], i, 0});
			update(tr2, 1, 1, k, a[i], (pr2){dp[i][1], i, 1});
		}

		int maxLen = 0;
		for (int i = 1; i <= n; i ++) {
			if (dp[i][0] > maxLen) maxLen = dp[i][0];
			if (dp[i][1] > maxLen) maxLen = dp[i][1];
		}

		if (maxLen == 0) {
			puts("");
		}
		else if (maxLen == 1) {
			puts("1");
		}
		else {
			for (int i = n; i >= 1; i --) {
				//cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << ' ' << max(dp[i][0], dp[i][1]) << endl;
				if (max(dp[i][0], dp[i][1]) != maxLen) continue;
				if (dp[i][0] == dp[i][1]) {
					if (pre[i][0].first > pre[i][1].first) dfs(i, 0);
					else dfs(i, 1);
				}
				else if (dp[i][0] == maxLen) dfs(i, 0);
				else dfs(i, 1);
				break;
			}
			puts("");
		}
	}
}

int main() {
	while (1) {
		IO::in(n); if (n < 0) break;
		for (int i = 1; i <= n; i ++) {
			IO::in(a[i]);
			b[i] = a[i];
		}
		sort (b + 1, b + n + 1);
		k = unique(b + 1, b + n + 1) - b - 1;
		for (int i = 1; i <= n; i ++)
			a[i] = lower_bound(b + 1, b + k + 1, a[i]) - b;
		
		/*for (int i = 1; i <= n; i ++)
			cout << ' ' << a[i];
		cout << endl;*/
		
		SMA::getSmall();
		LAR::getLarge();
	}
	//printf("%d\n", clock());
	return 0;
}