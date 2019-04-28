#include <bits/stdc++.h>

using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define rep0(i,r) for(int i=0;i<r;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
typedef long long ll;

inline int get_char() {
	static const int SIZE = 1 << 20;
	static char *S, *T = S, buf[SIZE];
	if (S == T) {
		T = fread(buf, 1, SIZE, stdin) + (S = buf);
		if (S == T) return -1;
	}
	return *S ++;
}

inline void in(int &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

inline void in(ll &x) {
	static int ch;
	while (ch = get_char(), ch < 48);x = ch - 48;
	while (ch = get_char(), ch > 47) x = x * 10 + ch - 48;
}

const int N=1e5+5;
int fa[N],n,q;
ll psz[N<<2],esz[N<<2],sz[N<<2],cnt[N];

int fx(int x)
{
    return fa[x]=x==fa[x]?x:fx(fa[x]);
}

ll calc(ll x)
{
    return x*(x-1ll)/2;
}

void updata(int x)
{
    sz[x]=sz[x<<1]+sz[x<<1|1];
    psz[x]=psz[x<<1]+psz[x<<1|1];
    esz[x]=esz[x<<1]+esz[x<<1|1];
}
void rebuild(int x,int l,int r)
{
    if (x)
   // printf("%d %d %d\n",x,l,r);
   // getchar();
    if (l==r) {
        if (l==1) {
            sz[x]=n;
            psz[x]=n;
            esz[x]=0;
        }
        else sz[x]=psz[x]=esz[x]=0;
        return;
    }
    int mid=(l+r)>>1;
    rebuild(x<<1,l,mid);
    rebuild(x<<1|1,mid+1,r);
    updata(x);
}

void del(int x,int l,int r,int y)
{
    if (l==r) {
        sz[x]--;
        psz[x]-=l;
        esz[x]-=l*(l-1ll)/2;
        return;
    }
    int mid=(l+r)>>1;
    if (y<=mid) del(x<<1,l,mid,y);
    else del(x<<1|1,mid+1,r,y);
    updata(x);
}

void add(int x,int l,int r,int y)
{
    if (l==r) {
        sz[x]++;
        psz[x]+=l;
        esz[x]+=l*(l-1ll)/2;
        return;
    }
    int mid=(l+r)>>1;
    if (y<=mid) add(x<<1,l,mid,y);
    else add(x<<1|1,mid+1,r,y);
    updata(x);
}

int fmax(ll k)
{
    int nowu=1,l=1,r=n,mid;
    ll nowsz=0,nowpsz=0,nowesz=0;
    while (l<r) {
        mid=(l+r)>>1;
        if (calc(nowpsz+psz[nowu<<1|1])-nowesz-esz[nowu<<1|1]>=k) {
            nowu=nowu<<1|1;
            l=mid+1;
            continue;
        }
        nowsz+=sz[nowu<<1|1];
        nowpsz+=psz[nowu<<1|1];
        nowesz+=esz[nowu<<1|1];
        nowu=nowu<<1;
        r=mid;
    }
//    printf("(%d,%d,%lld %lld %lld %d) ",l,r,nowsz,nowpsz,nowesz,sz[nowu]);
    ll mpsz=l,mesz=l*(l-1ll)/2;;
    l=0,r=sz[nowu];
    while (l+1<r) {
        int mid=(l+r)>>1;
        if (calc(nowpsz+mpsz*mid)-nowesz-mesz*mid>=k) r=mid;
        else l=mid;
    }
   // printf("((%d,%d))",l,r);
    return nowsz+r;
}

void solve()
{
    in(n),in(q);
    rep(i,1,n) fa[i]=i,cnt[i]=1;
    rebuild(1,1,n);
  //  printf("!!\n");
    int op,j,k;
    ll sum=0,kk;
    rep(i,1,q) {
        in(op);
        if (op==1) {
            in(j),in(k);
            j=fx(j),k=fx(k);
            if (j==k) sum--;
            else {
                del(1,1,n,cnt[j]);
                del(1,1,n,cnt[k]);
                sum+=cnt[j]*cnt[k]-1LL;
                cnt[j]+=cnt[k];
                fa[k]=j;
                add(1,1,n,cnt[j]);
            }
        }
        else {
            in(kk);
            printf("%lld ",max(1ll,sz[1]-kk));
            kk-=sum;
            if (kk<=0) printf("%lld\n",sz[1]);
            else
                printf("%lld\n",sz[1]-fmax(kk)+1);
        }
    }
}


int main() {
  //  freopen("a.in","r",stdin);
    int tt;
    in(tt);
    while (tt--) {
        solve();
    }
	return 0;
}