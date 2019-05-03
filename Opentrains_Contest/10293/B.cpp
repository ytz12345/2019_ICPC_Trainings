#include<cstdio>
const int N=400010;
int n,m,mx,lim,i,j,x,a[N],f[N][2];unsigned long long v[64][N/64+5];
inline void solve(int d){
  int i,j,A=d>>6,B=d&63;
  for(i=0;i+A<=lim;i++)if(v[0][i]&v[B][i+A])for(j=i<<6;;j++)if(a[j]&&a[j+d]){
    f[d][0]=a[j];
    f[d][1]=a[j+d];
    return;
  }
}
int main(){
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++){
    scanf("%d",&x);
    a[x]=i;
    if(x>mx)mx=x;
  }
  lim=mx/64;
  for(i=0;i<=mx;i++)if(a[i])for(j=0;j<64&&j<=i;j++)v[j][(i-j)>>6]|=1ULL<<((i-j)&63);
  for(f[0][1]=i=1;i<=mx;i++){
    f[i][0]=f[i-1][0];
    f[i][1]=f[i-1][1];
    solve(i);
  }
  while(m--){
    scanf("%d",&x);
    if(x>mx)x=mx;
    printf("%d %d\n",f[x][0],f[x][1]);
  }
}
