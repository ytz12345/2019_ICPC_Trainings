#include <bits/stdc++.h>

using namespace std;

int n, sd, len;

string s[23];

__int128 dp[20][300];

void dfs(int id, int sum, __int128 num) {
	if (id >= len) {
		if (sum == 0) return;
		for (int i = sum; i < 15; i ++)
			num *= 27;
		if (dp[0][sum] == 0 || dp[0][sum] > num) dp[0][sum] = num;
		return;
	}
	dfs(id + 1, sum, num);
	dfs(id + 1, sum + 1, num * 27 + s[sd][id] - 'A' + 1);
}

void pfs(int id, int sum, __int128 num) {
	if (id >= len) {
		if (sum == 0) return;
		for (int i = sum; i < 15; i ++)
			num *= 27;
		
		for (int i = 1; i <= 15 * sd; i ++)
			if (dp[sd - 1][i] != 0 && num > dp[sd - 1][i] && (dp[sd][i + sum] == 0 || dp[sd][i + sum] > num))
				dp[sd][i + sum] = num;
		return;
	}
	pfs(id + 1, sum, num);
	pfs(id + 1, sum + 1, num * 27 + s[sd][id] - 'A' + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	len = s[0].size(), sd = 0, dfs(0, 0, 0);
	for (int i = 1; i < n; i ++) 
		len = s[i].size(), sd = i, pfs(0, 0, 0);
	for (int i = 225; i >= 1; i --)
		if (dp[n - 1][i] != 0)
			printf("%d\n", i), exit(0);
	puts("-1");
}	