#include <bits/stdc++.h>

using namespace std;

int n;

char s[100100];

bool issame() {
	for (int i = 1; i < n; i ++)
		if (s[i] != s[0])
			return 0;
	return 1;
}

bool ispa(char *str) {
	for (int i = 0, j = strlen(str) - 1; i < j; i ++, j --)
		if (str[i] != str[j])
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	if (issame()) puts("-1");
	else if (!ispa(s)) puts("1");
	else {
		int flag = 0;
		for (int i = 1, j = n / 2; i < j; i ++) {
			if (s[i] != s[0]) {
				if (!ispa(s + i + 1)) flag = 1;
				else flag = 0;
				break;
			}
		}
		puts(flag ? "2" : "-1");
	}
	return 0;
}