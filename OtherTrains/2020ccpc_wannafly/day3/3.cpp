#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

int n, m, a[20][20];

vi dp[200000];

int b[20];

vi temp;

int tmp;

inline int lb(int x) {return x & (-x);}

int lg2[200000];

int main() {
    for (int i = 1, j = 0; j < 17; i <<= 1, j ++) lg2[i] = j;
    cin >> n >> m;
    for (int x, y, i = 0; i < m; i ++)
        cin >> x >> y, x --, y --, a[x][y] = a[y][x] = 1;
    for (int i = 1, up = 1 << n; i < up; i ++) {
        b[0] = 0;
        for (int j = 0; j < n; j ++)
            if (i >> j & 1)
                b[++ b[0]] = j;
        if (b[0] == 1) {
            tmp = 1 << b[1];
            dp[i].push_back(tmp);
        } 
        else {
            int upd = -1; 
            for (int j = 1; j <= b[0]; j ++) {
                temp.clear();
                int flag = 1;
                for (int v : dp[i ^ (1 << b[j])]) 
                    temp.push_back(v);
                int pushed = 0;
                for (int &v : temp) {
                    int flag = 1, x = v;
                    while (x) {
                        int u = lg2[lb(x)];
                        if (a[b[j]][u]) {
                            flag = 0;
                            break;
                        }
                        x -= lb(x);
                    }
                    if (flag) {
                        v |= 1 << b[j];
                        pushed = 1;
                        break;
                    }
                }
                if (!pushed) tmp = 1 << b[j], temp.push_back(tmp);
                if (upd == -1 || dp[i].size() > temp.size())
                    upd = 1, dp[i] = temp;
            }
        }
        //cout << i << ' ' << dp[i].size() << endl;
    }
    cout << dp[(1 << n) - 1].size() - 1 << endl;
    return 0;
}