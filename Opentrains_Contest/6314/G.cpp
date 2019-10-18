#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

const int N = 50;

char str[N];

int n, x, y;

vector <piir> p;

int f(char ch) {
	if (ch == 'L') return 0;
	if (ch == 'R') return 1;
	if (ch == 'U') return 2;
	return 3;
}

bool check() {
	int s = x, t = y;
	for (int i = 0; i < n; i ++) {
		int nx, ny, fg = -1;
		if (str[i] == 'L') {
			for (auto pt : p) {
				if (pt.first < s && pt.second == t) {
					if (fg == -1 || pt.first + 1 > nx) {
						fg = 0;
						nx = pt.first + 1;
						ny = t;
					}
				}
			}
		}
		else if (str[i] == 'R') {
			for (auto pt : p) {
				if (pt.first > s && pt.second == t) {
					if (fg == -1 || pt.first - 1 < nx) {
						fg = 0;
						nx = pt.first - 1;
						ny = t;
					}
				}
			}
		}
		else if (str[i] == 'U') {
			for (auto pt : p) {
				if (pt.first == s && pt.second > t) {
					if (fg == -1 || pt.second - 1 < ny) {
						fg = 0;
						ny = pt.second - 1;
						nx = s;
					}
				}
			}
		}
		else {
			for (auto pt : p) {
				if (pt.first == s && pt.second < t) {
					if (fg == -1 || pt.second + 1 > ny) {
						fg = 0;
						ny = pt.second + 1;
						nx = s;
					}
				}
			}
		}
		if (fg != -1) s = nx, t = ny;
		else {
			if (str[i] == 'U') {
				if (s == 0 && t < 0) t = 0;
				else t = 1e9; 
			}
			else if (str[i] == 'D') {
				if (s == 0 && t > 0) t = 0;
				else t = -1e9;
			}
			else if (str[i] == 'L') {
				if (t == 0 &&s > 0) s = 0;
				else s = -1e9;
			}
			else {
				if (t == 0 && s < 0) s = 0;
				else s = 1e9;
			}
		}
	}
	return s == 0 && t == 0;
}

int op[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> str; char st[N]; srand(time(NULL));
	n = strlen(str);
	for (int i = n - 1; i != -1; i = -1)
		if (str[i - 2] == str[i] && (f(str[i]) ^ f(str[i - 1])) == 1) {
			puts("impossible");
			return 0;
		}
	for (int i = n - 3; i >= 0; i --)
		if ((f(str[i + 1]) ^ f(str[i + 2])) == 1 && str[i] == str[i + 2])
			op[i] = -1;
	int nn = 0;
	for (int i = 0; i < n; i ++)
		if (op[i] != -1)
			str[nn ++] = str[i];
	str[n = nn] = 0;
	//puts(str);
	do {
		p.clear(), x = y = 0;
		for (int d, i = n - 1; i >= 0; i --) {
			if (i != n - 1 && (f(str[i]) ^ f(str[i + 1])) == 1) d = rand() % 10 + 10;
			else d = rand() % 100 + 100;
			if (str[i] == 'L') x += d;
			else if (str[i] == 'R') x -= d;
			else if (str[i] == 'U') y -= d;
			else y += d;
			if (i != 0) {
				if (str[i - 1] == 'L') p.push_back(piir(x - 1, y));
				else if (str[i - 1] == 'R') p.push_back(piir(x + 1, y));
				else if (str[i - 1] == 'U') p.push_back(piir(x, y + 1));
				else p.push_back(piir(x, y - 1));
				//printf("%d %d\n", p[int(p.size()) - 1].first, p[int(p.size()) - 1].second);
			}
			//printf("i=%d d=%d\n", i,d);
		}
		//break;
	}while (!check());
	printf("%d %d\n%d\n", x, y, int(p.size()));
	for (piir pt : p)
		printf("%d %d\n", pt.first, pt.second);
	return 0;
}