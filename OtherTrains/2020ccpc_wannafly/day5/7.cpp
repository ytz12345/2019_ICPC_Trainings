#include<stdio.h>

long long p,i,n,T,cnt,q;
struct node{
   long long l,r;
}ans[1000000];
long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0){x = 1;y = 0;return a;}
    long long ans = ex_gcd(b,a%b,x,y);
    long long temp = x;
    x = y;
    y = temp - a/b*y;
    return ans;
}
long long inv(long long a,long long b)
{
   long long x,y;
   long long ans = ex_gcd(a,b,x,y);
   if(ans!=1)return -1;
   if(x<0)x = (x%b + b)%b;
   return x;
}
int main()
{
   scanf("%lld",&T);
   while(T--)
   {
     scanf("%lld",&p);
     if(p==2){
     	printf("0\n");
     	continue;
	 }
     if(p==3){
     	printf("1\n");
     	printf("2 2\n");
     	continue;
	 }
     cnt=0;
     n=inv(2,p);
     ans[++cnt].r=n;
     ans[cnt].l=2;
     for(i=3;i<n;i++)
     {
      q=inv(i,p);
      if(q<n){
        n=q;
        ans[++cnt].r=n;
        ans[cnt].l=i;
	  }
	 }  
	 printf("%lld\n",2*cnt);
    for(i=1;i<=cnt;i++)
    {
      printf("%lld %lld\n",ans[i].l,ans[i].r);
	}
	for(i=cnt;i>=1;i--)
	{
	  printf("%lld %lld\n",ans[i].r,ans[i].l);
	}
   }
 
   return 0;
}
