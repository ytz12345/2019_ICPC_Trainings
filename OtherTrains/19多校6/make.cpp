#include <bits/stdc++.h>

using namespace std;

const int N=100010;

int T, n, m, q;

int a[500010];

int main() {
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int t=1;
	printf("%d\n",t);
	while(t --) {
		int n = 50000;
		printf("%d\n",n);
		for (int i = 1;  i<=n;i++)a[i]=i;
		random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');

		random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;i++)printf("%d%c",a[i],i==n?'\n':' ');
	}
}