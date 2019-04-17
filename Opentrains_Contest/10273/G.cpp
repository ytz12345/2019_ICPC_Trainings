#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define rev(i, j, k) for(int i = (j); i >= (k); i --)

using namespace std;

typedef pair<int, int> piir;

typedef pair<piir, int> pr;

const int N = 5e5 + 5;

int n, a[N];

int M;

int lt[N], rt[N];

int tr1[N << 2];//rightest 

int tr2[N << 2];//leftest

int q[N], tail;

int ansl, ans;

int lmax(int x, int y) {
	if (a[x] == a[y]) return x < y ? x : y;
	return a[x] < a[y] ? x : y; 
}

int rmax(int x, int y) {
	if (a[x] == a[y]) return x > y ? x : y;
	return a[x] < a[y] ? x : y; 
}

int ask1(int s, int t) {
	if (s > t) return -1;
	int res = 0;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = rmax(res, tr1[s ^ 1]);
		if ( t&1) res = rmax(res, tr1[t ^ 1]);
	} 
	return res;
}

int ask2(int s, int t) {
	if (s > t) return -1;
	int res = 0;
	for (s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s&1) res = lmax(res, tr2[s ^ 1]);
		if ( t&1) res = lmax(res, tr2[t ^ 1]);
	} 
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n; a[0] = 1e9 + 7;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) {
		while (tail > 0 && a[i] >= a[q[tail]]) rt[q[tail --]] = i - 1;
		q[++ tail] = i;
	}
	while (tail > 0) rt[q[tail --]] = n;
	rev(i, n, 1) {
		while (tail > 0 && a[i] >= a[q[tail]]) lt[q[tail --]] = i + 1;
		q[++ tail] = i;
	}
	while (tail > 0) lt[q[tail --]] = 1;
	
	for (M = 1; M < n + 2; M <<= 1);
	rep(i, 1, n)
		tr1[i + M] = tr2[i + M] = i;
	rev(i, M - 1, 1) {
		tr1[i] = rmax(tr1[i << 1], tr1[i << 1 | 1]);
		tr2[i] = lmax(tr2[i << 1], tr2[i << 1 | 1]);
	}

	rep(i, 1, n) {
		if (lt[i] == i) {
			if (rt[i] == i) {
				if (ans < 1 || (ans == 1 && ansl > i)) 
					ans = 1, ansl = i;
			}
			else {
				int p1 = ask2(i + 1, rt[i]);
				int p2 = ask2(p1 + 1, rt[i]);
				int rr = rt[i];
				if (p2 != -1 && a[p2] == a[p1]) rr = p2 - 1;
				if (ans < rr - i + 1 || (ans == rr - i + 1 && ansl > i))
					ans = rr - i + 1, ansl = i;
			}
		}
		else {
			if (rt[i] == i) {
				int p1 = ask1(lt[i], i - 1);
				int p2 = ask1(lt[i], p1 - 1);
				int ll = lt[i];
				if (p2 != -1 && a[p2] == a[p1]) ll = p2 + 1;
				if (ans < i - ll + 1 || (ans == i - ll + 1 && ansl > ll))
					ans = i - ll + 1, ansl = ll;
			}
			else {
				int p1 = ask1(lt[i], i - 1);
				int p2 = ask1(lt[i], p1 - 1);
				int ll = lt[i];
				int p3 = ask2(i + 1, rt[i]);
				int p4 = ask2(p3 + 1, rt[i]);
				int rr = rt[i];
				if (p2 != -1 && a[p2] == a[p1]) ll = p2 + 1;
				if (p4 != -1 && a[p4] == a[p3]) rr = p4 - 1;
				if (a[p1] == a[p3]) {
					if (ans < rr - p1 || (ans == rr - p1 && ansl > p1 + 1))
						ans = rr - p1, ansl = p1 + 1;
					if (ans < p3 - ll || (ans == p3 - ll && ansl > ll))
						ans = p3 - ll, ansl = ll;
				}
				else {
					if (a[p1] < a[p3]) {
						if (ans < rt[i] - ll + 1 || (ans == rt[i] - ll + 1 && ansl > ll))
							ans = rt[i] - ll + 1, ansl = ll;
					}
					else {
						if (ans < rr - lt[i] + 1 || (ans == rr - lt[i] + 1 && ansl > lt[i]))
							ans = rr - lt[i] + 1, ansl = lt[i];
					}
				}
			}
		}
	}

	cout << ans << ' ' << ansl << endl;
	return 0;
}