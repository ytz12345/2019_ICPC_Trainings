#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, k;

char s[N];

int main() {
    scanf("%d %d %s", &n, &k, s);
    int flag = 1;
    for (int i = k; i < n; i ++)
        if (s[i % k] != s[i]) {
            if (s[i % k] > s[i]) flag = 1;
            else flag = 0;
            break;
        }
    if (flag) {
        for (int i = k; i < n; i ++)
            s[i] = s[i % k];
        printf("%d\n%s\n", n, s);
    }
    else {
        s[k - 1] ++;
        for (int i = k - 1; i >= 0; i --) 
            if (s[i] > '9') s[i - 1] ++, s[i] = '0';
            else break;
        for (int i = k; i < n; i ++)
            s[i] = s[i % k];
        printf("%d\n%s\n", n, s);
    }
}