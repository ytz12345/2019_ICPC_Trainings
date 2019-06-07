#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

vector <int> ans;

int main() {
	ios::sync_with_stdio(false);
	scanf("%s", s + 1);
	if (s[1] == '1') s[0] = '0';
	else s[0] = '1';
	int n = strlen(s + 1) / 3;
	for (int i = 0; i < n; i ++) {
		int cnt = 0;
		for (int j = 1; j <= 3; j ++)
			cnt += s[i * 3 + j - 1] != s[i * 3 + j];
		if (cnt >= 2) continue;
		if (cnt == 0) {
			ans.push_back(i * 3 + 1);
		}
		else {
			if (s[i * 3 + 1] != s[i * 3]) ans.push_back(i * 3 + 2), s[i * 3 + 3] ^= 1;
			else if (s[i * 3 + 1] != s[i * 3 + 2]) ans.push_back(i * 3 + 1);
			else ans.push_back(i * 3 + 2), s[i * 3 + 3] ^= 1;
		}
	}
	cout << ans.size() << endl;
	for (int i : ans)
		cout << i << ' ';
}