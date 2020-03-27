#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

typedef long long ll;

typedef pair<int, int> pr;

int n;

char s[40][40];

bitset <2048> a[1024];

vector <pr> p;

int pos[40][40];

ll qpow(ll a, ll b) {
	ll c = 1;
	while (b > 0) {
		if (b & 1) c = c * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    n = 1 << n;
    for (int i = 0; i < n; i ++)
        cin >> s[i];
    int x, y;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            if (s[i][j] == '1') 
                p.push_back(pr(i, j));
    for (int now = 0, i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) 
            pos[i][j] = now ++;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            for (int k = 0; k < int(p.size()); k ++) {
                a[pos[i][j]][pos[(i + p[0].first - p[k].first + n) % n][(j + p[0].second - p[k].second + n) % n]] = 1;
            }
            a[pos[i][j]][n * n + pos[i][j]] = 1;
        }
    for (int i = 0; i < n * n; i ++) {
        int now = i;
        while (now < n * n && a[now][i] == 0) now ++;
        if (now >= n * n) continue;
        if (now != i) swap(a[now], a[i]);
        for (int j = i + 1; j < n * n; j ++)
            if (a[j][i] == 1) a[j] ^= a[i];
    }
    int ans = 0;
    for (int i = 0; i < n * n; i ++) 
        if (a[i].count() != 0)
            for (int j = i + 1; j < n * n; j ++)
                if (a[j].count() != 0)
                    if (a[i] == a[j])
                        a[j].reset();
    
    for (int i = 0; i < n * n; i ++)
        ans += a[i].count() != 0;
    //ans = n * n - ans;
    cout << qpow(2, ans) << endl;
}