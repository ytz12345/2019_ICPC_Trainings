#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

typedef pair<int, int> piir;

int t, n;

int cnt;

piir c[N * 2];

int d[N][3];

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
    char buffer[SIZE];
    char *s = buffer;
    void flush() {//最后需要flush!!
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if(s - buffer > SIZE - 2) flush();
        *s++ = ch;
    }
    inline void print(char *str) {//for string
        while(*str != 0) 
            print(char(*str ++));
    }
    inline void print(int x) {
        static char buf[25];
        static char *p = buf;
        if (x <  0) print('-'), x = -x;
        if (x == 0) print('0');
        while(x) *(++ p) = x % 10, x /= 10;
        while(p != buf) print(char(*(p --) ^ 48));
    }
};

struct SegmentTree {
    #define lc (o << 1)
    #define rc (o << 1 | 1)
    #define mid (l + r >> 1)

    int s[N * 6];

    void clear(int r, int o = 1, int l = 1) {
        s[o] = 0;
        if (l == r) {
            if (lc < N * 6) s[lc] = 0;
            if (rc < N * 6) s[rc] = 0;
            return;
        }
        clear(mid, lc, l);
        clear(r, rc, mid + 1);
    }

    int rk(int k = 1, int o = 1, int l = 1, int r = cnt) {
    	while (l != r) {
    		if (s[rc] >= k) {
    			l = mid + 1;
    			o = rc;
    		}
    		else {
    			k -= s[rc];
    			r = mid;
    			o = lc;
    		}
    	}
    	return r;
    }

    void insert(int x, int o = 1, int l = 1, int r = cnt) {
    	while (1) {
    		s[o] ++;
    		if (x <= mid) {
    			r = mid;
    			o = lc;
    		}
    		else {
    			l = mid + 1;
    			o = rc;
    		}
    		if (l == r) {
    			s[o] ++;
    			return;
    		}
    	}
    }

    void erase(int x, int o = 1, int l = 1, int r = cnt) {
        while (1) {
    		s[o] --;
    		if (x <= mid) {
    			r = mid;
    			o = lc;
    		}
    		else {
    			l = mid + 1;
    			o = rc;
    		}
    		if (l == r) {
    			s[o] --;
    			return;
    		}
    	}
    }

    int size() {
        return s[1];
    }

}s1, s2;

int a[N], b[N], f[N];

int in1[N], in2[N];

void work(int st) {
    static int mmax, tmp, p1, p2;
    for (int i = st; i <= n * 2; i += 2) {
        mmax = c[s1.rk()].first;
        if (s2.size() >= 2) {
            tmp = c[s2.rk()].first + c[s2.rk(2)].first;
            if (tmp > mmax) {
                f[i] = f[i - 2] + tmp;
                p1 = s2.rk();
                p2 = s2.rk(2);
                s2.erase(p1);
                s2.erase(p2);
                p1 = c[p1].second;
                p2 = c[p2].second;
                if (p1 > 0) s2.insert(d[p1][2]), in2[p1] = -p1;
                if (p2 > 0) s2.insert(d[p2][2]), in2[p2] = -p2;
                p1 = abs(p1), p2 = abs(p2);
                if (in1[p1] != 0) s1.erase(d[p1][0]), in1[p1] = 0;
                if (in1[p2] != 0) s1.erase(d[p2][0]), in1[p2] = 0;
            }
            else {
                f[i] = f[i - 2] + mmax;
                p1 = s1.rk();
                s1.erase(p1);
                p1 = c[p1].second;
                if (in2[p1] != 0) {
                    if (in2[p1] > 0) s2.erase(d[p1][1]);
                    else s2.erase(d[p1][2]);
                    in2[p1] = 0;
                }
            }
        }
        else {
            f[i] = f[i - 2] + mmax;
            p1 = s1.rk();
            s1.erase(p1);
            p1 = c[p1].second;
            if (in2[p1] != 0) {
                if (in2[p1] > 0) s2.erase(d[p1][1]);
                else s2.erase(d[p1][2]);
                in2[p1] = 0;
            }
        }
    }
}

using IO::in;
using IO::print;

int main() {
    for (in(t); t --; ) {
        in(n);
        for (int i = 1; i <= n; i ++)
            in(a[i]), in(b[i]);
        cnt = 0;
        for (int i = 1; i <= n; i ++) {
            c[++ cnt] = piir(a[i] + b[i], i);
            c[++ cnt] = piir(a[i], i);
            c[++ cnt] = piir(b[i], -i);
        }
        sort (c + 1, c + cnt + 1);
        for (int i = 1; i <= n; i ++) {
            d[i][0] = lower_bound(c + 1, c + cnt + 1, piir(a[i] + b[i], i)) - c;
            d[i][1] = lower_bound(c + 1, c + cnt + 1, piir(a[i], i)) - c;
            d[i][2] = lower_bound(c + 1, c + cnt + 1, piir(b[i],-i)) - c;
        }

        s1.clear(cnt), s2.clear(cnt);
        int mmax = 0, pos = -1;
        for (int i = 1; i <= n; i ++) {
            if (a[i] > mmax) {
                mmax = a[i];
                pos = i;
            }
        }
        f[1] = mmax;
        for (int i = 1; i <= n; i ++) {
            if (i != pos) {
                s1.insert(d[i][0]);in1[i] = i;
                s2.insert(d[i][1]);in2[i] = i;
            }
            else {
                in1[i] = 0;
                s2.insert(d[i][2]);in2[i] = -i;
            }
        }
        work(3);

        s1.clear(cnt), s2.clear(cnt); f[0] = 0;
        for (int i = 1; i <= n; i ++) {
            s1.insert(d[i][0]);in1[i] = i;
            s2.insert(d[i][1]);in2[i] = i;
        }
        work(2);

        for (int i = 1; i <= n * 2; i ++) {
            print(f[i]);
            if (i == n * 2) print("\n");
            else print(" ");
        }

    }
    //print(int(clock()));
    IO::flush();
    return 0;
}