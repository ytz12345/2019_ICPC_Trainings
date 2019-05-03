#include <bits/stdc++.h>

using namespace std;

void move_(char *str) {
    printf("move %s\n", str);
    fflush(stdout);
}

void echo_(char *str = "Ready！") {
    printf("echo %s\n", str);
    fflush(stdout);
}

char *s[] = {"north", "east", "south", "west"};

int path[] = {0, 1, 2, 2, 3, 3, 0, 0, 1, 2};

char res[10];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 10; i ++) {
        move_(s[path[i]]);
        cin >> res;
        if (res[0] == 'f') {
            move_(s[path[i + 1]]); cin >> res;
            for (int j = 0; j < 7 - i; j ++)
                echo_(), cin >> res;
            move_(s[(2 + path[i + 1]) % 4]), cin >> res;
            return 0;
        }
    }
    return 0;
}   