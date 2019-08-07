#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

const ll inf = 1e18 + 5;
const ll Mod = 1e9 + 7;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)

int n,q;
ll m;
ll a[N],a2[N],f[N][22];
char s[N];

ll dec(ll x,ll y)
{
	return ((x-y)%m+m)%m;
}

void solve()
{
	scanf("%d %lld %d",&n,&m,&q);
	scanf("%s",s+1);
	//pow1 = %m
	//pow2 = %Mod
	ll pres=0,pow1=1,pow2=1,prem=0;
	int tot=0;
	dow(i,1,n) {
		if (i==n) pow1=1ll,pow2=1ll;
		else 
			pow1=pow1*10ll%m,pow2=pow2*10ll%Mod;
		if (s[i]=='?') 
			a[++tot]=pow1,a2[tot]=pow2;
		else {
			int t=s[i]-'0';
			pres=(pres+pow2*t)%Mod;
			prem=(prem+pow1*t)%m;
		}
	}
	int mm=tot;
	prem=dec(m,prem);
	f[0][0]=1;
	rep(i,1,tot) {
		rep(j,0,m-1) f[i][j]=0;
		rep(j,0,m-1) {
			rep(k,0,9) {
				ll t=dec(j,k*a[i]%m);
				f[i][j]+=f[i-1][t];
				if (f[i][j]>inf) f[i][j]=inf;
			}
		}
		if (f[i][prem]>=inf) {
			mm=i;
			break;
		}
	}
	//rep(i,1,mm)
	//	rep(j,0,9) printf("%d %lld\n",j,f[i][j]);
	ll kk,ans,now;
	//printf("%lld\n",pres);
	while (q--) {
		ans=pres;
		now=prem;
		scanf("%lld",&kk);
		if (tot==0) {
			if (kk==1 && prem==0) printf("%lld\n",pres);
			else printf("-1\n");
			continue;
		}
		if (f[mm][prem]<kk) {
			printf("-1\n");
			continue;
		}
		dow(i,1,mm) {
			rep(j,0,9) {
				ll t=dec(now,j*a[i]%m);
				if (kk>f[i-1][t]) {
					kk-=f[i-1][t];
				}
				else {
					ans += a2[i]*j%Mod;
					ans%=Mod;
					now=t;
		//			printf("%d ",j);
					break;
				}
			}
		}
		if (now==0) printf("%lld\n",ans);
		else printf("-1\n");
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		solve();
	}
	return 0;
}