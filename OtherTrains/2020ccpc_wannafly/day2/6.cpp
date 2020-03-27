#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000005
using namespace std;
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
    char buffer[SIZE];
    char *s = buffer;
    void flush() {//????flush!!
        fwrite(buffer, 1, s - buffer, stdout);
        s = buffer;
        fflush(stdout);
    }
    inline void print(const char ch) {
        if(s - buffer > SIZE - 2) flush();
        *s++ = ch;
    }
    inline void print(char *str) {//for string
        while(*str != 0) 
            print(char(*str ++));
    }
    inline void print(long long x) {
        static char buf[25];
        static char *p = buf;
        if (x <  0) print('-'), x = -x;
        if (x == 0) print('0');
        while(x) *(++ p) = x % 10, x /= 10;
        while(p != buf) print(char(*(p --) ^ 48));
    }
};
int lg2[N];
int lb(int x){return x & (-x);}

int n;
struct ro{
	int to,next;
	long long l;
}road[N*2];
int zz,a[N];
void build(int x,int y,int z)
{
	zz++;
	road[zz].to=y;
	road[zz].next=a[x];
	road[zz].l=z;
	a[x]=zz;
}
int zz1;
int Fa[N][21],sum;
long long fr[N];
int deep[N],l[N],r[N],f[N],dfn[N];
inline void dfs1(int x)
{
	zz1++;
	dfn[x]=zz1;
	l[x]=zz1;
	for(int i=a[x];i;i=road[i].next)
	{
		int y=road[i].to;
		if(y==Fa[x][0])continue;
		deep[y]=deep[x]+1;
		Fa[y][0]=x;
		fr[y]=road[i].l;
		dfs1(y);
	}
	r[x]=zz1;
}
int size[N],root;
bool fw[N];
inline void find_root(int x,int fa)
{
	size[x]=1;
	f[x]=0;
	for(int i=a[x];i;i=road[i].next)
	{
		int y=road[i].to;
		if(y==fa||fw[y]) continue;
		find_root(y,x);
		size[x]+=size[y];
		if(size[y]>f[x]) f[x]=size[y];
	}
	if(sum-f[x]>f[x]) f[x]=sum-f[x];
	if(f[x]<f[root]) root=x;
}
int bel[N];
long long val[N],cnt[N],Fr[N];
inline void work(int x,int be,int F)
{
	fw[x]=1;bel[x]=be;
	cnt[x]=val[x]=0;
	Fr[x]=F;
	for(int i=a[x];i;i=road[i].next)
	{
		int y=road[i].to;
		if(fw[y])continue;
		sum=size[y];root=0;
		find_root(y,x);
		work(root,x,road[i].l);
	}
}
void work1(int x,int fr,int st,int da)
{
	
/*	cnt[x]+=da;
	if(x!=st) val[x]+=1ll*da*Fr[fr];
	if(bel[x]) work1(bel[x],x,st,da);*/
	int la=x;
	cnt[x]+=da;
	x=bel[x];
	for(;x;x=bel[x])
	{
		val[x]+=1ll*da*Fr[la];
		cnt[x]+=da;
		la=x;
	}
}
long long ans;
int find(int x,int y)
{
	if(l[x]<=dfn[y]&&r[x]>=dfn[y])
	{	
		int d = deep[y] - deep[x] - 1;
		while (d) y = Fa[y][lg2[lb(d)]], d-=lb(d);
		return fr[y];
	}
	else return fr[x];
}
inline void work2(int x,int frr,int st)
{
	ans+=val[x];
	int la=x;
	x=bel[x];
	for(;x;x=bel[x])
	{
		ans+=1ll*find(st,x)*(cnt[x]-cnt[la]);
		la=x;
	}
}
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	scanf("%d",&n);
	for(int i=1,j=0;i<N;i<<=1, j ++)
	lg2[i] = j;
	IO::in(n);
	for( int i=1;i<n;i++)
	{
		int x,y,z;
	//	scanf("%d%d%d",&x,&y,&z);
		IO::in(x);
		IO::in(y);
		IO::in(z);
		build(x,y,z);
		build(y,x,z);
	}
	deep[1]=1;
	dfs1(1);
	f[0]=0x7fffffff;
	sum=n;
	for(int i=1;i<=20;i++)
	{
		for( int j=1;j<=n;j++)
		{
			Fa[j][i]=Fa[Fa[j][i-1]][i-1];
		}
	}
	find_root(1,0);
	work(root,0,0);
	int Q,now=1;
	//scanf("%d",&Q)
	IO::in(Q);;
	for( int i=1;i<=Q;i++)
	{
		int op;
		IO::in(op);
		//scanf("%d",&op);
		if(op==1)
		{
			int x,y;
			//scanf("%d%d",&x,&y);
			IO::in(x);
			IO::in(y);
			work1(x,0,x,y);
		}
		else
		{
			int x;
//			scanf("%d",&x);
			IO::in(x);
			now=x;
		}
		ans=0;
		work2(now,0,now);
		IO::print(ans);
		IO::print("\n");
	//	printf("%lld\n",ans);
	}
	IO::flush();
	return 0;
}