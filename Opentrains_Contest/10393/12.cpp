#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;

char s[N][4];

int num[N], out[N];

char intToChar(int x) {
	if (x < 10) return '0' + x;
	return 'A' + x - 10;
}

char *intToHex(int x) {
	static char str[10];
	static int len; len = 0;
	if (!x) str[len ++] = '0';
	else while (x) str[len ++] = intToChar(x % 16), x /= 16;
	for (int i = 0, j = len - 1; i < j; i ++, j --) swap(str[i], str[j]);
	str[len] = 0;
	return str;
}

void print() {
	if (!out[0]) return;
	if (out[0] < 3) {out[0] = 0; return;}
	for (int i = 1; i <= out[0]; i ++)
		printf("%s%c", intToHex(out[i]), i == out[0] ? '\n' : ' ');
	out[0] = 0;
}

char st[20];

int cnt;

int charToInt(char ch) {
	if (ch <= '9') return ch - '0';
	return ch - 'A' + 10;
}

int strToInt(char *str, int id) {
	return num[id] = charToInt(str[0]) * 16 + charToInt(str[1]);
}

void strToBin(char *str, int id) {
	st[8] = cnt = 0;
	for (int i = 7, j = strToInt(str, id); i >= 0; i --, j >>= 1) 
		st[i] = (j & 1) + '0';
	while (cnt < 8 && st[cnt] == '1') cnt ++;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> s[n ++]); n --;
	/*for (int i = 0; i < n; i ++)
		printf("%s\n", s[i]);*/
	for (int up, j, i = 0; i < n; ) {
		strToBin(s[i], i);
		//printf("out %d %s %s %d\n", i, s[i], st, cnt);
		if (cnt == 1 || cnt > 6) {
			print();
			i ++;
		}
		else {
			if (i + cnt > n) break;
			if (cnt == 0) {
				out[++ out[0]] = num[i];
				i ++;
			}
			else {
				int flag = 1;
				out[++ out[0]] = num[i] & ((1 << (8 - cnt)) - 1);
				for (j = i + 1, up = i + cnt; j < up; j ++) {
					strToBin(s[j], j);
					if (cnt != 1) {
						flag = 0;
						break;
					}
					out[out[0]] = (out[out[0]] << 6) | (num[j] & 63);
				}
				if (!flag) {
					out[0] --;
					print();
				}
				i = j;
			}
		}
	}
	print();
	return 0;
}