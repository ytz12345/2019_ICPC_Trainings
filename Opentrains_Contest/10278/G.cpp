#include <bits/stdc++.h>

using namespace std;

int T;

string s, t, ans;

deque <char> q;

int pre[2019];

stack <int> sta;

void mmin(const string &a, const string &b, string &c) {
	if (a.size() < b.size()) {c = a; return;}
	if (a.size() > b.size()) {c = b; return;}
	for (int i = 0, up = min(a.size(), b.size()); i < up; i ++)
		if (a[i] != b[i]) {
			if (a[i] < b[i]) c = a;
			else c = b;
			return;
		}
	c = a;
}

void dfs(int l, int r, string &res) { //[l, r)
	int cnt = 0; bool eor = false; int pos;
	while (l < r && pre[r - 1] == l) l ++, r --;
	if (l >= r) {res.clear(); return;}
	for (int i = l; i < r; i ++) {
		if (t[i] == '(') cnt ++;
		else if (t[i] == ')') cnt --;
		else if (t[i] == '|') {
			if (cnt == 0) {
				eor = true;
				pos = i;
				break;
			}
		} 
	}
	if (eor) {
		string L, R; 
		L.clear(), R.clear(); 
		dfs(l, pos, L);
		dfs(pos + 1, r, R);
		mmin(L, R, res);
	}
	else {
		string tmp;
		res.clear();
		cnt = 0;
		for (int i = l; i < r; i ++) {
			if (t[i] == '(') cnt ++;
			else if (t[i] == ')') {
				cnt --;
				if (cnt == 0) {
					tmp.clear();
					dfs(pre[i], i + 1, tmp);
					res += tmp;
				}
			}
			else {
				if (cnt != 0 || t[i] == '$') continue;
				res += t[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while (T --) {
		cin >> s;
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == '*') {
				if (q.empty()) continue;
				if (i != 0 && s[i - 1] == '*') continue;
				if (q.back() != ')') q.pop_back();
				else {
					int cnt = 1; q.pop_back();
					while (!q.empty() && cnt != 0) {
						char x = q.back(); q.pop_back();
						if (x == '(') cnt --;
						else if (x == ')') cnt ++;
					}
				}
			}
			else q.push_back(s[i]);
		}
		t.clear();
		while (!q.empty()) t += q.front(), q.pop_front();
		for (int i = 0; i < t.size(); i ++) {
			pre[i] = -1;
			if (t[i] == '(') sta.push(i);
			else if (t[i] == ')') pre[i] = sta.top(), sta.pop();
		}
		ans.clear(), dfs(0, t.size(), ans);
		if (ans.size() == 0) ans = "$";
		cout << ans << '\n';
	}
	return 0;
}