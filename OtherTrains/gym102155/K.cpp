#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

const int M = (1 << 29) - 1;

int n, s;

int a[N], v[N], d[N];

vector <int> e[N], cb;

struct {int u, v;}f[N];

int ri[N * 3], id;

namespace my_hash {
	const int N = (1 << 19) - 1;//散列大小，一定要取2^k-1，不超内存的情况下，Ｎ越大碰撞越少
	struct E {
		int v;
		E *nxt;
	}*g[N + 1], pool[N], *cur = pool, *p;
	int vis[N + 1], T;
	void ins(int v) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return;
		p = cur ++; p -> v = v; p -> nxt = g[u]; g[u] = p;
	}
	int ask(int v) {
		int u = v & N;
		if (vis[u] < T) return 0;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) return 1;
		return 0;
	}
    void del(int v) {
		int u = v & N;
		if (vis[u] < T) vis[u] = T, g[u] = NULL;
		for (p = g[u]; p; p = p -> nxt) if (p -> v == v) p -> v = M + 1;
	}
	void init() {T ++, cur = pool;}//应对多组数据使用
}

void print() {
    printf("%d\n", n);
    for (int i = 1; i < n; i ++)
        printf("%d %d\n", v[f[i].u], v[f[i].v]);
}

int getrand() {
    static int x;
    do {
        x = ri[id ++] % (M - n) + n;
        if (id >= N * 3) id = 0;
    }while (my_hash::ask(x));
    my_hash::ins(x);
    return x;
}

int work() {
    id = 0;
    random_shuffle(ri, ri + N * 3);
    int ss, sss = s;
    my_hash::init();
    for (int i = 1; i <= n; i ++)
        if (!a[i])
            my_hash::ins(i);
    for (int i = min(3, int(cb.size())); i < cb.size(); i ++)
        my_hash::ins(v[cb[i]] = cb[i]), sss ^= v[cb[i]];
    int cnt = 0;
    while(1) {
        cnt ++;
        if (cnt > 100) return 0;
        ss = sss;
        for (int i = 1; i < min(3, int(cb.size())); i ++)
            v[cb[i]] = getrand(), ss ^= v[cb[i]];
        if (ss == 0 || ss > M || my_hash::ask(ss)) {
            for (int i = 1; i < min(3, int(cb.size())); i ++)
                my_hash::del(v[cb[i]]);
        }
        else break;
    }
    my_hash::ins(v[cb[0]] = ss);
    for (int i = 1; i <= n; i ++)
        if (d[i] % 2 == 0 && a[i]) {
            if (!my_hash::ask(i)) my_hash::ins(v[i] = i);
            else v[i] = getrand();
        }
    return 1;
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(false);
    for (int i = 0; i < N * 3; i ++)
        ri[i] = rand() % M + 1;
    cin >> n; s = n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i], v[i] = i;
    }
    for (int i = 1; i < n; i ++) {
        cin >> f[i].u >> f[i].v;
        d[f[i].u] ++, d[f[i].v] ++;
    }
    for (int i = 1; i <= n; i ++) {
        if (d[i] & 1) {
            if (!a[i]) s ^= i;
            else cb.push_back(i);
        }
    }
    if (cb.size() == 0) {
        if (s == 0) print();
        else puts("-1");
        return 0;
    }
    if (cb.size() == 1) {
        if (s == 0 || (s <= n && !a[s])) puts("-1");
        else {
            if (s <= n) swap(v[cb[0]], v[s]);
            else v[cb[0]] = s;
            print();
        }
        return 0;
    } 
    if (cb.size() == 2) {
        if (s == 0) 
            return puts("-1"), 0;
    }
    while (!work());
    print();
    return 0;
}