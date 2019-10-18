#include <bits/stdc++.h>

typedef long long ll;

ll divide(ll a, ll b){
    return a / b - (a % b && (a ^ b) < 0);
}

ll getarea(ll x, ll y, ll inv){
    return divide(x - y * (inv ? 3 : 2), 5);
}

int main(){
    bool inv = false;
    ll x1, y1, x2, y2;
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    if (x1 > x2){
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    if (y1 > y2){
        inv = !inv;
        y1 = -y1, y2 = -y2;
    }
    if (x2 - x1 < y2 - y1){
        inv = !inv;
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
    printf("%lld\n", x2 + y2 - x1 - y1 
    	+ std::max(0ll, 2 * (getarea(x2, y2, inv) - getarea(x1, y1, inv))));
    return 0;
}