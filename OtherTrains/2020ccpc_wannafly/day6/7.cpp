#include <bits/stdc++.h>

using namespace std;

int k;

int *pos;

void solve(int *a, int *b, int n, int st) {
    if (n == 0) return;
    if (a[0] == -1) {
        b[0] = 1;
        vector <int> e; e.clear();
        for (int i = 0; i < n; i ++)
            if (b[i] == 1)
                e.push_back(i);
        //puts("?");printf("%d\n", e.size());
        for (int i = 0, sz = e.size(); i < sz; i ++)
            a[e[i]] = st + sz - i;//, printf("%d %d %ld\n", e[i], a[e[i]], a + e[i] - pos);
        for (int i = 0; i < n; i ++)
            if (b[i] != -1)
                b[i] --;
        solve(a + 1, b + 1, n - 1, st + e.size());
    }
    else {
        solve(a + 1, b + 1, n - 1, st);
    }
}

int t, n, a[123], b[123];

int main() {
    ios::sync_with_stdio(false);
    for (cin >> t; t --; ) {
        cin >> n; k = n;
        for (int i = 1; i <= n; i ++)
            cin >> b[i], a[i] = -1;
        pos = a;
        solve(a + 1, b + 1, n, 0);
        for (int i = 1; i <= n; i ++)
            printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}