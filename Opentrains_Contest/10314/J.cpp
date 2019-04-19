#include <bits/stdc++.h>

using namespace std;

bool ok(char c) {
	return c == EOF || c == '.' || c == 'x' || c == 'o';
}

int get_ch() {
	static int ch;
	while (!ok(ch = getchar()));
	if (ch == EOF) exit(0);
	return ch;
}

struct game {
	char c[3][3];

	void scan() {
		for (int i = 0; i < 3; i ++)
			for (int j = 0; j < 3; j ++) 
				c[i][j] = get_ch();
	}

	void putx(int x, int y) {
		c[x][y] = 'x';
	}

	void print() {
		for (int i = 0; i < 3; i ++)
			printf("%c%c%c\n", c[i][0], c[i][1], c[i][2]);
		fflush(stdout);
	}

	bool check(char ch) {
		int flag = 0;
		if (c[0][0] == ch && c[1][1] == ch && c[2][2] == ch) flag = 1;
		if (c[0][2] == ch && c[1][1] == ch && c[2][0] == ch) flag = 1;
		for (int i = 0; i < 3; i ++) {
			if (c[i][0] == ch && c[i][1] == ch && c[i][2] == ch) flag = 1;
			if (c[0][i] == ch && c[1][i] == ch && c[2][i] == ch) flag = 1;
		}
		return flag;
	}
}s;

int dfs(int now) {
	int cnt = 0;
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			if (s.c[i][j] != '.') continue;
			cnt ++;
			s.c[i][j] = now ? 'x' : 'o';
			if (now && s.check('x')) {
				s.c[i][j] = '.';
				return 1;
			}
			if (dfs(now ^ 1) == -1) {
				s.c[i][j] = '.';
				return 1;
			}
			s.c[i][j] = '.';
		}
	}
	if (!cnt) return 1;
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	while (1) {
		s.scan();
		s.putx(1, 1);
		s.print();
		while (1) {
			s.scan();
			int flag = 0;
			for (int i = 0; i < 3; i ++) {
				for (int j = 0; j < 3; j ++) {
					if (s.c[i][j] != '.') continue;
					s.c[i][j] = 'x';
					if (s.check('x')) {
						flag = 1;
						break;
					}
					if (dfs(0) == -1) {
						flag = 1;
						break;
					}
					s.c[i][j] = '.';
				}
				if (flag == 1) break;
			}
			s.print();
			if (s.check('x')) break;
		}
	}
	return 0;
}