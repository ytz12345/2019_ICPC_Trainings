#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll t, n;

char str[N][5];

ll len[N];

ll s1, s2, s3, s4, ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t --) {
		cin >> n; s1 = s2 = 0;
		for (int i = 0; i < n; i ++) {
			cin >> len[i] >> str[i];
			if (str[i][0] == 'B') s1 += len[i];
			else s2 += len[i];
		}
		if (s1 == 0) printf("%lld\n", s2);
		else if (s2 == 0) printf("%lld\n", s1);
		else {
			ll tmp = __gcd(s1, s2);
			s1 /= tmp, s2 /= tmp;
			s3 = s4 = 0; ans = 0;
			for (int i = 0; i < n; i ++) {
				if (str[i][0] == 'B') {
					if (s4 == 0 || s4 % s2 != 0) s3 += len[i];
					else if (s3 * s2 < s1 * s4 && s1 * s4 <= (s3 + len[i]) * s2) {
						ans ++;
						s3 = s3 + len[i] - s1 * s4 / s2;
						s4 = 0;
						//printf("B %d\n", i);
					}
					else s3 += len[i];
				}
				else {
					if (s3 % s1 != 0) s4 += len[i];
					else if (s3 * s2 > s1 * s4 && s1 * (s4 + len[i]) >= s3 * s2) {
						ans ++;
						s4 = s4 + len[i] - s2 * s3 / s1;
						s3 = 0;
						//printf("W %d\n", i);
					}
					else s4 += len[i];
				}
				//printf("%d %lld %lld %lld %lld %lld\n", i, s1, s2, s3, s4, ans);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}