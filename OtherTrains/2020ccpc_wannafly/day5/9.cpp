#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 2005
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

int n,m1,m2;
long long B[N],A[N][N];
long long ma[N][N];
int fr[500005],pr[500005];
long long RMQ[N][13];
int Q[500005][5];
long long ans[500005];
int low[N];
int main()
{
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	scanf("%d%d%d",&n,&m1,&m2);
	IO::in(n);
	IO::in(m1);
	IO::in(m2);
	low[1]=0;
	for(int i=2;i<=2000;i++)
	{
		low[i]=low[i>>1]+1;
	}
	for(int i=1;i<=m1;i++)
	{
		int x,y,xx,yy,w;
		IO::in(x);
		IO::in(y);
		IO::in(xx);
		IO::in(yy);
		IO::in(w);
		A[x][y]+=w;
		A[x][yy+1]+=-w;
		A[xx+1][y]+=-w;
		A[xx+1][yy+1]+=w;
	}
	for(register int i=1,j;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			B[j]+=A[i][j];
			ma[i][j]=ma[i][j-1]+B[j];
		}
	}
	for(int i=1;i<=m2;i++)
	{
		//scanf("%d%d%d%d",&Q[i][1],&Q[i][2],&Q[i][3],&Q[i][4]);		
		IO::in(Q[i][1]);
		IO::in(Q[i][2]);
		IO::in(Q[i][3]);
		IO::in(Q[i][4]);
		fr[i]=i+1;
		pr[i]=i-1;
	}
	fr[0]=1;
	fr[m2]=0;
	for(register int i=1,j,k,l;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			RMQ[j][0]=ma[i][j];
		}
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=12;k++)
			{
				RMQ[j][k]=max(RMQ[j][k-1],RMQ[j+(1<<(k-1))][k-1]);
			}
		}
		for(j=fr[0];j;j=fr[j])
		{
			if(Q[j][1]<=i&&Q[j][3]>=i)
			{
				l=Q[j][4]-Q[j][2]+1;
				l=low[l];
				ans[j]=max(ans[j],max(RMQ[Q[j][2]][l],RMQ[Q[j][4]-(1<<l)+1][l]));
			}
			if(i>Q[j][3]) pr[fr[j]]=pr[j],fr[pr[j]]=fr[j];
		}
	}
	for(register int i=1;i<=m2;i++)IO::print(ans[i]),IO::print("\n");
	IO::flush();
	return 0;
}