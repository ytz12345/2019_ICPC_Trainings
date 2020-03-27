#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

typedef long long ll;

int n, m;

int a[N], b[N];

int c[N][110];

char s[110];

int len[N];

int char_to_int(char ch) {
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    return ch - 'A' + 26;
}

char int_to_char(int x) {
    if (x <= 25) return 'a' + x;
    return 'A' + x - 26;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i ++) {
        cin >> s;
        len[i] = strlen(s);
        for (int j = 0; j < len[i]; j ++) 
            c[i][j] = char_to_int(s[j]);
    }
    for (int i = m - 1; i >= 0; i --)
        for (int j = 0; j < len[b[i]]; j ++)
            c[b[i]][j] = (c[b[i]][j] + 52 - c[a[i]][j % len[a[i]]]) % 52;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < len[i]; j ++)
            cout << char(int_to_char(c[i][j]));
        cout << '\n';
    }
    return 0;
}