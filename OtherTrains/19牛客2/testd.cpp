#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<105> bs;
struct pi{
    ll F;
    bs S;
    bool operator < (const pi &u) const{
        return F>u.F;
    }
};
ll w[105];
bs f[105];
char s[105];
int n,k;
priority_queue <pi> q;
 
int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> w[i];
    for (int i=0;i<n;i++){
        cin >> s;
        for (int j=0;j<n;j++) if (s[j]=='1') f[i][j]=1;
    }
    bs t; t.reset();
    q.push((pi){0,t});
    int cnt =0;
    while (!q.empty()){
        pi tmp=q.top(); q.pop();
        --k;
        bs r=tmp.S;
        int pos=0; for (int i=0;i<n;i++) if (r[i]) pos=i+1;
        if (k==0){
            cout << tmp.F << endl;
            break;
        }
        for (int j=pos;j<n;j++) if (!r[j]&&((r&f[j])==r)){
            r[j]=1;
            q.push((pi){tmp.F+w[j],r});
            cnt++;
            r[j]=0;
        }
    }
    //puts("-1");
    cout << cnt << endl;
    cout << cnt * (sizeof(pi)) << endl;
    cout << clock() << endl;
}