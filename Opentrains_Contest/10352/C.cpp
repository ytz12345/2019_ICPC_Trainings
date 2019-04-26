#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long x, y, z;

double t;

int main() {
	ios::sync_with_stdio(false);
	scanf("%*s %lld %*s %lf %lld", &x, &t, &z);
	y = int(t * 100000 + 0.8), z *= 100000;
	if (x * y == z) puts("Whatever");
	else if (x * y > z) puts("Power up, Evolve");
	else puts("Evolve, Power up");
	return 0;
}