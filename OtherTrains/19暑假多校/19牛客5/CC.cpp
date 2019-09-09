#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t1 = 2e3+7, t2 = 5e5+7;
unordered_map<int, int> mp;
long long n;
int x, a, b, p, q;
int pw(int w, int t)
{
    int r = 1;
    while(t)
    {
        if(t % 2)
            r = (ll)r * w % p;
        w = (ll)w * w % p;
        t /= 2;
    }
    return r;
}
void query()
{
    int v;
    scanf("%d", &v);
    if(a == 0)
    {
        printf("%d\n", v==x&&n>0 ? 0:(v==b&&n>1 ? 1:-1));
        return;
    }
    if(a == 1)
    {
        v = (ll)(v - x + p) * pw(b, p-2) % p;
        printf("%d\n", v < n ? v : -1);
        return;
    }
    int y = (ll)b * pw(a-1, p-2) % p;
    v = (ll)(v + y) * pw(y+x, p-2) % p;
    int r = p;
    for(int i = 1; i <= t1; i++)
    {
        v = (ll)v * a % p;
        if(mp.count(v))
            r = min(r, mp[v]-i);
    }
    printf("%d\n", r<p && r<n ? r : -1);
}
void get_res()
{
     
    scanf("%lld%d%d%d%d%d", &n, &x, &a, &b, &p, &q);
    int s = pw(a, t1), k = 1;
    mp.clear();
    for(int i = 1; i <= t2; i++)
    {
        k = (ll)k * s % p;
        if(!mp.count(k))
            mp[k] = i * t1;
    }
    while(q-- > 0)
        query();
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t-- > 0)
        get_res();
    return 0;
 }