#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> piir;

typedef vector<piir> vp;

const int N = 31;

int n, k;

piir p[N];

vector <vp> ans;

vp tmp;

int now;

bool operator < (const vp &a, const vp &b) {
	for (int i = 0; i < n; i ++)
		if (a[i] != b[i])
			return a[i] < b[i];
	return 0;
}

void dfs(int s) {
	int l, r, cl, cr;
	for (int i = 0; i < n; i ++) if ((s >> i) & 1)
		for (int j = 0; j < n; j ++) if (i != j && ((s >> j) & 1) && (p[i] < p[j])) {
			l = 0, r = 0, cl = 0, cr = 0;
			for (int k = 0; k < n; k ++) if (k != j && i != k && ((s >> k) & 1))
				if ((p[j].x - p[i].x) * (p[k].y - p[i].y) > (p[k].x - p[i].x) * (p[j].y - p[i].y))
					cl ++, l |= 1 << k;
				else
					cr ++, r |= 1 << k;

			if (cl & 1) continue;
			tmp[now ++] = p[i];
			tmp[now ++] = p[j];
			if (now == n) ans.push_back(tmp);
			else {
				if (l) dfs(l);
				if (r) dfs(r);
			}  
			now -= 2;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;
	tmp.resize(n);
	dfs((1 << n) - 1);
	cin >> k;
	nth_element(ans.begin(), ans.begin() + k, ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < n; i ++)
		printf("%d %d\n", ans[k][i].x, ans[k][i].y);
	return 0;
}