#include <bits/stdc++.h>

using namespace std;

int t;

char s[110];

int main() {
	cin >> t;
	while (t --) {
		cin >> s;
		int i = 0, n = strlen(s);
		while (i < n && s[i] == 'y') i ++;
		if (i < n && s[i] == 'z') s[i] = 'b'; 
		puts(s);
	}
	return 0;
}