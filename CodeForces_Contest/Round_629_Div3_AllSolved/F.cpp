#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, m, k;

ll a[N], ans = 1e18;

map <ll, int> p;

ll s1[N], s2[N], s3[N], s4[N];

struct node {ll v, c;}b[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k; int mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i]; 
        mx = max(mx, ++ p[a[i]]);
    }
    if (mx >= k) {
        cout << 0 << endl;
        return 0;
    }
    for (auto i : p)
        b[++ m] = (node){i.first, i.second};
    sort (b + 1, b + m + 1, [&](node x, node y){return x.v < y.v;});
    for (int i = 1; i <= m; i ++) 
        s1[i] = s1[i - 1] + b[i].v * b[i].c, s3[i] = s3[i - 1] + b[i].c;
    for (int i = m; i >= 1; i --)
        s2[i] = s2[i + 1] + b[i].v * b[i].c, s4[i] = s4[i + 1] + b[i].c;
    for (int i = 1; i <= m; i ++) 
        if (s3[i] >= k) {
            ans = min(ans, b[i].v * s3[i - 1] - s1[i - 1] - (s3[i] - k));
            break;
        }
    //cout << ans << endl;
    for (int i = m; i >= 1; i --)
        if (s4[i] >= k) {
            ans = min(ans, s2[i + 1] - b[i].v * s4[i + 1] - (s4[i] - k));
            break;
        }
    //cout << ans << endl;
    for (int i = 1; i <= m; i ++) {
        ans = min(ans, b[i].v * s3[i - 1] - s1[i - 1] + s2[i + 1] - b[i].v * s4[i + 1] - (n - k));
    }
    cout << ans << endl;
    return 0;
}