#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
typedef pair<int, int> P;
const int N = 2e5 + 7;
P e[N];
P dp[N][6][4];
int id[N][6];

int head[N], len;

struct edge{
	int to, next;
}E[N << 1];

void add(int u, int v) {
	E[++ len] = (edge){v, head[u]}, head[u] = len;
	E[++ len] = (edge){u, head[v]}, head[v] = len;
}

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    rep(i, 1, m) {
        scanf("%d%d", &e[i].first, &e[i].second);    
    }
    scanf("%d%d", &a, &b);


    auto ok = [&](P v[4], P x, int sz) -> bool {
        if (sz == 0) return 1;
        if (sz == 4) return 0;
        for (int i = 0; i < sz; i ++) {
        	P p = v[i];
        	if (p.first == x.first && p.second == x.second) return 0;
        }

        static map<int, int> mp1, mp2;
    	mp1.clear(), mp2.clear();

        for (int i = 0; i < sz; i ++) {
        	P p = v[i]; 
        	mp1[p.first] = 1;
        }

        if (!mp1.count(x.first)) {
            if (mp1.size() >= 2) return 0; return 1;
        }

        for (int i = 0; i < sz; i ++) {
        	P p = v[i]; 
        	if (p.first == x.first) mp2[p.second] = 1;
		}	

        if (mp2.size() >= 2) return 0;

        return 1;

    };

    auto check = [&](int k) -> bool {

    	len = 0;
        rep(i, 1, n) head[i] = 0;
        rep(i, 1, k) add(e[i].first, e[i].second);
        
        memset (id, 0, sizeof id);

        dp[a][0][++ id[a][0]] = (P(-1, -1));


        rep(d, 0, 4) {
            rep(i, 1, n) 
            if (id[i][d] != 0) {
                if (d && (i == a || i == b)) continue;
                for (int v, i1 = head[i]; i1 != 0; i1 = E[i1].next) {
                	v = E[i1].to;
                    for (int i2 = 0; i2 < id[i][d]; i2 ++) {
                    	P p = dp[i][d][i2];
                        if (p.first == v || p.second == v) continue;
                        if (v == b && d == 4) return 1;
                        if (d < 4 && ok(dp[v][d + 1], P(i, p.first), id[v][d + 1])) {
                            dp[v][d + 1][id[v][d + 1] ++] = P(i, p.first);
                        }
                    }
                }
            }
        }

        return 0;
    };


    if (!check(m)) {
        printf("-1\n"); return 0;
    }
    
    int L = 1, R = m;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid; else L = mid + 1;
    }

    printf("%d\n", L);
}

/*
10 9
1 6
6 9
9 10
10 3
3 2
2 7
7 5
5 8
8 4
6 7

10 10 
1 2 
1 3 
1 4 
1 5 
1 6 
1 7 
1 8 
1 9 
10 2 
10 3 
1 10

5 5
1 2
2 3
3 4
2 4
2 5
1 5
*/