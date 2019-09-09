#include <bits/stdc++.h>
using namespace std;
int n;
int a[100007];
bool dp[100007][3][3];
int last[100007][3][3];
int stk[3];
int res[100007];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=2;i<n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,false,sizeof(dp));
        dp[2][2][1]=dp[2][2][2]=true;
        for(int i=3;i<=n;i++){
            for(int j=0;j+i<=n&&j<=2;j++){
                for(int k=0;k<=2;k++){
                    for(int l=0;l+i<=n+1&&l<=2;l++){
                        if(dp[i-1][k][l]){
                            stk[0]=a[i-3+k];
                            stk[1]=a[i-2+l];
                            stk[2]=a[i-1+j];
                            sort(stk,stk+3);
                            if(a[i-1]==stk[1]){
                                dp[i][l][j]=true;
                                last[i][l][j]=k;
                            }
                        }
                    }
                }
            }
        }
        if(!dp[n][0][0]&&!dp[n][1][0]){
            printf("-1\n");
        }
        else {
            int j,k=0;
            if(dp[n][0][0])j=0;
            else j=1;
            for(int i=n;i>=2;i--){
                res[i]=a[i-1+k];
                int p=last[i][j][k];
                k=j;
                j=p;
            }
            res[1]=a[2];
            for(int i=1;i<=n;i++)printf("%d%c",res[i],i==n?'\n':' ');
        }
    }
}