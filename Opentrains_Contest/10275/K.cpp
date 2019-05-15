#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef pair<long, int> P;
typedef long long ll;
const ll inf = 2e18;
int s=20, cnt;
ll fac[1001];
vector<ll> ok;
long long ksc(long long x,long long y,long long mod)
{
    long long res=0;
    while(y)
    {
        if(y&1)
        res=(res+x)%mod;
        x=(x<<1)%mod;
        y>>=1;
    }
    return res;
}
long long ksm(long long x,long long y,long long mod)
{
    long long res=1;
    while(y)
    {
        if(y&1)
        res=ksc(res,x,mod);
        x=ksc(x,x,mod);
        y>>=1;
    }
    return res;
}
int miller_rabin(long long n)
{
    if(n==2)
    return 1;
    if(n<2||!(n%2))
    return 0;
    long long u,pre,x;
    int k=0;
    u=n-1;
    while(!(u&1))
    {
        ++k;
        u>>=1;
    }
    for(int i=1;i<=s;++i)
    {
        x=rand()%(n-2)+2;
        x=ksm(x,u,n);
        pre=x;
        for(int j=1;j<=k;++j)
        {
            x=ksc(x,x,n);
            if(x==1&&pre!=1&&pre!=n-1)
            return 0;
            pre=x;
        }
        if(x!=1)
        return 0;
    }
    return 1;
}
long long gcd(long long a,long long b)//×¢ÒâÓëÒ»°ãµÄgcd²»Ò»Ñù£¡£¡£¡ 
{
    if (a==0) return 1;//pollard_rhoµÄÐèÒª 
    if (a<0) return gcd(-a,b);//¿ÉÄÜÓÐ¸ºÊý 
    while (b){
        long long t=a%b; a=b; b=t;
    }
    return a;
}
long long pollard_rho(long long n,long long c)
{
    long long i=1,k=2;
    long long xx=rand()%n,y=xx;
    while(1)
    {
        i++;
        xx=(ksc(xx,xx,n)+c)%n;
        long long d=gcd(y-xx,n);
        if(1<d&&d<n)
        return d;
        if(y==xx)
        return n;
        if(i==k)
        {
            y=xx;
            k<<=1;
        } 
    } 
}
void find(long long n)//Í¨¹ýÕÒÒòÊýÀ´ÕÒÖÊÒò×Ó 
{
    if(miller_rabin(n))
    {
        fac[++cnt]=n;//¼ÇÂ¼ÖÊÒò×Ó 
        return;
    }
    long long p=n;
    while(p>=n)
    p=pollard_rho(p,rand()%(n-1)+1);
    find(p);
    find(n/p);
}
ll a, n;
ll calc(vector<int> &count) {
    ll ret = 1ll;
    rep(i, 1, cnt) {
        rep(j, 1, count[i]) {
            if (ret > (long double)inf / fac[i]) return inf;
            ret = ret * fac[i];
        }
    }
    if (ret > n) return inf;
    return ret;
}
int main() {
    srand(time(NULL));
    cin >> a >> n;
    if (a == 1) {
        puts("-1");
        return 0;
    }
    cnt = 0;
    find(a);
    sort(fac + 1, fac + 1 + cnt);
    cnt = unique(fac + 1, fac + 1 + cnt) - fac - 1;
    vector<P> v(cnt + 1);
    rep(i, 1, cnt) {
        int c = 0;
        while (a % fac[i] == 0) {
            a /= fac[i];
            c ++;
        }
        v[i] = P(fac[i], c);
    }
    // rep(i, 1, cnt) cout << v[i].first << ' ' << v[i].second << endl;
    ll ans = inf, m = 1ll;
    vector<int> count(cnt + 1, 1);
    rep(i, 1, cnt) {
        count[i] = v[i].second + 1;
        // rep(j, 1, cnt) cout << count[j] << ' '; cout << endl;
        ll tmp = calc(count);
        if (tmp <= n) ok.push_back(tmp);
        count[i] = v[i].second;
    }
    if (ok.size() == 0) puts("-1");
    else printf("%lld\n", ok[ok.size() - 1]);
    //if (ans >= inf) ans = -1;
    //cout << ans << '\n';
}