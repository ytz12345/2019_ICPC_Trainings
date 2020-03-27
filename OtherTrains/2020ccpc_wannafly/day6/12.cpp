#include <bits/stdc++.h> 

using namespace std;

const int N = 110;

const int inf = 1e9;

const int ax[] = {1, 1, -1, -1, 0, 0, 0, 0};
const int ay[] = {0, 0, 0, 0, 1, 1, -1, -1};
const int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
const int dy[] = {-1, 1, -1, 1, 2, 2, -2, -2};

int n, m;

char s[N][N];

queue <int> qx, qy;

int ans[N][N];

int is_in(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m && s[x][y] != 'X';
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j ++) {
            ans[i][j] = inf;
            if (s[i][j] == 'M') {
                ans[i][j] = 0;
                qx.push(i), qy.push(j);
            }
        }
    }
    while (!qx.empty()) {
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        for (int i = 0; i < 8; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_in(nx, ny) && ans[nx][ny] > ans[x][y] + 1 && is_in(x + ax[i], y + ay[i])) {
                qx.push(nx), qy.push(ny);
                ans[nx][ny] = ans[x][y] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; printf("%d%c", ans[i][j] == inf ? -1 : ans[i][j], j == m ? '\n' : ' '), j ++);
    return 0;
}