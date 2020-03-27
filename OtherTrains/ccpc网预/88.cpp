#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define fir first
#define sec second

const int N=100100;
typedef long long LL;
typedef pair<LL,LL> piir;
piir p[N];
int n;
LL kk,sum[N],pre[N];
int id[N];

LL calc() {
    LL res = kk, tt = n - 1;
    for (int i = 1; i <= n; i ++) {
        LL tmp = (p[id[i]].sec+kk-1)/kk;
        if (tt >= tmp) res +=tmp*kk,tt -=tmp;
        else res += p[id[i]].sec,tt=0;
      //  if(id[1]==1&&id[2]==2&&id[3]==3) printf("%d %lld\n",i,res);
    }
   /* if(res==301){
        for (int i=1;i<=n;i++)
            printf("%d ", id[i]);
        exit(0);
    }*/
    return res;
}

void solve()
{
    scanf("%d %lld",&n,&kk);
    rep(i,1,n) {
        scanf("%lld",&p[i].sec);
        p[i].fir=p[i].sec/kk+(p[i].sec%kk>0?1:0);
    }
    rep(i,1,n) id[i] = i;
    LL  ans = 1e18;
    while(1) {
        ans =min(ans, calc());
        if (!next_permutation(id +1,id+n+1)) break;
    }
    printf("%lld\n", ans);
}

int main()
{
    int tt;
    scanf("%d",&tt);
    while (tt--) solve();
 } 