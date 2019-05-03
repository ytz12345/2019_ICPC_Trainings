#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int M = 2e5 + 5;

const int N = M << 3;

int T = 2;

int n, m ,k;

vector <int> vx, vy;

int ans[M];

ull s[M], sum, num[M];

ull c[N];

int lb(int x) {return x & (-x);}

void add(int i, ull x) {while (i <= (int)vy.size()) c[i] += x, i += lb(i);}

ull ask(int i) {ull res = 0; while (i > 0) res += c[i], i -= lb(i); return res;}

struct node {
    int x, y, id, op;
    ull v;

    bool operator < (const node &a) const {
        if (x != a.x) return x < a.x;
        if (y != a.y) return y < a.y;
        return abs(op) < abs(a.op);
    }
}a[M][4], b[M][4], d[N];

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 4; j ++) {
            cin >> a[i][j].x >> a[i][j].y;
            vx.push_back(a[i][j].x);
            vy.push_back(a[i][j].y);
            a[i][j].op = 0;
            a[i][j].id = i;
        }
    }
    int x[2], y[2];
    for (int i = 0; i < m; i ++) {
        cin >> x[0] >> y[0] >> x[1] >> y[1];
        b[i][0].x = x[0] - 1, b[i][0].y = y[0] - 1, b[i][0].op = 1;
        b[i][1].x = x[0] - 1, b[i][1].y = y[1], b[i][1].op = -1;
        b[i][2].x = x[1], b[i][2].y = y[0] - 1, b[i][2].op = -1;
        b[i][3].x = x[1], b[i][3].y = y[1], b[i][3].op = 1;
        for (int j = 0; j < 4; j ++) {
            b[i][j].id = i;
            vx.push_back(b[i][j].x);
            vy.push_back(b[i][j].y);
        }
        ans[i] = 1;
    }
    sort (vx.begin(), vx.end());
    sort (vy.begin(), vy.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < 4; j ++) {
            a[i][j].y = lower_bound(vy.begin(), vy.end(), a[i][j].y) - vy.begin() + 1;
            d[k ++] = a[i][j];
            //printf("%d %d %d %d\n", i, j, a[i][j].x, a[i][j].y);
        }
    for (int i = 0; i < m; i ++) 
        for (int j = 0; j < 4; j ++) {
            b[i][j].y = lower_bound(vy.begin(), vy.end(), b[i][j].y) - vy.begin() + 1;
            d[k ++] = b[i][j];
            //printf("%d %d %d %d\n", i, j, b[i][j].x, b[i][j].y);
        }
    sort (d, d + k);

    while (T --) {
        sum = 0;
        for (int i = 0; i < n; i ++)
            num[i] = rand(), sum += num[i] * 2;
        for (int i = 0; i < m; i ++)
            s[i] = 0;

        for (int i = 1; i <= (int)vy.size(); i ++) {
            c[i] = 0;
        }

        for (int i = 0; i < k; i ++)
            if (!d[i].op)
                d[i].v = num[d[i].id];
        
        for (int i = 0; i < k; i ++) {
            if (!d[i].op)
                add(d[i].y, d[i].v);
            else
                s[d[i].id] += ask(d[i].y) * d[i].op;
        }

        //printf("%llu\n", sum);
        for (int i = 0; i < m; i ++) {
            //printf("%d %llu\n", i, s[i]);
            ans[i] &= (s[i] == sum);
        }
    }

    for (int i = 0; i < m; i ++)
        puts(ans[i] ? "YES" : "NO");

    return 0;
}   