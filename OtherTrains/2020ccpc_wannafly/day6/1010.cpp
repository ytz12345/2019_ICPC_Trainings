#include <bits/stdc++.h>

using namespace std;

int a[1010];

    int n;

int v[1010];
bool judge() {
    memset(v, 0, sizeof(v));
    int x = 0, c=  0;
    while (!v[x]) {
        v[x] = 1;
        c ++;
        x = a[x];
    }
    return c == n;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) a[i] = i;
    int ans = 0;
    while (1){
        ans += judge();
        if (!next_permutation(a,a  +n)) break;
    }
    cout << ans << endl;
 }