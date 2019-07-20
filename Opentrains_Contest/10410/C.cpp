#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;

struct node{
	int k;
	vector <double> e;
	double t1, t2, t3; 

	void calc() {
		t1 = t2 = 0, t3 = 1;
		for (int i = 0; i < k; i ++) {
			t1 += t3 * (1 - e[i]);
			t2 += t3 * (1 - e[i]) * (i + 1);
			t3 *= e[i];
		}
		t3 *= k;
	}
}a[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> k;
		a[i].e.resize(k);
		for (int j = 0; j < k; j ++)
			cin >> a[i].e[j], a[i].e[j] /= 1000;
		a[i].calc();
	}

	sort (a, a + n, [&](node x, node y) {
		double rx = x.t3, ry = y.t3;
		for (int i = 0; i < x.k; i ++) {
			
		}
	});


}