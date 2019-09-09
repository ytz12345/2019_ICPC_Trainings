#include <bits/stdc++.h>

using namespace std;

const int N=100010;

typedef long long ll;

int T, n, m, q;

char s[2010],t[2010];

int b[N];

struct node{
	char s[2010];
	int id;
}a[N];

int maxk,cnt;

map<int, int>p;

int dfs(int id, int md) {
	//printf("%d\n",id);
	if (id==n) {
		if (md!=0)return 0;
		cnt++;
		if (p.find(cnt)!=p.end()){
			int pos;pos=p[cnt];
			for(int i=0;i<n;i++)
				a[pos].s[i]=t[i];
			if (cnt == maxk) return 1;
		}
		return 0;
	}
	if (s[id]!='?') {t[id]=s[id];
		if(dfs(id + 1, (md+(s[id]-'0')*b[id+1])%m)) return 1;}
	else {
		for (int i='0';i<='9';i++){
			t[id]=i;
			if(dfs(id + 1, (md+(t[id]-'0')*b[id+1])%m)) return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	const int Mod = 1e9 + 7;
	while(T--) {
		cin>>n>>m>>q>>s;maxk=0;cnt=0;
		b[n] = 1;p.clear();
		for (int i = n - 1; i >= 1; i --)
			b[i] = (b[i + 1] * 10) % m; 
		for (int i=0;i<q;i++){
			cin>>a[i].id,p[a[i].id]=i,maxk=max(maxk,a[i].id);
			a[i].s[0]=0;
		}
		dfs(0, 0);
		for(int i=0;i<q;i++){
			if(a[i].s[0]==0)puts("-1");
			else {
				a[i].s[n]=0;
				//puts(a[i].s);
				ll ans = 0;
				for (int j = 0; j < n; j ++)
					ans = (ans * 10 + (a[i].s[j] - '0')) % Mod;
				printf("%lld\n", ans);
			}
		}
		//sort (a, a +q,[&](node x, node y){return x.id <y.id});
	}
}