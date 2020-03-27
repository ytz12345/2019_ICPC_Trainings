#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

typedef long long ll;

int n, c[70];

ll s, a;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a;
        s ^= a;
        for (int i = 0; i < 60; i ++)
            c[i] += a & 1, a >>= 1;
        if (s == 0) puts("0");
        else {
            for (int i = 59; i >= 0; i --) 
                if ((s >> i) & 1) {
                    printf("%d\n", c[i]);
                    break;
                }
        }
    }
    return 0;
}