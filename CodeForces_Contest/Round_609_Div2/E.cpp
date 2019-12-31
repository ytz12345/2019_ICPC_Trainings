#include <bits/stdc++.h>
 
const int XN=3e5+11,P=998244353;
 
void Mod(int &x) {
    ((x>=P) && (x-=P)) || ((x<0) && (x+=P));
}
 
int f[XN],sum[XN];
 
int Get(int L,int R) {
    int x=sum[R-1]-(L==1?0:sum[L-2]);
    return x<0?x+P:x;
}
 
int ctrb[XN<<2],cov[XN<<2];
void Add(int pos,int L,int R,int l,int r,int v) {
    if(l<=L && R<=r) {
        cov[pos]+=v;
    } else {
        int M=(L+R)/2;
        if(l<=M)
            Add(pos<<1,L,M,l,r,v);
        if(M+1<=r)
            Add(pos<<1|1,M+1,R,l,r,v);
    }
    if(cov[pos])
        ctrb[pos]=Get(L,R);
    else
        Mod(ctrb[pos]=ctrb[pos<<1]+ctrb[pos<<1|1]);
}
 
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    int n;std::cin>>n;
    static int last[XN],a[XN],pre[XN];
    sum[0]=f[0]=1;
    for(int i=1;i<=n;++i) {
        std::cin>>a[i];
        if(last[a[i]])
            Add(1,1,n,pre[last[a[i]]]+1,last[a[i]],-1);
        Add(1,1,n,last[a[i]]+1,i,1);
        pre[i]=last[a[i]];
        last[a[i]]=i;
        f[i]=ctrb[1];
        Mod(sum[i]=sum[i-1]+f[i]);
    }
    std::cout<<f[n]<<'\n';
	return 0;
}