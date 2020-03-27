#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
typedef pair<int, int> P;
const int N = 5e5 + 7;
const int maxNode = N;
const ll inf = (ll)1e15;
char s[N];

int w[N];

struct Aho_Corasick {
	int ch[maxNode][26];
	int f[maxNode], last[maxNode];
	int val[maxNode];
	int tot;
	queue<int> Q;
	void init() { 
		while (!Q.empty()) Q.pop();
		tot = 1; 
		memset(ch[0], 0, sizeof(ch[0])); 	
	}
	void insert(char *s, int n, int v) {
		int u = 0;
		for (int i = 0; i < n; ++i) {
			int c = s[i] - 'a';
			if (!ch[u][c]) {
				memset(ch[tot], 0, sizeof(ch[tot]));
				val[tot] = 0; ch[u][c] = tot++; 
			}
			u = ch[u][c];
		}
        if (val[u] == 0 || w[val[u]] > w[v]) val[u] = v;
        //val[u] = v;
		//if (val[u] == 0) val[u] = v;
        //else val[u] = min(val[u], v);
		Q.push(u);
	}
	void getFail() {
		queue<int> q;
		f[0] = 0;
		for (int i = 0; i < 26; ++i) {
			int u = ch[0][i];
			if (u) { f[u] = last[u] = 0; q.push(u); }
		}
		while (!q.empty()) {
			int r = q.front(); q.pop();
			for (int i = 0; i < 26; ++i) {
				int u = ch[r][i];
				if (!u) { ch[r][i] = ch[f[r]][i]; continue; }
				q.push(u);
				int v = f[r];
				while (v && !ch[v][i]) v = f[v];
				f[u] = ch[v][i];
				last[u] = val[f[u]] ? f[u] : last[f[u]];
			}
		}
	}
}ac;
int l[N];
vector<int> g[N];
ll dp[N];

int main() {
	int n;
	ac.init();
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%s%d", s, w + i); 
		int len = strlen(s); 
		l[i] = len;
		ac.insert(s, len, i);
	}
	ac.getFail();

	scanf("%s", s + 1);
	int len = strlen(s + 1);
	
	rep(i, 1, N - 1) dp[i] = inf;
	dp[0] = 0;
	int u = 0;
	rep(i, 1, len) {
		u = ac.ch[u][s[i] - 'a'];
		vector<int> v;
		int o = u;
		if (!ac.val[o]) o = ac.last[o];
		while (o) {
			v.push_back(ac.val[o]);
			o = ac.last[o];
		}
		for (int x: v) {
			dp[i] = min(dp[i], dp[i - l[x]] + w[x]);
		}
	}
	if (dp[len] >= inf) cout << -1 << endl; else cout << dp[len] << endl;
}
