#include<cstring>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define rep0(i,r) for(int i=0,rr=(int)r;i<rr;i++)
#define fir first
#define sec second
#define mp make_pair
#define pb push_back


const int N=100510;
const int Mod = 1e9 + 7;
typedef long long ll;
ll px[N],py[N],vk[N],vv[N];
int n;

ll normal(ll x) {
    return (x % Mod + Mod) % Mod;
}

ll calc(ll x) {
    ll res = 1, k = Mod - 2;
    for (x %= Mod ; k > 0; k >>= 1, x = x * x % Mod)
        if (k & 1) res = res * x % Mod;
    return normal(res);
}

int check(ll k,ll b,ll x,ll y)
{
    return normal(y-(k*x+b))==0;
}

int check()
{
    ll sumk=0,sumb=0;
    rep(i,2,n-1) sumb=normal(sumb+vv[i-1]*px[i]);
    rep(i,2,n-1) sumk=normal(sumk-vv[i-1]);
    rep(i,1,n) {
        if (!check(sumk,sumb,px[i],py[i])) return 0;
        if (i>1 && i<n) sumb=normal(sumb-vv[i-1]*px[i]*2),sumk=normal(sumk+2*vv[i-1]);
    }
    return 1;
}

void solve()
{
    scanf("%d",&n);
    n++;
    rep(i,1,n) {
        scanf("%lld %lld",&px[i],&py[i]);
        if (i>1) vk[i-1]=normal((py[i]-py[i-1])*calc(px[i]-px[i-1]));
    }
    ll sum=0;
   // puts("");
    // rep(i,1,n-1) printf("%.8lf ",vk[i]);puts("");
    rep(i,2,n-1) sum=normal(sum+(vv[i-1]=normal((vk[i]-vk[i-1])*calc(2))));
    // rep(i,1,n-2) printf("%.8lf ",vv[i]);puts("");
    if (normal(sum+vk[1])==0 && check()) puts("Yes");
    else puts("No");
}


int main()
{
    solve();
    return 0;
}


/*

2
-1 2
1 0
2 1

3
-3 -1
-1 -1
1 1 
4 1

3
-3 1
-2 0
0 1
1 1


*/