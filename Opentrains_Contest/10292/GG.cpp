#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 210;

string ans, str, s;

int n, len;

int cnt[26];

int vis[N][N], dp[N][N], len1;

int dfs(int l, int r) {
	if (l > r) return 1;
	if (l == r) return dp[l][r] = str[0] == s[l];
	if (vis[l][r]) return dp[l][r];
	dp[l][r] = 0;
	int p_1 = (r - l + 1) % len1;
	p_1 = (p_1 + len1 - 1) % len1;
	if (str[p_1] != s[r]) return dp[l][r];

	for (int k = r - 1; k >= l; k -= len1) {
		if (dfs(l, k) && dfs(k + 1, r - 1)) return dp[l][r] = 1;
	}
	return dp[l][r];
}
map<string, int> mp;
bool check() {
	static int c[26];
	//cout << str << endl;
	int k = n / str.size();
	memset (c, 0, sizeof c);
	for (int i = 0; i < str.size(); i ++)
		c[str[i] - 'a'] ++;
	for (int i = 0; i < 26; i ++) {
		if (cnt[i] == 0) continue;
		if (c[i] == 0) return 0;
		if (cnt[i] % c[i] != 0 || cnt[i] / c[i] != k) return 0;
	}
	memset(vis, 0, sizeof(vis));
	len1 = str.size();
	return dfs(0, n - 1);
}

void judge(int x) {
	if (x >= len) return;
	mp.clear();
	for (int i = 0; i + x <= n; i ++) {
		str = s.substr(i, x);
		if (mp.find(str) != mp.end()) continue;
		mp[str] = 1;
		if (check()) {
			len = x;
			ans = s.substr(i, x);
			return;
		}
	} 
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> s) {
		ans = s, len = n = s.size();
		memset (cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i ++)
			cnt[s[i] - 'a'] ++;
		bool flag = 1;
		for (int i = 0; i < len; ++ i) {
			if (s[i] != s[0]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << s[0] << '\n'; continue;
		}
		auto check2 = [&]() -> bool {
			char s1 = s[0], s2 = s[n - 1];
			int cnt = 0;
			for (int i = 0; i < n; ++ i) {
				if (s[i] == s1) cnt ++;
				else cnt --;
				if (cnt < 0) return 0;
			}
			cout << s1 << s2 << '\n';
			return 1;
		};
		if (check2()) continue;
		for (int i = 3; i < n; ++ i)
			if (n % i == 0) judge(i); 
		cout << ans << '\n';
	}
	return 0;
}