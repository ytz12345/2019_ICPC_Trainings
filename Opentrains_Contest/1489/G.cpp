#include <bits/stdc++.h>

using namespace std;

const int N = 200;

const int n = 150;

const int M = 13;

int a[N][N], b[N][N], c[N][N];

void print() {

	printf("%d\n", n);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++)
			printf("%c", c[i][j] ? 'O' : '.');
		puts("");
	}
}

bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cnt += c[i][j];
	if (cnt < 1700) return 0;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) if (c[i][j]) 
			for (int x = 1; x < i; x ++) if (c[x][j])
				for (int y = 1; y < j; y ++) if (c[i][y])
					if (c[x][y])
						return 0;

	return 1;
}

void make() {
	for (int i = 1; i <= M; i ++)
        for (int j = 1; j <= M; j ++)
            a[i][j + 1] = M * (j - 1) + i;
    for (int i = 1; i <= M; i ++)
        for (int j = 1; j <= M; j ++)
            c[i][a[i][j]] = 1;
    for (int k = 1; k < M; k ++) {
        memcpy(b, a, sizeof b);
        for (int i = 1; i <= M; i ++)
            for (int j = 1; j <= M; j ++)
                a[i][j] = (b[i + j - 1 - ((i + j - 1) > M ? M : 0)][j]);
        for (int i = 1; i <= M; i ++)
            for (int j = 1; j <= M; j ++)
                c[k * M + i][a[i][j]] = 1;
    }
}

int main() {
	srand(time(NULL));
	ios::sync_with_stdio(false);
	make();
	if (check() == true) 
		print();
	else 
		puts("sb");
	return 0;
}