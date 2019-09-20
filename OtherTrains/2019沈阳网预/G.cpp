#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 6;

double a[N];

int t;

char s[N];

double x;

int main() {
	a[1] = 5.0 / 3;
	for (int i = 2; i < N; i ++)
		a[i] = a[1] - 1.0 / (a[i - 1] * 9 + 6);
	scanf("%d", &t);
	while (t --) {
		scanf("%s %lf", s, &x);
		if (strlen(s) >= 6) printf("%.10f\n", a[10000] * x);
		else {
			int n = 0;
			int len = strlen(s);
			for (int i = 0; i < len; i ++)
				n = n * 10 + s[i] - '0';
			printf("%.10f\n", a[n] * x);
		}
	}
	//printf("%.15f %.15f\n", a[10000] * 1e6, a[1000000] * 1e6);
	return 0;
}