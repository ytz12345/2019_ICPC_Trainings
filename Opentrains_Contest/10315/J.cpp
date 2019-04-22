#include <bits/stdc++.h>
using namespace std;

int n;
int a[210][210];
vector <int> ve[210], ve1[210];
bool used[210];
int x[210];

void dfs(int k) {
        used[k] = true;
        for (int i = 0; i < (int) ve[k].size(); i++)
                if (!used[ve[k][i]]) {
                        x[ve[k][i]] = x[k] + ve1[k][i];
                        dfs(ve[k][i]);
                }
}

int main() {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                        scanf("%d", &a[i][j]);
        int m;
        scanf("%d", &m);
        while (m--) {
                int s, t, w;
                scanf("%d%d%d", &s, &t, &w);
                ve[t].push_back(s);
                ve1[t].push_back(-w);
                ve[s].push_back(t);
                ve1[s].push_back(w);
        }
        for (int i = 1; i <= n; i++)
                if (!used[i]) {
                        x[i] = 0;
                        dfs(i);
                }
        for (int i = 1; i <= n; i++)
                for (int j = 0; j < (int) ve[i].size(); j++) {
                        if (x[ve[i][j]] != x[i] + ve1[i][j]) {
                                printf("Impossible\n");
                                return 0;
                        }
                }
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                        a[i][j] += x[j] - x[i];
        for (int i = 1; i <= n; i++) {
                for (int j = 1; j < n; j++)
                        printf("%d ", a[i][j]);
                printf("%d\n", a[i][n]);
        }
}