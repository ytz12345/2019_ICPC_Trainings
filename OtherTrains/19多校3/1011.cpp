#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define rep0(i,r) for(int i=0;i<r;i++)

int const N=200200;
typedef long long ll;

// struct E{
//     int t,next;
//     long long  v;
// };
// E e[N<<1];
// int fi[N],total;

int n,vis[N];
ll f1[N][2],f2[N][2],f[N][2],dp[N][2],efa[N];
vector< pair<int,ll> > v[N];

#define vsz(x) (int)(v[x].size())
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void dfs_bottom_up(int x) 
{
    vis[x]=1;
    f[x][0]=f[x][1]=dp[x][0]=dp[x][1]=f1[x][0]=f1[x][1]=f2[x][0]=f2[x][1]=0;
    if (!vsz(x)) return;
    for(auto sonx:v[x]) {
        int nson=sonx.fi; 
        if (vis[nson]) continue;
        ll vson=sonx.se; 
        efa[nson]=vson;
        dfs_bottom_up(nson);
        f[x][1]=min(min(max(f[x][1],f[nson][0]+vson),
                        max(f[x][0],f[nson][0])),
                    max(f[x][0],f[nson][1]+vson));
        f[x][0]=max(f[nson][0]+vson,f[x][0]);
    }
    ll m1=0,m2=0;
    rep(i,0,vsz(x)-1) {
        int nson=v[x][i].fi; 
        ll vson=v[x][i].se; 
        f1[nson][0]=m1;
        f1[nson][1]=m2;
        m2=min(min(    m2+f[nson][0]+vson,
                       m1+f[nson][1]+vson),
                m1+f[nson][0]);
        m1=max(f[nson][0]+vson,m1);
    }
    m1=0,m2=0;
    dow(i,0,vsz(x)-1) {
        int nson=v[x][i].fi;
        ll vson=v[x][i].se;
        f2[nson][0]=m1;
        f2[nson][1]=m2;
        m2=min(min(    m2+f[nson][0]+vson,
                       m1+f[nson][1]+vson),
                m1+f[nson][0]);
        m1=max(f[nson][0]+vson,m1);
    }

    rep(i,0,vsz(x)-1) {
        int nson=v[x][i].fi;
        f1[nson][1]=min(max(f1[nson][1],f2[nson][0]),
                        max(f2[nson][0],f1[nson][1]));
        f1[nson][0]=max(f1[nson][0],f2[nson][0]);
    }
}

void dfs_top_down(int x,int fa=0) {
    vis[x]=1;
    if (fa) {
        dp[x][0] = efa[x]+max(dp[fa][0],f1[x][0]);
        dp[x][1] = min(min(max(dp[fa][0],f1[x][0]),
                            efa[x]+max(dp[fa][1],f1[x][0])),
                        efa[x]+max(dp[fa][0],f1[x][1]));
    }
    for(auto sonx:v[x]) {
        int nson=sonx.fi;
        if (vis[nson]) continue;
        dfs_top_down(nson,x);
    }
} 

void solve()
{
    scanf("%d",&n);
    rep(i,1,n-1) {
        int j,k;
        ll l;
        scanf("%d %d %lld",&j,&k,&l);
        v[j].pb(mp(k,l));
        v[k].pb(mp(j,l));
    }
    rep(i,1,n) vis[i]=0;
    dfs_bottom_up(1);
    rep(i,1,n) vis[i]=0;
    dfs_top_down(1);
    int ans1=0;
    ll ans2=1LL<<60;
    rep(i,1,n) 
        if (ans2>min(max(f[i][0],dp[i][1]),max(f[i][1],dp[i][0]))) {
            ans2=min(max(f[i][0],dp[i][1]),max(f[i][1],dp[i][0]));
            ans1=i;
        } 
//    rep(i,1,n)
//        cout<<f[i][0]<<" "<<f[i][1]<<" "<<dp[i][0]<<" "
//            <<dp[i][1]<<" "<<f1[i][0]<<" "<<f1[i][1]<<endl;
    printf("%d %lld\n",ans1,ans2);
    rep(i,1,n) v[i].clear(); 
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--) solve();    
    return 0;
}