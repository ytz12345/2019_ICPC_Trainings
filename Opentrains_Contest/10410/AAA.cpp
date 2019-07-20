 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	const int N = 5;
	int n = 10, l = rand() % N + 1, r = rand() % N + 1;
	if (l > r) swap(l, r);
	printf("%d %d %d\n", n, l, r);
	for (int i = 0; i < n; i ++ ){
		printf("%d %d %d\n", 
			rand() % N * (rand() % 2  ? 1:-1), 
			rand() % N * (rand() % 2  ? 1:-1),
			rand() % N * (rand() % 2  ? 1:-1));
	}
	return 0;
}