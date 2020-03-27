// n*a(n) +(-9*n+8)*a(n-1) +2*(13*n-23)*a(n-2) +12*(-2*n+5)*a(n-3)=0
// a[n] = ((9n+8)*a[n-1] - 2*(13n-23)*a[n-2] + 12 *(2n-5)*a[n-3] ) / n
#include <bits/stdc++.h>

using namespace std;

int n, a[10];

int judge() {
    int last[2], flag;
    for (int i = 0, up = 1 << n; i < up; i ++) {
        last[0] = -1, last[1] = n; flag = 1;
        for (int j = 0; j < n; j ++) 
            if (i >> j & 1) {
                if (a[j] > last[0]) last[0] = a[j];
                else {flag = 0; break;}
            }
            else {
                if (a[j] < last[1]) last[1] = a[j];
                else {flag = 0; break;}
            }
        if (flag) return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) a[i] = i;
    int ans = 0;
    while (1) {
        ans += judge();
        if (!next_permutation(a, a+ n)) break;
    }
    cout << ans << endl;
    return 0;
}