#include <bits/stdc++.h>

using namespace std;

const int N = 2560;

int n, m, a[N];

vector <int> e[N];

int tim, vis[N][N];

queue <int> qx, qy;

void bfs(int x, int y) {
    while (!qx.empty()) qx.pop();
    while (!qy.empty()) qy.pop();
    qx.push(x), qy.push(y), vis[x][y] = ++ tim;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        cin >> m; e[i].resize(m);
        for (int j = 0; j < m; j ++) {
            cin >> e[i][j];
        }
    }
    for (int i = 0; i < 2520; i ++)
        for (int j = 1; j <= n; j ++)
            if (!vis[j][i]) 
                bfs(j, i);
}