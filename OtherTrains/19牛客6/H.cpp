#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=1e9+7;
vector<int>p[N];deque<int>q;
int A[21],B[21],d1[21][N],d2[21][N],d[N];bool v[N];
inline void bfs(){
    while(!q.empty()){
        int x=q.front();q.pop_front();
        for(auto&i:p[x])if(!v[i]){
            if(d[i]<=d[x])q.push_front(i);
            else{
                d[i]=d[x]+1;q.pb(i);
            }v[i]=1;
        }
    }
}
inline void sol(int CA){int n,m;ll ans=0;
    scanf("%d%d",&n,&m);
    rep(i,1,n)p[i].clear();
    rep(i,1,m){int x,y;
        scanf("%d%d",&x,&y);
        p[x].pb(y);p[y].pb(x);
    }int SA,SB;
    scanf("%d",&SA);
    rep(i,1,SA){
        scanf("%d",&A[i]);
        rep(j,1,n)d[j]=n+1,v[j]=0;
        q.pb(A[i]);d[A[i]]=0;v[A[i]]=1;bfs();
        rep(j,1,n)d1[i][j]=d[j];
    }
    scanf("%d",&SB);
    rep(i,1,SB){
        scanf("%d",&B[i]);
        rep(j,1,n)d[j]=n+1,v[j]=0;
        q.pb(B[i]);d[B[i]]=0;v[B[i]]=1;bfs();
        rep(j,1,n)d2[i][j]=d[j];
    }
    printf("Case #%d: ",CA);
    rep(i,1,SA)rep(j,1,SB){q.pb(A[i]);
        rep(k,1,n)d[k]=d1[i][k]+d2[j][k],v[k]=0;
        v[A[i]]=1;bfs();rep(k,1,n)ans+=d[k];
    }
    ll rs=1ll*n*SA*SB,gc=__gcd(ans,rs);
    ans/=gc;rs/=gc;
    printf("%lld",ans);
    if(rs>1)printf("/%lld",rs);putchar('\n');
}
int main(){int t;
    scanf("%d",&t);
    rep(i,1,t)sol(i);
}