#include <bits/stdc++.h>

using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define mp make_pair
#define fir first
#define sec second
const int N = 2e5 + 5;
const int M = 10000;

int t, n;

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
    void flush() {//最后需要flush!!
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
    inline void print(int x) {
        static char buf[25];
        static char *p = buf;
        if (x <  0) print('-'), x = -x;
        if (x == 0) print('0');
        while(x) *(++ p) = x % 10, x /= 10;
        while(p != buf) print(char(*(p --) ^ 48));
    }
};

using IO::in;
using IO::print;

typedef pair<int,int> piir;
piir c[N],n1,n2;

int a[N][2];
int h1[N],h2[N],t1[N],sz[N],ans[N],p[N*2],nx[N*2],total,vis[N];

using IO::in;
//using IO::print;


void build(int x,int l,int r)
{
	sz[x]=0;
    if (l==r) {
        h1[x]=-1;
        t1[x]=-1;
        h2[x]=-1;
        sz[x]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}

piir get1(int x,int l,int r,int kk)
{
    //printf("%d %d %d %d\n",x,sz[x],l,r);
    if (l==r) {
        if (h2[x]!=-1) return mp(p[h2[x]],1);
        return mp(p[h1[x]],0);
    }
    int mid=(l+r)>>1;
    if (sz[x<<1|1]>=kk)
        return get1(x<<1|1,mid+1,r,kk);
    return get1(x<<1,l,mid,kk-sz[x<<1|1]);
}

piir get2(int x,int l,int r,int kk)
{
    if (l==r) {
        if (kk==1) {
            if (h2[x]!=-1) return mp(p[h2[x]],1);
            return mp(p[h1[x]],0);
        }
        if (h2[x]!=-1) {
            if (nx[h2[x]]!=-1) return mp(p[nx[h2[x]]],1);
            return mp(p[h1[x]],0);
        }
        return mp(p[nx[h1[x]]],0);
    }
    int mid=(l+r)>>1;
    if (sz[x<<1|1]>=kk)
        return get2(x<<1|1,mid+1,r,kk);
    return get2(x<<1,l,mid,kk-sz[x<<1|1]);
}


int newline(int x)
{
    ++total;
    nx[total]=-1;
    p[total]=x;
    return total;
}

void add(int x,int l,int r,int y,int op)
{
    sz[x]++;
    if (l==r) {
        int now=newline(y);
        if (op==0) {
            if (h1[x]==-1)
                t1[x]=h1[x]=now;
            else {
                nx[t1[x]]=now;
                t1[x]=now;
            }
        }
        else {
            nx[now]=h2[x];
            h2[x]=now;
        }
        return;
    }
    int mid=(l+r)>>1;
    if (a[y][op]<=mid)
        add(x<<1,l,mid,y,op);
    else add(x<<1|1,mid+1,r,y,op);
}

void del(int x,int l,int r,int y,int op)
{
    sz[x]--;
    if (l==r) {
        if (op==0) h1[x]=nx[h1[x]];
        else h2[x]=nx[h2[x]];
        return;
    }
    int mid=(l+r)>>1;
    if (a[y][op]<=mid)
        del(x<<1,l,mid,y,op);
    else del(x<<1|1,mid+1,r,y,op);
}

void solve0()
{
    rep(i,1,n) vis[i]=1;
    build(1,1,M);
    total=0;
    int lc=1;
   // printf("%d\n",sz[1]);
    rep(i,1,n) add(1,1,M,c[i].sec,0);
    rep(i,1,n) {
        //printf("!!!\n");
        while (lc<=n && !vis[c[lc].sec]) lc++;
        if (sz[1]<2) {
            ans[i*2]=ans[i*2-2]+c[lc].fir;
            del(1,1,M,c[lc].sec,0);
            continue;
        }
        //printf("!!!\n");
        n1=get1(1,1,M,1),n2=get2(1,1,M,2);
      //  printf("%d %d %d %d\n",n1.fir,n1.sec,n2.fir,n2.sec);
        if (lc<=n && a[n1.fir][n1.sec]+a[n2.fir][n2.sec]<=c[lc].fir) {
      //  	printf("select1 %d\n",lc);
            ans[i*2]=ans[i*2-2]+c[lc].fir;
            del(1,1,M,c[lc].sec,0);
            lc++;
        }
        else {
       //	 	printf("select2\n");
            ans[i*2]=ans[i*2-2]+a[n1.fir][n1.sec]+a[n2.fir][n2.sec];
            del(1,1,M,n1.fir,n1.sec);
            del(1,1,M,n2.fir,n2.sec);
            if (n1.sec==0) {
                add(1,1,M,n1.fir,1);
                vis[n1.fir]=0;
            }
            if (n2.sec==0) {
                add(1,1,M,n2.fir,1);
                vis[n2.fir]=0;
            }
        }
    }
}

void solve1()
{
//	printf("+++++++++++++++++++solve1\n");
    rep(i,1,n) vis[i]=1;
    build(1,1,M);
    total=0;
    int lc=1;
    rep(i,1,n) add(1,1,M,c[i].sec,0);
  //  printf("%d\n",sz[1]);
    n1=get1(1,1,M,1);
    ans[1]=a[n1.fir][0];
    vis[n1.fir]=0;
   // printf("%d %d\n",n1.fir,n1.sec);
    del(1,1,M,n1.fir,0);
    add(1,1,M,n1.fir,1);
    rep(i,1,n-1) {
        while (lc<=n && !vis[c[lc].sec]) lc++;
        if (sz[1]<2) {
            ans[i*2]=ans[i*2-2]+c[lc].fir;
            del(1,1,M,c[lc].sec,0);
            continue;
        }
        n1=get1(1,1,M,1),n2=get2(1,1,M,2);
     //   printf("%d %d %d %d %d %d\n",n1.fir,n1.sec,n2.fir,n2.sec,lc,c[lc].fir);
        if (lc<=n && a[n1.fir][n1.sec]+a[n2.fir][n2.sec]<=c[lc].fir) {
            ans[i*2+1]=ans[i*2-1]+c[lc].fir;
            del(1,1,M,c[lc].sec,0);
            lc++;
        }
        else {
            ans[i*2+1]=ans[i*2-1]+a[n1.fir][n1.sec]+a[n2.fir][n2.sec];
            del(1,1,M,n1.fir,n1.sec);
            del(1,1,M,n2.fir,n2.sec);
            if (n1.sec==0) {
                add(1,1,M,n1.fir,1);
                vis[n1.fir]=0;
            }
            if (n2.sec==0) {
                add(1,1,M,n2.fir,1);
                vis[n2.fir]=0;
            }
        }
    }
}

int main() {
    for (in(t); t --; ) {
        in(n);
      //  printf("!!\n");
        for (int i = 1; i <= n; i ++) {
            in(a[i][0]), in(a[i][1]);
            c[i]=mp(a[i][0]+a[i][1],i);
        }
        sort(c+1,c+1+n,[&](const piir x,const piir y){
                return x.fir>y.fir;
             });
        solve0();
      //  printf("!!");
        solve1();
        rep(i,1,2*n) {
            print(ans[i]);
            if (i==2*n)print('\n');
            else print(' ');
        }
    }
   // IO::flush();
    //printf("%d\n", clock());
    return 0;
}
