#include <bits/stdc++.h>

using namespace std;

int n, op;

deque <int> ans;

int tmp[555];

void print(char *s = "YES") {
    printf("! %s\n", s);
    while (!ans.empty()) printf("%d ", ans.front()), ans.pop_front();
    fflush(stdout);
    exit(0);
}

void ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
}

bool cmp(int x, int y) {
    ask(x, y);
    cin >> op;
    return op;
}


void s0rt(int l, int r) {
    if (l >= r) return;
    int pivot = l + rand() % (r - l + 1);
    int s = l, t = r;
    for (int i = l; i <= r; i ++) {
        if (i == pivot) continue;
        if (cmp(ans[i], ans[pivot])) tmp[s ++] = ans[i];
        else tmp[t --] = ans[i];
    }
    tmp[s] = ans[pivot];
    for (int i = l; i <= r; i ++)
        ans[i] = tmp[i];
    s0rt(l, s - 1);
    s0rt(t + 1, r);
}


int main() {
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n;
    if (n == 1) {
        ans.push_back(1);
        print();
    }
    if (n == 2) {
        ask(1, 2);
        cin >> op;
        if (op == 1) ans.push_back(1), ans.push_back(2);
        else ans.push_back(2), ans.push_back(1);
        print();
    }
    ans.resize(n);
    for (int i = 1; i <= n; i ++)
        ans[i - 1] = i;
    s0rt(0, n - 1);
    ask(ans[n - 1], ans[0]);
    cin >> op;
    if (op == 1) ans.push_front(n), print("NO");
    else print();

    return 0;
}
