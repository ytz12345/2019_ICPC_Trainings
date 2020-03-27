#include <bits/stdc++.h>

using namespace std;

const int N=100010;

int T, n, m, q;

int a[500010];

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int t=3;
	printf("%d\n",t);
	while(t --) {
		int n = rand()%8+1,k;
		printf("%d %d\n", n, k=rand()%100+1);
		while(n--)printf("%d ", rand()&1?(rand()%k+1):(rand()%(k*5)+1));
		puts("");
	}
}