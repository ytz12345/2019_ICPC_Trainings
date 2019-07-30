#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int M = (1 << 20) + 2019;
const int B = 2155;

int n, m, pl, pr, cur, a[N], b[N], d[N], cnt[M];

int idxC, idxQ, tim[N], pos[N], val[N], pre[N];

ll res, ans[N];

#define mst(x) memset (x, 0, sizeof x)
#define bel(x) (((x) - 1) / B + 1)
struct query {
    int id, tim, l, r;
    bool operator < (const query &b) const {
        if(bel(l) != bel(b.l)) return l < b.l;
        if(bel(r) != bel(b.r)) return r < b.r;
        return id < b.id;
    }
}q[N];

void add(int p){
    res += cnt[b[p]];
    cnt[b[p]] ++;
}

void del(int p){
    cnt[b[p]] --;
    res -= cnt[b[p]];
}

void change_add(int cur){
    if(pos[cur] >= pl && pos[cur] <= pr) del(pos[cur]);
    pre[cur] = b[pos[cur]];
    b[pos[cur]] = val[cur];
    if(pos[cur] >= pl && pos[cur] <= pr) add(pos[cur]);
}

void change_del(int cur){
    if(pos[cur] >= pl && pos[cur] <= pr) del(pos[cur]);
    b[pos[cur]] = pre[cur];
    if(pos[cur] >= pl && pos[cur] <= pr) add(pos[cur]);
}

void change(int now){
    while(cur < idxC && tim[cur + 1] <= now) change_add(++ cur);
    while(cur > 0    && tim[cur]     >  now) change_del(cur --);
}

int main(){
    int op, x, y;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            b[i] = b[i - 1] ^ a[i];
            d[i] = a[i];
        }

        idxQ = idxC = 0;
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &op);
            if (op == 1) {
                idxQ ++;
                q[idxQ].id = idxQ;
                q[idxQ].tim = i;
                scanf("%d %d", &q[idxQ].l, &q[idxQ].r);
                q[idxQ].l --;
            }
            else {
                tim[++ idxC] = i;
                scanf("%d", &x);
                b[x] ^= a[x], b[x] ^= a[x + 1];
                swap(a[x], a[x + 1]);
                pos[idxC] = x;
                val[idxC] = b[x];
            }
        }

        for (int i = 1; i <= n; i ++) 
            b[i] = b[i - 1] ^ d[i];

        pl = 1, pr = 0; cur = res = 0;
        sort(q + 1, q + idxQ + 1);
        for(int i = 1; i <= idxQ; i++){
            change(q[i].tim);
            while(pl > q[i].l) add(-- pl);
            while(pr < q[i].r) add(++ pr);
            while(pl < q[i].l) del(pl ++);
            while(pr > q[i].r) del(pr --);
            ans[q[i].id] = res;
        }
        for(int i = 1; i <= idxQ; i++)
            printf("%lld\n", ans[i]);

        for (int i = pl; i <= pr; i ++)
            cnt[b[i]] --;
    }
    
    return 0;
}