#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 510;

int t, n, m, a[N][N];

#define fir first
#define sec second

piir b[N];

int ans;

int q0[N], h0, t0;

int q1[N], h1, t1;

int main() {
	ios::sync_with_stdio(false);
	for (cin >> t; t --; ) {
		cin >> n >> m;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				cin >> a[i][j];

		ans = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				if (j == i + 1) {
					for (int k = 1; k <= n; k ++)
						b[k] = piir(1e9, -1e9);
				}

				t0 = t1 = 0;
				h0 = h1 = 1;
				int last = 0; 
				for (int k = 1; k <= n; k ++) {
					//cout << i << ' ' << j << ' ' << k << endl;
					b[k].fir = min(b[k].fir, a[j][k]);
					b[k].sec = max(b[k].sec, a[j][k]);
					//cout << b[k].fir << ' ' << b[k].sec << endl;

					while (t0 >= h0 && b[q0[t0]].fir >= b[k].fir) t0 --;
					q0[++ t0] = k;

					while (t1 >= h1 && b[q1[t1]].sec <= b[k].sec) t1 --;
					q1[++ t1] = k; 

					while (t0 >= h0 && t1 >= h1 && b[q1[h1]].sec - b[q0[h0]].fir > m) {
						last ++;
						//cout << q0[t0] << ' ' << q1[t1] << endl;
						//exit(0);
						if (t0 >= h0 && q0[h0] == last) h0 ++;
						if (t1 >= h1 && q1[h1] == last) h1 ++;
					}
					//cout << q0[t0] << ' ' << q1[t1] << endl;
					//cout << b[q0[t0]].fir << ' ' << b[q1[t1]].sec << endl;
					if (t0 >= h0 && t1 >= h1)
						ans = max(ans, (j - i) * (k - last));
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}