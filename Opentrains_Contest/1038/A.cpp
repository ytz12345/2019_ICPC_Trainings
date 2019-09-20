#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, y, z;
};

vector <node> a[4];

int sqr(int x) {return x * x;}

int main() {
	srand(time(NULL));
	for (int x, y, z, t = 0; t < 4; t ++) {
		x = rand() % 1000, y = rand() % 1000;
		while (x <= 100 || y <= 100) 
			x = rand() % 1000, y = rand() % 1000;
		printf("Q %d %d\n", x, y);
		fflush(stdout);
		cin >> z;
		for (int i = 0; i <= 100; i ++) 
			for (int j = 0; j <= 100; j ++)
				if (sqr(x - i) + sqr(y - j) == z)
					a[t].push_back((node){i, j, t == 3});
	}
	for (int t = 3; t > 0; t --) {
		for (int i = 0, s1 = a[t].size(); i < s1; i ++) {
			if (!a[t][i].z) continue;
			for (int j = 0, s2 = a[t - 1].size(); j < s2; j ++)
				if (abs(a[t][i].x - a[t - 1][j].x) + abs(a[t][i].y - a[t - 1][j].y) == 1)
					a[t - 1][j].z = 1;
		}
	}
	for (auto i : a[0])
		if (i.z == 1) {
			printf("A %d %d\n", i.x, i.y);
			fflush(stdout);
			return 0;
		} 
}