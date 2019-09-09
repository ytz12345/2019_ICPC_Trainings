#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define rep0(i,r) for(int i=0,rr=r;i<rr;i++)
#define pb push_back

const int N=300100;
const LL MMM=100003;
const LL Mod[2]={998244353,1004535809};
LL diva[3]={0,998244353,1004535809};
LL inv2[2]={998244353/2+1,1004535809/2+1};
LL g[2][21],ng[2][21],len[N],ka,s[N];
int n,q;
vector<LL> v[N*4];

namespace IO {//only for int!!!
    static const int SIZE = 1 << 20;
    inline int get_char() {
        static char *S, *T = S, buf[SIZE];
        if (S == T) {
            T = fread(buf, 1, SIZE, stdin) + (S = buf);
            if (S == T) return -1;
        }
        return *S ++;
    }
    inline void in(int &x) {//for int
        static int ch;
        while (ch = get_char(), ch < 48);x = ch ^ 48;
        while (ch = get_char(), ch > 47) x = x * 10 + (ch ^ 48);
    }
};


LL gcd(LL a,LL b)
{
    if (!b) return a;
    return gcd(b,a%b);
}
LL qpow(LL a,LL b, LL M)
{
    a%=M;
    LL sum=1;
    while (b) {
        if (b&1) sum=sum*a%M;
        a=a*a%M;
        b>>=1;
    }
    return sum;
}

LL mul(LL x, LL y, LL p) {
    x %= p; y %= p;
    LL ret = x * y - (LL)((long double)x * y / p + 0.5) * p;
    return ret < 0 ? ret + p : ret;
}

LL inv(LL x,LL y)
{
    return qpow(x,y-2,y);
}
LL M, invv[3];
void init_M() {
    M = diva[1] * diva[2];
    invv[1] = inv(M / diva[1], diva[1]);
    invv[2] = inv(M / diva[2], diva[2]);
}
LL CRT(LL *a, LL *m, int n) {
    LL ret = 0;
   // printf("%lld\n",M);
    rep(i, 1, n) {
        LL w = M / m[i];
        ret = (ret + mul(mul(a[i], w, M) , invv[i], M)) % M;
    }
 //   printf("%lld\n",ret);
    return ret;
}

void init()
{
    rep(i, 1, 20) {
        g[0][i] = qpow(3, (Mod[0] - 1) / (1 << i), Mod[0]),
        ng[0][i] = qpow(g[0][i], Mod[0] - 2, Mod[0]);
        g[1][i] = qpow(3, (Mod[1] - 1) / (1 << i), Mod[1]),
        ng[1][i] = qpow(g[1][i], Mod[1] - 2, Mod[1]);
    }
}

void NTT(int op,LL *a, int n, int t) {
    int k = 0;
    while ((1 << k) < n) k ++;
    rep(i, 0, n - 1) {
        int t = 0;
        rep(j, 0, k - 1) if ((i >> j) & 1) t |= (1 << (k - 1 - j));
        if (i < t) swap(a[i], a[t]);
    }
    for (int c = 1, l = 2; l <= n; l <<= 1, ++ c) {
        int m = l >> 1; LL _w = t == 1? g[op][c]: ng[op][c];
        for (int i = 0; i < n; i += l) {
            LL w = 1LL;
            for (int j = 0; j < m; ++ j) {
                LL x = a[i + j + m] * w % Mod[op];
                (a[i + j + m] = a[i + j] + Mod[op] - x) %= Mod[op];
                (a[i + j] += x) %= Mod[op];
                (w *= _w) %= Mod[op];
            }
        }
    }
    if (t == -1) {
        LL invn = qpow(n, Mod[op] - 2, Mod[op]);
        rep(i, 0, n - 1) (a[i] *= invn) %= Mod[op];
    }
}

int getpow2(int x)
{
    int now=1;
    while (x>=now) now*=2;
    return now;
}
LL a[2][N*2],b[2][N*4],c[2][N*2],moda[3],cc[N*2];

void build(int x,int l,int r)
{
   // printf("%d %d %d\n",x,l,r);
    if (l==r) {
        len[x]=1;
        v[x].pb(1);
        v[x].pb(qpow(ka,s[l],MMM));
        return;
    }
    int mid=(l+r)>>1,lson=(x<<1),rson=(x<<1|1);
    build(lson,l,mid);
    build(rson,mid+1,r);
  //  printf("2-%d %d %d %d %d\n",x,l,r,len[lson],len[rson]);
    int nowl=getpow2((max(len[lson],len[rson])+1)*2);
    rep(op,0,1) {
        rep0(i,v[lson].size()) a[op][i]=v[lson][i];
        rep(i,v[lson].size(),nowl-1) a[op][i]=0;
        rep0(i,v[rson].size()) b[op][i]=v[rson][i];
        rep(i,v[rson].size(),nowl-1) b[op][i]=0;
    }
    rep(i,0,1) {
        NTT(i,a[i],nowl,1),NTT(i,b[i],nowl,1);
        rep0(j,nowl) c[i][j]=a[i][j]*b[i][j];
        NTT(i,c[i],nowl,-1);
    }
  //  printf("3-%d %d %d %d\n",nowl,x,l,r);
    rep0(i,nowl) {
     //   printf("!!%lld",cc[0]);
        moda[1]=c[0][i];
        moda[2]=c[1][i];
      //  printf("!!%lld",cc[0]);
        cc[i]=CRT(moda,diva,2)%MMM;
      //  printf("%lld %lld %lld\n",cc[0],c[0][i],c[1][i]);
    }
   // rep0(i,nowl) printf("%lld\n",cc[i]);
    dow(i,0,nowl-1)
        if (cc[i]) {
            len[x]=i;
   //         printf("%d %lld\n",len[x],i);
            break;
        }
    rep(i,0,len[x]) {
        v[x].pb(cc[i]);
  //      printf("%d\n",cc[i]);
    }
 //   printf("4-%d %d %d %d: ",x,l,r,len[x]);
 //   rep0(i,len[x]) printf("%d ",v[x][i]);puts("");
}

LL fc[N], inva, fcn, Fc[N];

using IO::in;

void solve()
{
    in(n), in(ka), in(q);
    //scanf("%d %lld %d",&n,&ka,&q);
    fc[0] = 1;
    for (int i = 1; i <= n; i ++) fc[i] = fc[i - 1] * i % MMM; fcn = fc[n];
    for (int i = 1; i <= n; i ++) fc[i] = qpow(fc[i], MMM - 2, MMM);
    for (int i = 0; i <= n; i ++) Fc[i] = fcn * fc[i] % MMM * fc[n - i] % MMM;
    inva = qpow(ka - 1, MMM - 2, MMM);
    rep(i,1,n) in(s[i]);//scanf("%lld",&s[i]);
    build(1,1,n);
    int j;LL ans;
    while (q--) {
        in(j);
        //scanf("%d",&j);
        if (v[1].size()<=j) puts("0\n");
        else {
        //    printf("%lld\n",v[1][j]);
            ans=((v[1][j]-Fc[j])%MMM*inva%MMM+MMM)%MMM;
            printf("%lld\n",ans);
        }
    }
}

int main() {
  //  freopen("1.in","r",stdin);
    init();
    init_M();
    solve();
    return 0;
}