#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
 
const int n = 50, m = 1e5;

int q, t, x[2], y[2];

int f[(n + 5) * (m + 5)];

bool vis[n + 5][m + 5];

int gr[n + 5][m + 5];

int fa(int x, int *F = f) {
	while (x != F[x]) x = F[x] = F[F[x]];
	return x;
}

inline void un(int x, int y) {f[fa(y)] = fa(x);}

int main() {
	ios::sync_with_stdio(false);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m + 1; j ++) 
			f[(i - 1) * m + j] = (i - 1) * m + j, gr[i][j] = j;
	for (scanf("%d", &q); q --; ) {
		scanf("%d %d %d %d %d", &t, &x[0], &y[0], &x[1], &y[1]);
		if (t == 0) {
			if (x[0] > x[1]) swap(x[0], x[1]);
			if (y[0] > y[1]) swap(y[0], y[1]);
			for (int i = x[0]; i <= x[1]; i++) {
                for (int j = y[0]; j <= y[1]; j = fa(j + 1, gr[i])) {
                    vis[i][j] = 1;
                    gr[i][j] = fa(j + 1, gr[i]);
                    for (int k = 0; k < 4; k ++) {
                        int nx = i + dx[k], ny = j + dy[k];
                       	if (nx > 0 && ny > 0 && nx <= n && ny <= m && vis[nx][ny])
                            un((i - 1) * m + j, (nx - 1) * m + ny);
                    }
                }
            }
		} 
		else {
			puts(vis[x[0]][y[0]] && vis[x[1]][y[1]] && fa((x[0] - 1) * m + y[0]) == fa((x[1] - 1) * m + y[1]) ? "1" : "0");
		}
	}
 }