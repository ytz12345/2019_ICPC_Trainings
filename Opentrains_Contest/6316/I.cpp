#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int t, n, a[N];

int main() {
	for (int i = 1; i * (i + 1) * (i + 2) < N; i ++)
		for (int j = i + 1; i * j * (j + 1) < N; j ++)
			for (int k = j + 1; i * j * k < N; k ++) 
				a[i * j * k] ++;
	for (int i = 1; i < N; i ++)
		a[i] += a[i - 1];
	//cout << clock() << endl;
	for (cin >> t; t --; ) {
		cin >> n;
		cout << a[n] << '\n';
	}
}