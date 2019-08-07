#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

char s[2019];

int a[10];

int cnt;

struct {int id, len;}b[10];

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt ++) {
		scanf("%s", s);

		for (int i = 0; i < 8; i ++) {
			a[i] = 0;
			for (int j = i * 16, up = j + 16; j < up; j ++)
				a[i] = a[i] * 2 + s[j] - '0';
		}

		cnt = 0;

		for (int i = 1; i < 8; i ++) {
			if (a[i] == 0) {
				if (a[i - 1] == 0) {
					if (i - 2 < 0 || a[i - 2] != 0) {
						cnt ++;
						b[cnt].id = i - 1;
						b[cnt].len = 2;
					}
					else {
						b[cnt].len ++;
					}
				}
			}
		}

		printf("Case #%d: ", tt);
		if (cnt == 0) {
			for (int i = 0; i < 8; i ++)
				printf("%x%c", a[i], i == 7 ? '\n' : ':');
		}
		else if (cnt == 1) {
			if (b[1].len == 8) {
				puts("::");
			}
			else {
				for (int i = 0; i < b[1].id; i ++) {
					printf("%x", a[i]);
					if (i + 1 != b[1].id) printf(":");
				}
				printf("::");
				for (int i = b[1].id + b[1].len; i < 8; i ++) {
					printf("%x", a[i]);
					if (i != 7) printf(":");
				}
				puts("");
			}
		}
		else {
			int pos = 1, len = 0;
			for (int i = 1; i <= cnt; i ++) {
				if (b[i].len > len) {
					pos = i, len = b[i].len;
				}
				else if (b[i].len == len) {
					if (b[i].id + b[i].len != 8) {
						pos = i, len = b[i].len;
					}
					else if (b[pos].id == 0) {
						pos = i, len = b[i].len;
					}
				}
			}
 
			for (int i = 0; i < b[pos].id; i ++) {
				printf("%x", a[i]);
				if (i + 1 != b[pos].id) printf(":");
			}
			printf("::");
			for (int i = b[pos].id + b[pos].len; i < 8; i ++) {
				printf("%x", a[i]);
				if (i != 7) printf(":");
			}
			puts("");
		}
	
	}

	return 0;
}