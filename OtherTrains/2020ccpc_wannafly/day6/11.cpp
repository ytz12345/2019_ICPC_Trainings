#include <bits/stdc++.h> 

using namespace std;

int n;

int a[233333];

int main() {
    cin >> n;
    for (int i = 1, j = n, k = 1; ; ) {
        if (i <= j) a[i ++] = k ++;
        else break;
        if (i <= j) a[j --] = k ++;
        else break;
    }
    for (int i = 1; i <= n; i ++)
        printf("%d ", a[i]);
    return 0;
}