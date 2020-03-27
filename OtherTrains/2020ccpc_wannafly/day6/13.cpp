#include <bits/stdc++.h> 

using namespace std;

int n, m, w;

int locked[110];//is calc finished?

vector <int> tj[110][11];

int is_ac[110][11];

int ans[110];

int ac_person[11];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> w;
    for (int x, y, c; w --; ) {
        cin >> x >> y >> c;
        tj[x][y].push_back(c);
    }

    //count people solve pro i
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            for (int k : tj[i][j])
                if (k == 1) {
                    ac_person[j] ++;
                    is_ac[i][j] = 1;
                    break;
                }
    }

    //rule 1
    for (int i = 1; i <= n; i ++) {
        int sum = 0;
        for (int j = 1; j <= m; j ++)
            sum += tj[i][j].size();
        if (sum == 0) {
            ans[i] = 998244353;
            locked[i] = 1;
        }
    }

    //rule 2 & 3
    for (int i = 1; i <= n; i ++) {
        int ac_sum = 0;
        for (int j = 1; j <= m; j ++)
            ac_sum += is_ac[i][j];
        if (ac_sum == 0 && !locked[i]) {
            ans[i] = 1000000;
            locked[i] = 1;
        }
        if (ac_sum == m && !locked[i]) {
            ans[i] = 0;
            locked[i] = 1;
        }
    }

    //rule 4 & 5
    for (int i = 1; i <= n; i ++) {
        if (locked[i]) continue;
        for (int j = 1; j <= m; j ++) 
            if (!is_ac[i][j] && ac_person[j] != 0) {
                ans[i] += 20;
                if (ac_person[j] >= n / 2) ans[i] += 10;
            }
    }

    //rule 6 & 7
    for (int i = 1; i <= n; i ++) {
        if (locked[i]) continue;
        for (int j = 1; j <= m; j ++) 
            if (!is_ac[i][j]) {
                ans[i] += int(tj[i][j].size()) * int(tj[i][j].size()) * 2;
            }
            else {
                int cnt = 0, mmax = 0;
                for (int k = 0, sz = tj[i][j].size(); k < sz; k ++) {
                    if (tj[i][j][k] == 1) mmax = max(mmax, cnt), cnt = 0;
                    else cnt ++;
                }
                mmax = max(mmax, cnt);
                ans[i] += mmax * mmax;
            }
    }

    for (int i = 1; i <= n; i ++)
        printf("%d\n", ans[i]);
    return 0;
}