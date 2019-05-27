#include <bits/stdc++.h>

using namespace std;

const int SIZE = 8000000;

const char *fg = "---###";

char buf[SIZE];

char text[5000000];

int len_t;

string s[1010];

int n, ans[1010];

int main() {
	ios::sync_with_stdio(false);
	int len = fread(buf, 1, SIZE, stdin);
	int now;
	for (now = 0; now < len; now ++) {
		if (buf[now] == ' ' || buf[now] == '\n') continue;
		if (buf[now] == '-' && buf[now] + 75 <= len) {
			int flag = 1;
			for (int i = 0, j = now; i < 12; i ++, j ++) {
				if (fg[i % 6] != buf[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) break;
		} 
		text[len_t ++] = buf[now];
	}
	while (now < len) {
		now += 75;
		for (; now < len; now ++) {
			if (buf[now] == ' ' || buf[now] == '\n' || buf[now] == '#') continue;
			if (buf[now] == '-' && buf[now] + 75 <= len) {
				int flag = 1;
				for (int i = 0, j = now; i < 12; i ++, j ++) {
					if (fg[i % 6] != buf[j]) {
						flag = 0;
						break;
					}
				}
				if (flag) break;
			} 
			s[n] += buf[now];
		}
		n ++;
	}

	now = 0;
	for (int i = 1; i <= n; i ++) 
		for (int j = 0; j < n; j ++) {
			int tmp = now, flag = 0, t = 0, l = s[j].size();
			for (t = 0; tmp < len && t < l; tmp ++) {
				if (text[tmp] == s[j][t]) t ++;
				if (tmp - now > 100) {
					flag = t >= 80;
					break;
				}
			}
			if (flag) {
				ans[j] = i;
				for (now = tmp; tmp < len && t < l; now ++)
					if (text[now] == s[j][t]) 
						t ++;
				break;
			}
		}

	for (int i = 0; i < n; i ++)
		cout << ans[i] << ' ';
	return 0;
}