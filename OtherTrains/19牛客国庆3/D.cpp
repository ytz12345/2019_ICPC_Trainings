#include<bits/stdc++.h>

#define rep(i, j, k) for (int i = j; i <= k; i ++)

using namespace std;

const int N = 2019;

char s[N][N];

int n, m, ans;

bool judge(int x, int y, char c) {
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == c;
}

void cover(int x, int y, int a, int b, int c, int d) {
    s[x][y] = s[x + a][y + b] = s[x + c][y + d] = 0;
}

int main() {
    while(~scanf("%d %d", &n, &m)) {
        ans = 0;
        rep(i, 1, n) scanf("%s", s[i] + 1);
        rep(i, 1, n) rep(j, 1, m) 
            if (s[i][j] == '^') {
                if (judge(i + 1, j - 1, 'v') && judge(i + 1, j + 1, 'v'))
                    ans ++, cover(i, j, 1, -1, 1, 1);
                else if (judge(i, j + 2, '^') && judge(i + 1, j + 1, 'v'))
                    ans ++, cover(i, j, 0, 2, 1, 1);
            }
            else if (s[i][j] == '<') {
                if (judge(i + 1, j + 1, '>') && judge(i + 2, j, '<'))
                    ans ++, cover(i, j, 1, 1, 2, 0);
            }
            else if (s[i][j] == '>' && judge(i + 1, j - 1, '<') && judge(i + 2, j, '>'))
                ans ++, cover(i, j, 1, -1, 2, 0);
        printf("%d\n", ans);
    }
}