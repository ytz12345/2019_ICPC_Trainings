#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

ll ans;

int n, m;

int h[N][N];

char s[N][N];

void rot() {
	static int t[N][N];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			t[j][n + 1 - i] = s[i][j];
	swap(n, m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			s[i][j] = t[i][j];
}

int f(int x) {
	return x - 1;
}

void work(int x, int y) {
	static int base, head; 
	base = 1 - x, head = x;
	while (x <= n && y <= m) {
		if (s[x][y] != s[head][y - (x - head)]) {
			while (head != x) ans += f(x - head), head ++, base --;
		}
		else {
			while (h[x][y] < base) ans += f(x - head), head ++, base --;
		}
		x ++, y ++;
	}
	//cout << "?? " << head << ' ' << x << endl;
	while (head < x) ans += f(x - head), head ++;
	//cout << ' ' << ans << endl;
}

void calc() {
	/*for (int i = 1; i <= n; i ++)
		printf("%s\n", s[i] + 1);
	puts("");*/

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (j == 1 || s[i][j] != s[i][j - 1]) h[i][j] = 1;
			else h[i][j] = h[i][j - 1] + 1;
		}
		for (int j = 1; j <= m; j ++) {
			h[i][j] -= i;
			//printf("%d%c", h[i][j], j == m ? '\n' : ' ');
		}
	}

	for (int i = n; i > 1; i --) work(i, 1);
	for (int i = 1; i <= m; i ++) work(1, i);
	//cout << ans << endl;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	calc(), rot();
	calc(), rot();
	calc(), rot();
	calc();
	cout << ans << endl;
	return 0;
}