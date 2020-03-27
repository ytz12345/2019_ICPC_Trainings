#include <bits/stdc++.h>

using namespace std;

const int N = 8e4 + 5;

int n, m, siz;

int a[N], b[N];

int flag[N];

int calc(int l, int r, int x) {
    int res = 0;
    if (l / siz == r / siz) {
        int bk = l / siz;
        for (int i = l; i <= r; i ++)
            res += min(flag[bk], a[i]) <= x;
        return res;
    }
    for (int i = l, bk = l / siz, up = min(bk * siz + siz, r + 1); i < up; i ++)
        res += min(a[i], flag[bk]) <= x;
    for (int up = r + 1, bk = r / siz, i = max(l, bk * siz); i < up; i ++)
        res += min(a[i], flag[bk]) <= x;
    
    for (int i = l / siz + 1, up = r / siz; i < up; i ++) {
        if (flag[i] <= x) res += siz;
        else {
            int L = i * siz, R = i * siz + siz - 1, mid, pos = L - 1;
            while (L <= R) {
                mid = (L + R) / 2;
                if (b[mid] <= x) pos = mid, L = mid + 1;
                else R = mid - 1;
            }
            res += pos - (i * siz) + 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    siz = max(int(sqrt(n * log(n) / log(2)) + 0.5), 5);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 0; i < n; i += siz) {
        sort (b + i, b + min(i + siz, n));
        flag[i / siz] = 1e9;
    }
    for (int op, l, r, k; m --; ) {
        cin >> op >> l >> r >> k;
        l --, r --;
        if (op == 1) {
            for (int i = l, bk = l / siz, up = min(bk * siz + siz, r + 1); i < up; i ++)
                a[i] = min(a[i], min(flag[bk], k));
            for (int up = r + 1, bk = r / siz, i = max(l, bk * siz); i < up; i ++)
                a[i] = min(a[i], min(flag[bk], k));
            for (int bk = l / siz, i = bk * siz, up = min(i + siz, n); i < up; i ++)
                b[i] = a[i] = min(a[i], flag[bk]);
            for (int bk = r / siz, i = bk * siz, up = min(i + siz, n); i < up; i ++)
                b[i] = a[i] = min(a[i], flag[bk]);
            sort (b + l / siz * siz, b + min(l / siz * siz + siz, n));
            sort (b + r / siz * siz, b + min(r / siz * siz + siz, n));
            flag[l / siz] = flag[r / siz] = 1e9;

            for (int i = l / siz + 1, up = r / siz; i < up; i ++)
                flag[i] = min(flag[i], k);
        }
        else {
            int L = 0, R = n + 1, mid, ans;
            while (L <= R) {
                mid = (L + R) / 2;
                if (calc(l, r, mid) >= k) ans = mid, R = mid - 1;
                else L = mid + 1;
            }
            printf("%d\n", ans);
        }
    }
}