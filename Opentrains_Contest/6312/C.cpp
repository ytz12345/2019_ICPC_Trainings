#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N = 2e5 + 5;

const int p1 = 233, p2 = 2333;

map <ull, bool> p;

ull h1[N], h2[N], b1, b2, h;

char s[23];

int n, m, k;

int main() {
    srand(time(NULL));
    cin >> n >> m >> k; b1 = b2 = 1;
    for (int i = 0; i < m; i ++) cin >> s[i];
    for (int j, i = 0; i < n; i ++) {
        j = m - 1, putchar(s[j]);
        h1[i] = h1[i - 1] * p1 + s[j], h2[i] = h2[i - 1] * p2 + s[j];
        b1 *= p1, b2 *= p2;    
    }
    p[(h1[n - 1] << 23) + h2[n - 1]] = 1;
    for (int i = 0; i < k - 1; i ++) 
        for (int j = 0; j < m; j ++) {
            h1[n + i] = h1[n + i - 1] * p1 + s[j];
            h2[n + i] = h2[n + i - 1] * p2 + s[j];
            if (p.find(h = (((h1[n + i] - h1[i] * b1) << 23) + (h2[n + i] - h2[i] * b2))) == p.end()) {
                p[h] = 1; putchar(s[j]); break;
            }
        }
}