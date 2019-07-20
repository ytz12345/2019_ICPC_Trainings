#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int M = 60;
const int K = 30010;
const int T = 10010;

typedef pair<int, int> piir;
typedef long double LD;

int n, m, k, t;

int v[N];

vector <piir> bm[N];

vector <piir> bmm;

int enumd[N];

LD p[T][M], pre[T][M], suc[T][M];

LD ans;

int d, last, yes[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> t;
	for (int i = 1; i <= n; i ++) cin >> v[i];
	for (int stu, sch, day, i = 1; i <= k; i ++) {
		cin >> stu >> sch >> day;
		if (sch != m) bm[stu].push_back(piir(day, sch));
		else bmm.push_back(piir(day, stu));
	}

	for (int i = 1; i <= n; i ++) {
		sort (bm[i].begin(), bm[i].end(), [&](piir a, piir b) {
			return a.first < b.first;
		});
	}
	sort (bmm.begin(), bmm.end(), [&](piir a, piir b) {
		return a.first < b.first;
	});
	
	if (bmm.size() == 0) return puts("0 1"), 0;
	enumd[++ enumd[0]] = bmm[0].first;
	for (int i = 1; i < bmm.size(); i ++) 
		if (bmm[i].first != enumd[enumd[0]])
			enumd[++ enumd[0]] = bmm[i].first;

	for (int i = 1; i <= t; i ++) 
		for (int j = 1; j < m; j ++) 
			cin >> p[i][j];
	for (int i = t; i > 0; i --) 
		for (int j = 1; j < m; j ++) 
			suc[i][j] = suc[i + 1][j] + p[i][j];
	for (int i = 1; i <= t; i ++)
		for (int j = 1; j < m; j ++)
			pre[i][j] = pre[i - 1][j] + p[i][j];

	ans = 0, d = 1;
	LD tmp, temp; int flag;
	for (int i, ed = 1; ed <= enumd[0]; ed ++) {
		i = enumd[ed];
		for (; last < bmm.size(); last ++) {
			if (bmm[last].first > i) break;
			yes[bmm[last].second] = 1;
		}
		tmp = 0;
		for (int j = 1; j <= n; j ++) {
			if (!yes[j]) continue;
			temp = 0, flag = 1;
			for (int x = 0; x < bm[j].size(); x ++) {
				if (bm[j][x].first >= i) break;
				if (pre[bm[j][x].first - 1][bm[j][x].second] + suc[i][bm[j][x].second] == 0) {
					flag = 0;
					break;
				}
				temp += log(pre[bm[j][x].first - 1][bm[j][x].second] + suc[i][bm[j][x].second]);
			}
			if (!flag) continue;
			tmp += v[j] * exp(temp);
		}
		if (tmp > ans) ans = tmp, d = i;
	}
	printf("%.10Lf %d\n", ans, d);
	return 0;
}