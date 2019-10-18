#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> piir;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll a, b, c;
	while (cin >> a >> b) {
		if (b < a) c = a;
		else c = b + 1; 
		cout << c << '\n';
	}
}