#include <bits/stdc++.h>

using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
#define pb push_back
const int N = 1e3 + 5;


int col[N],id[N],fa[N],dep[N],n,m,kk;
vector<int> v[N],ans;
int flag;

void dfs(int x)
{
	int scol=1;
	//printf("\tCase %d,%d ",x,fa[x]);
	for(auto nxt:v[x]) {
		if (!col[nxt]) continue;
	//	printf("%d ",nxt);
	//	if (dep[ffa]>dep[nxt]) ffa=nxt;
		if (id[col[nxt]]!=x) {
			id[col[nxt]]=x;
	//		if (dep[ffa]>dep[nxt]) ffa=nxt;
			while (id[scol]==x&&scol<=kk) scol++;
		} 
	}
//	printf("=%d\n",scol);
	if (scol>=kk+1) {
		flag=x;
		return;
	}
	else {
		col[x]=scol;
		for(auto nxt:v[x]) {
			if (col[nxt]) continue;
			fa[nxt]=x;
			dfs(nxt);
			if (flag) return;
		}

	}
}

void solve()
{
	scanf("%d %d",&n,&m);
	scanf("%d",&kk);
	flag=0;
	rep(i,1,n) v[i].clear(),col[i]=0;
	rep(i,1,kk) id[i]=0;
	rep(i,1,m) {
		int j,k;
		scanf("%d %d",&j,&k);
		v[j].pb(k);
		v[k].pb(j);
	}
	ans.clear();
	for(int i=1;i<=n;i++)
		if (!col[i]) {
			//dep[i]=1;
			dfs(i);
			if (flag) {
				printf("path");
				for(int now=flag,j=1;j<=kk+1;now=fa[now],j++) printf(" %d",now);
				break;
			}
		}
	if (flag==0) {
		printf("coloring");
		rep(i,1,n) printf(" %d",col[i]);
	}
	puts("");
}

int main() {
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}
	return 0;
}