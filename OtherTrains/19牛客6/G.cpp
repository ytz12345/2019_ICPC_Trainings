#include <bits/stdc++.h>

using namespace std;

int kk;

struct node {
	int b[10];
}a[3630000];

int p[10];

int tt, n;

string s[100010];

int isRun(int yy) {
	if (yy % 100 == 0) return yy % 400 == 0;
	return yy % 4 == 0;
}

int isValid(int yy, int mm, int dd) {
	if (mm <= 0 || mm > 12) return 0;
	if (yy < 1600 || yy > 9999) return 0;
	if (dd <= 0) return 0;
	static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (mm != 2) return dd <= days[mm];
	return dd <= days[mm] + isRun(yy);
}

/*int calc(int y, int m, int d) {
	int ans = 1;
	if (m < 3) m += 12, y --;
	if ((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3))
		ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + 5) % 7;
	else 
		ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	return ans + 1;
}*/

int calc(int yy, int mm, int dd) {
	int m = mm; if (m < 3) m += 12, yy --;
	int c = yy / 100;
	int y = yy % 100;
	int d = dd;
	int w = (c / 4 - c * 2 + y + y / 4 + (13 * (m + 1)) / 5 + d - 1) % 7;
	return (w + 7) % 7;
}

int isFri(int yy, int mm, int dd) {
	if (!isValid(yy, mm, dd)) return 0;
	
	return calc(yy, mm, dd) == 5;
}

int main() {
	/*cin >> tt;
	while (tt --) {
		int y, m, d;
		cin >> y >> m >> d;
		cout << calc(y, m, d) << endl;
	}
	return 0;*/
	
	for (int i = 0; i < 10; i ++)
		p[i] = i;
	while (1) {
		for (int i = 0; i < 10; i ++)
			a[kk].b[i] = p[i];//, printf("%d ", p[i]);
		//puts("");
		kk ++;
		if (!next_permutation(p, p + 10)) break;
	}

	//return 0;
	
	//cout << sizeof (a);
	ios::sync_with_stdio(false);
	cin >> tt;
	for (int t = 1; t <= tt; t ++) {
		cin >> n;
		for (int i = 0; i < n; i ++)
			cin >> s[i];

		sort (s, s + n);
		n = unique(s, s + n) - s;
		//printf("%d\n", n);
		random_shuffle (s, s + n);

		int ok = 0;
		for (int i = 0; i < kk; i ++) {
			int flag = 1, yy, mm, dd;
			for (int j = 0; j < n; j ++) {
				yy = mm = dd = 0;
				for (int k = 0; k < 4; k ++)
					yy = yy * 10 + a[i].b[s[j][k] - 'A'];
				for (int k = 5; k < 7; k ++)
					mm = mm * 10 + a[i].b[s[j][k] - 'A'];
				for (int k = 8; k < 10; k ++)
					dd = dd * 10 + a[i].b[s[j][k] - 'A'];

				if (!isFri(yy, mm, dd)) {
					flag = 0;
					break;
				}

			}
			if (flag) {
				ok = 1;
				printf("Case #%d: ", t);
				for (int j = 0; j < 10; j ++)
					printf("%d", a[i].b[j]);
				puts("");

				//printf("%d\n", i);
				break;
			}
		}
		if (!ok) {
			printf("Case #%d: Impossible\n", t);
		}
	}
	
}