#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n;

struct node {
	int id, x;
	bool operator < (const node &a) const  {
		if (x != a.x) return x > a.x;
		return id > a.id;
	}
}a[N];

inline int get_char() {
	static const int SIZE = 1 << 20;
	static char *S, *T = S, buf[SIZE];
	if (S == T) {
		T = fread(buf, 1, SIZE, stdin) + (S = buf);
	}
	return *S ++;
}

inline void in(int &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

int main() {
	ios::sync_with_stdio(false);
	in(t);
	while (t --) {
		in(n);
		for (int i = 1; i <= n; i ++)
			in(a[i].x), a[i].id = i;
		sort (a + 1, a + n + 1);
		int m = 1;
		for (int i = 2; i <= n; i ++) {
			if (a[i].id > a[i - 1].id) {
				int j = i + 1;
				while (j <= n && a[j].x == a[i].x) {
					if (a[j].id < a[i - 1].id)
						m ++;
					j ++;
				}
				break;
			}
			m = i;
		}
		printf("%d\n", n - m);
	}
	return 0;
}