#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a, b, d, e, c[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b, d = b, e = n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= n; i ++)
        if (c[i] == 1 && d != b) {
            if (a != 0) a --, d ++;
            else if (d != 0) d --;
            else {e = i - 1; break;}
        }
        else {
            if (d != 0) d --;
            else if (a != 0) a --;
            else {e = i - 1; break;}
        }
    cout << e << endl;
}