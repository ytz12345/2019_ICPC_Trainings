#include <bits/stdc++.h>

using namespace std;


string last = "farther", in;

void forward() {
	puts("forward");
	fflush(stdout);
	cin >> in;
}

void dig() {
	puts("dig");
	fflush(stdout);
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	int c1, c2, flag = 1;
	while (flag) {
		forward();
		if (last[0] != 'f' && in[0] == 'f') flag = 0;
		last = in;
	}
	puts("left\nleft");
	forward();
	puts("right");
	flag = 1;
	while (flag) {
		forward();
		cin >> in;
		if (last[0] != 'f' && in[0] == 'f') flag = 0;
		last = in;
	}
	c1 = c2 = 0, flag = 1; 
	while (flag) {
		forward();
		if (last[0] != 'f' && in[0] == 'f') flag = 0; 
		if (in[0] == 'f') c2 ++;
		else c1 ++;
		last = in;
	}
	if (c1 > c2) {
		puts("left\nleft");
		forward();
		dig();
	}
	else {
		flag = 1;
		while (flag) {
			forward();
			if (last[0] != 'f' && in[0] == 'f') flag = 0; 
			last = in;
		}
		puts("left\nleft");
		forward();
		dig();
	}
	return 0;
}