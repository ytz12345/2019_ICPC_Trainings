#include <bits/stdc++.h>

using namespace std;

#define rep(i, st, ed, sp) for (int i = st; i < k; i += sp)
#define rev(i, st, ed, sp) for (int i = st; i < k; i -= sp)

int ask(int x1,int y1,int x2,int y2){
	static int x;
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	cin >> x;
	return x;
}

int n, a[110][110];

int main() {
	cin >> n;
	a[1][1] = 1;
	rep(i, 3, n + 1, 1)
		a[1][i] = a[1][i - 2] ^ (!ask(1, i - 2, 1, i));
	
	rep(i, 2, n + 1, 1)
		rep(j, )
	for(int i=2;i<=n;++i){
		for(int j=n;j>=1;--j){
			if(j>=2){
				a[i][j]=a[i-1][j-1]^(!ask(i-1,j-1,i,j));
			}
			else{
				a[i][j]=a[i][j+2]^(!ask(i,j,i,j+2));
			}
		}
	}
	int flag=0;
	for(int i=1;i<n-1;++i){
		if(a[i][i]==1&&a[i+2][i+2]==0){
			if(ask(i,i,i+1,i+2)){
				flag=a[i+1][i+2]^1;
			}
			else if(ask(i,i+1,i+2,i+2)){
				flag=a[i][i+1];
			}
			else if(a[i][i+1]==a[i+1][i+2]){
				flag=a[i][i+1]^a[i][i+2]^1;
			}
			else {
				flag=a[i][i+1]^1;
			}
			break;
		}
	}
	puts("!");
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i+j&1)a[i][j]^=flag;
			printf("%d",a[i][j]);
		}
		puts("");
	}
}