#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 300005
using namespace std;
int n,m;
struct ro{
	int to,next;
}road[N*2];
int zz,a[N];
void build(int x,int y)
{
	zz++;
	road[zz].to=y;
	road[zz].next=a[x];
	a[x]=zz;
}
int Fa[N][20],deep[N];
long long A[N],B[N],C[N],D[N];
void dfs2(int x)
{
	for(int i=a[x];i;i=road[i].next)
	{
		int y=road[i].to;
		if(y==Fa[x][0])continue;
		dfs2(y);
		A[x]+=A[y]+B[y]+C[y];
		B[x]+=B[y]+C[y];
		C[x]+=C[y];
	}
}
long long ans[N];
void dfs3(int x)
{
	for(int i=a[x];i;i=road[i].next)
	{
		int y=road[i].to;
		if(y==Fa[x][0])continue;
		A[y]+=A[x]-(A[y]+B[y]+C[y]);
		dfs3(y);
	}
}
int main()
{
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)  continue;
		long long l,r,lca;
		lca=get_lca(x,y);
		l=deep[x]-deep[lca];
		r=deep[y]-deep[lca];
		B[x]+=r+l+1;C[x]+=-2;
		B[y]+=r+l+1;C[y]+=-2;
		A[lca]-=l*r;B[lca]-=-l+r+1;B[lca]-=l-r+1;C[lca]+=4;
	}
	dfs2(1);
	dfs3(1);
	
	for(int i=1;i<=n;i++) printf("%lld\n",A[i]);
	return 0;
}