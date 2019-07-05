#include <bits/stdc++.h>

using namespace std;

vector <string> vs;

void dfs(string s, int sz) {
	if (sz > 0 && sz < 10) {
		int flag = 1;
		for (int i = 1; i < sz; i ++) {
			if (sz % i == 0) {
				int ok = 0;
				for (int j = 0; j < sz; j ++) 
					if (s[j % i] != s[j])
						ok = 1;
				if (!ok) flag = 0;
			}
		}
		if (flag) vs.push_back(s);
	}
	if (sz >= 10) return;
	dfs(s + 'a', sz + 1);
	dfs(s + 'b', sz + 1);
	dfs(s + 'c', sz + 1);
} 

int main() {
	ios::sync_with_stdio(false);
	dfs("", 0);
	/*cout << vs.size() << endl;
	for (auto i : vs)
		cout << i << endl;*/
	long long ans = 0;
	int n; char str[23333];
	//cout << clock() << endl;
	cin >> n >> str;
	for (int len, t, i = 0; i < vs.size(); i ++) {
		t = vs[i].size();
		if (ans * t >= n * n) continue;
		len = 0;
		for (int j = 0, k = 0; j < n; j ++) {
			if (str[j] == vs[i][k]) {
				k ++;
				if (k == t) k = 0, len ++;
			}
		}
		//if (vs[i] == "ab") cout << len << endl;
		ans = max(ans, 1ll * len * len * t);
	}
	cout << ans << endl;
	//cout << clock() << endl;
	return 0;
}