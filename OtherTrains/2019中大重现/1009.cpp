#include <bits/stdc++.h>

using namespace std;

typedef pair<int, double> pr;

char s[110][110];

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n >> m >> k) {
        for (int i = 0; i < n; i ++) 
            cin >> s[i];
        for (int i = 0; i < n; i ++)
            for (int t1 = 0; t1 < k; t1 ++) {
                for (int j = 0; j < m; j ++)
                    for (int t2 = 0; t2 < k; t2 ++)
                        cout << s[i][j];
                cout << '\n';
            }
    }
    return 0;
}