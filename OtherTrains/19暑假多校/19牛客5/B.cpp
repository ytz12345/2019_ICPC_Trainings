#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const int K = 2;

ll mod;

struct matrix {
	ll c[K][K];

	void clear() {
		memset (c, 0, sizeof c);
	}

	matrix operator * (const matrix&a) const {
		matrix res; res.clear();
		for (int k = 0; k < K; k ++)
			for (int i = 0; i < K; i ++)
				for (int j = 0; j < K; j ++)
					res.c[i][j] = (res.c[i][j] 
						+ c[i][k] * a.c[k][j] % mod) % mod;
		return res;
	}

	matrix operator ^ (const char *s) const {
		matrix res, x = *this, y; res.clear();
		for (int i = 0; i < K; i ++) res.c[i][i] = 1;
		int len = strlen(s + 1);
		for (int i = len; i >= 1; i --) {
			y = x;
			for (int j = 1; j < 10; j ++) {
				if (s[i] == '0' + j) res = res * y;
				y = y * x;
			}
			x = y;
		}
		return res;
	}
}a, b;

char s[N];
 
int main(){
    scanf("%lld %lld %lld %lld %s %lld", 
    	&a.c[0][0], &a.c[0][1], 
    	&b.c[1][1], &b.c[0][1],
    	s + 1, &mod);

    b.c[1][0] = 1;
    printf("%lld\n",(a * (b ^ s)).c[0][0]);
    return 0;
}