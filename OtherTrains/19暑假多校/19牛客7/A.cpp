#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 450;

char a[N];

int minrep(int n) {
	int i = 0, j = 1, k = 0, t;
	while (i < n && j < n && k < n) 
		if (t = a[(i + k) % n] - a[(j + k) % n]) {
			if (t > 0) i += k + 1;
			else       j += k + 1;
			if (i == j) j ++;
			k = 0;
		}	
		else 
			k ++;
	return i < j ? i : j;
}

int isMin(char *str, int n) {
	for (int i = 0; i < n; i ++)
		a[i] = a[i + n] = str[i];
	int p = minrep(n);
	for (int i = 0; i < n; i ++) {
		if (str[i] != str[p])
			return 0;
		p = (p + 1) % n;
	}
	return 1;
}

int t, n;

char s[N];

int dp[N];

int out;

int pre[N];

void print(int p) {
	if (!p) return;
	print(pre[p]);
	if (out) putchar(' ');
	for (int i = pre[p] + 1; i <= p; i ++)
		putchar(s[i]);
	out ++;
}

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		memset (dp, 0x3f, sizeof dp);
		/*dfs(0, n - 1);
		out = 0;
		print(0, n - 1);
		puts("");*/
		dp[0] = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < i; j ++) {
				if (dp[j] + 1 < dp[i] && isMin(s + j + 1, i - j)) {
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
		}
		out = 0;
		print(n);
		puts("");
	}
	//printf("%d\n", clock());
	return 0;
}