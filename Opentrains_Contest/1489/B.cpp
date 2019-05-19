#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
const int N=610000,M=200010;
int father[N],n,m,x[N],y[N],size[N],w[N];
int findfather(int k1){
        while (father[k1]!=k1) k1=father[k1]; return k1;
}
int s[N*2],ans[N];
int head,rem;
void link(int k1,int k2){
        k1=findfather(k1); k2=findfather(k2);
        if (size[k1]>size[k2]) swap(k1,k2);
        if (k1!=k2){
                s[++head]=k1; father[k1]=k2; size[k2]+=size[k1]; w[k2]+=w[k1];
                if ((w[k1]&1)&&(w[k2]&1)==0) rem-=2;
        }
}
void insert(int k){
        link(k+M+M,x[k]);
        link(k+M+M,y[k]+M);
}
void getback(int k){
        while (head>k){
                size[father[s[head]]]-=size[s[head]];
                w[father[s[head]]]-=w[s[head]];
                father[s[head]]=s[head];
                head--;
        }
}
void solve(int l,int r){
        if (l==r){
                ans[l]=rem; return;
        }
        int prerem=rem; int pre=head;
        int mid=l+r>>1;
        for (int i=l;i<=mid;i++) insert(i);
        solve(mid+1,r); rem=prerem; getback(pre);
        for (int i=mid+1;i<=r;i++) insert(i);
        solve(l,mid); rem=prerem; getback(pre);
}
int main(){
        scanf("%d",&n);
        //n=100000;
        for (int i=1;i<=n*2+1;i++){
                scanf("%d%d",&x[i],&y[i]);
        //        x[i]=rand()%n+1;
                //y[i]=rand()%n+1;
        }
        m=n*2+1+M+M; //cerr<<"tot "<<m<<endl;
        for (int i=1;i<=m;i++) father[i]=i,size[i]=1;
        for (int i=1;i<=n*2+1;i++) w[i+M+M]=1;
        rem=n*2;
        solve(1,n*2+1);
        for (int i=1;i<=n*2+1;i++) if (ans[i]) printf("NG\n"); else printf("OK\n");
}
