#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 1e6 + 5;

int t, n;

long long ans;

deque <int> q;

int a[N], b[N];

namespace IO {//only for int!!!
    static const int SIZE = 1 << 20;
    inline int get_char() {
        static char *S, *T = S, buf[SIZE];
        if (S == T) {
            T = fread(buf, 1, SIZE, stdin) + (S = buf);
            if (S == T) return -1;
        }
        return *S ++;
    }
    inline void in(int &x) {//for int
        static int ch;
        while (ch = get_char(), ch < 48);x = ch ^ 48;
        while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
    }
};

using IO::in;

int main() {
	//freopen("test.txt", "r", stdin);
	for (in(t); t --; ) {
		in(n); q.resize(n); ans = 0;
		for (int i = 0; i < n; i ++) 
			in(a[i]), in(b[i]), q[i] = i;
		for (int i = 0, j, flag; i < n; i ++) {
			flag = 0;
			while (!q.empty() && b[i] > 0) {
				j = q.front(), q.pop_front();
				if (j == i) {
					q.push_back(j);
					if (flag == 0) {
						flag = 1;
						continue;
					}
					else {
						break;
					}
				}
				else flag = 0;
				ans += min(b[i], a[j]);
				if (b[i] >= a[j]) b[i] -= a[j];
				else a[j] -= b[i], b[i] = 0, q.push_back(j);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
