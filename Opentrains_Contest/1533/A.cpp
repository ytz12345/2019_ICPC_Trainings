#include <bits/stdc++.h>

using namespace std;

struct node {
	vector <string> s;

	void in() {
		s.clear(); char str[23];
		cin >> str; string st = "";
		for (int i = 0, j = strlen(str); i < j; i ++) {
			st += str[i];
			if (i + 1 == j || isdigit(str[i]) != isdigit(str[i + 1]))
				s.push_back(st), st = "";
		}
	}

	bool operator < (const node &a) const {
		for (int i = 0, j = min(s.size(), a.s.size()); i < j; i ++) {
			if (isdigit(s[i][0]) != isdigit(a.s[i][0])) {
				if (isdigit(s[i][0])) return 1;
				return 0;
			}
			else if (isdigit(s[i][0])) {
				if (s[i].size() != a.s[i].size()) return s[i].size() < a.s[i].size();
				for (int k = 0, up = s[i].size(); k < up; k ++)
					if (s[i][k] != a.s[i][k])
						return s[i][k] < a.s[i][k];
			}
			else {
				for (int k = 0, up = s[i].size(); k < up; k ++)
					if (s[i][k] != a.s[i][k])
						return s[i][k] < a.s[i][k];
				if (s[i].size() != a.s[i].size()) return s[i].size() < a.s[i].size();
			}
		}
		if (s.size() != a.s.size()) return s.size() < a.s.size();
		return 0;
	}
}a, b;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n; a.in(); 
	while (n --) b.in(), puts(b < a ? "-" : "+");
	return 0;
}