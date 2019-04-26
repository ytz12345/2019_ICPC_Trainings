#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 3;

bitset <N> a[N], b;

int n, m, k;

string s[N], t;

map <string, int> p;

vector <int> e[N];

int x, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> n;
	for (int i = 0; i < n; i ++) {
		cin >> s[i]; 
		a[i].reset();
		for (int j = 0; j < s[i].size(); j ++) {
			if ('A' <= s[i][j] && s[i][j] <= 'Z') {
				a[i][j] = 1;
				s[i][j] += 'a' - 'A';
			}
		}
		if (!p[s[i]]) p[s[i]] = ++ cnt;
		e[p[s[i]]].push_back(i);
	}
	cin >> m;
	for (int i = 0; i < m; i ++) {
		cnt = 0;
		cin >> t;
		b.reset();
		for (int j = 0; j < t.size(); j ++)
			if ('A' <= t[j] && t[j] <= 'Z')
				b[j] = 1, t[j] += 'a' - 'A'; 
		if ((x = p[t]) != 0) {
			for (int j : e[x])
				cnt += (b ^ (a[j])).count() <= k;
		} 
		printf("%d\n", cnt);
	}	
	return 0;
}