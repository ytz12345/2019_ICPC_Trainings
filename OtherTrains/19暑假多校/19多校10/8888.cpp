#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

typedef pair<int, int> piir;

int t, n;

set <piir, greater<piir> > s1, s2;

int a[N], b[N], f[N];

int in1[N], in2[N];

void work(int st) {
	static int mmax, tmp, p1, p2;
	static multiset <piir, greater<piir> >::iterator it;
	for (int i = st; i <= n * 2; i += 2) {
		mmax = (*s1.begin()).first;
		if (s2.size() >= 2) {
			it = s2.begin();
			tmp = (*it).first;
			it ++;
			tmp += (*it).first;
			if (tmp > mmax) {
				f[i] = f[i - 2] + tmp;
				p1 = (*s2.begin()).second;
				p2 = (*it).second;
				s2.erase(s2.begin());
				s2.erase(s2.begin());
				if (p1 > 0) s2.insert(piir(b[p1], -p1));
				if (p2 > 0) s2.insert(piir(b[p2], -p2));
				p1 = abs(p1), p2 = abs(p2);
				if (in1[p1] != 0) s1.erase(piir(a[p1] + b[p1], p1)), in1[p1] = 0;
				if (in1[p2] != 0) s1.erase(piir(a[p2] + b[p2], p2)), in1[p2] = 0;
			}
			else {
				f[i] = f[i - 2] + mmax;
				p1 = (*s1.begin()).second;
				s1.erase(s1.begin());
				if (in2[p1] != 0) {
					if (in2[p1] > 0) s2.erase(piir(a[p1], p1));
					else s2.erase(piir(b[p1], -p1));
					in2[p1] = 0;
				}
			}
		}
		else {
			f[i] = f[i - 2] + mmax;
			p1 = (*s1.begin()).second;
			s1.erase(s1.begin());
			if (in2[p1] != 0) {
				if (in2[p1] > 0) s2.erase(piir(a[p1], p1));
				else s2.erase(piir(b[p1], -p1));
				in2[p1] = 0;
			}
		}
	}
}

int main() {
	for (scanf("%d", &t); t --; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d %d", &a[i], &b[i]);
		s1.clear(), s2.clear();
		int mmax = 0, pos = -1;
		for (int i = 1; i <= n; i ++) {
			if (a[i] > mmax) {
				mmax = a[i];
				pos = i;
			}
		}
		f[1] = mmax;
		for (int i = 1; i <= n; i ++) {
			if (i != pos) {
				s1.insert(piir(a[i] + b[i], in1[i] = i));
				s2.insert(piir(a[i], in2[i] = i));
			}
			else {
				in1[i] = 0;
				s2.insert(piir(b[i], in2[i] = -i));
			}
		}
		work(3);

		s1.clear(), s2.clear(); f[0] = 0;
		for (int i = 1; i <= n; i ++) {
			s1.insert(piir(a[i] + b[i], in1[i] = i));
			s2.insert(piir(a[i], in2[i] = i));
		}
		work(2);

		for (int i = 1; i <= n * 2; i ++)
			printf("%d%c", f[i], i == n * 2 ? '\n' : ' ');

	}
	printf("%d\n", clock());
	return 0;
}