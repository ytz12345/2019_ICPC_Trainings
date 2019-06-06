#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> piir;

const int N = 1e5 + 5;

const int inf = 1e4;

set <int> s;

int main() {
	int n = 1e2;
	srand(time(NULL));
	for (int i = 0; i < inf; i ++)
		s.insert(rand() % n);
	cout << s.size();
	return 0;
}