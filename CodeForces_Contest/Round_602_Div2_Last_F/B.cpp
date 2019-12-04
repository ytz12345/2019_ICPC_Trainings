#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int t, n, a[N], b;

set <int> s;

int main() {
    ios::sync_with_stdio(false);
    for (cin >> t; t --; ) {
        cin >> n;
        int flag = 1; s.clear();
        for (int i = 1; i <= n; i ++) s.insert(i);
        for (int i = 1; i <= n; i ++) {
            cin >> b;
            if (b < i) {
                flag = 0;
                for (i ++; i <= n; i ++) cin >> b;
                break;
            }
            if (s.find(b) != s.end()) a[i] = b;
            else a[i] = *s.begin();
            s.erase(a[i]);
        }
        if (flag) for (int i = 1; i <= n; i ++) printf("%d%c", a[i], i == n ? '\n' : ' ');
        else puts("-1");
    }
}