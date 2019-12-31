#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2019;

int n, m;

vector <int> e[N];

struct {int u, v;}a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int p, i = 2; i <= n; i ++) {
        cin >> p;
        e[p].push_back(i);
    }
    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> a[i].u >> a[i].v;
    
}