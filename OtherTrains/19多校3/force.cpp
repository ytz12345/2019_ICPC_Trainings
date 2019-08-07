
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 7;
 
int n, q, op, l, r, block;
LL sum;
int a[maxn], b[maxn];
LL cnt[1 << 20 + 5];
 
struct que
{
    int l, r, id, t;
    LL ans;
    bool operator < (const que& x) const
    {
        if ((l - 1) / block != (x.l - 1) / block) {
            return l < x.l;
        }
        if ((r - 1) / block != (x.r - 1) / block) {
            return r < x.r;
        }
        return t < x.t;
    }
}ask[maxn];
 
struct modify {
    int pre, val, pos;
}mfy[maxn];
 
void del(int x) {
    --cnt[x];
    sum -=cnt[x];
}
 
void add(int x) {
    sum += cnt[x];
    ++cnt[x];
}
int main()
{
    while (~scanf("%d%d", &n, &q))
    {
        sum = 0;
        for (int i = 0; i <= 1024 * 1024; i++)cnt[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = b[i - 1] ^ a[i];
        }
        block = (int)pow(n, 2.0 / 3);
        int nw = 0, idq = 0, idc = 0;
        for (int i = 1; i <= q; i++)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                // 询问当前的区间
                idq++;
                scanf("%d%d", &ask[idq].l, &ask[idq].r);
                ask[idq].id = idq;
                --ask[idq].l;
                ask[idq].t = nw;
            }
            else
            {
                //修改
                idc++;
                ++nw;
                scanf("%d", &mfy[idc].pos);
                int pos = mfy[idc].pos;
                mfy[idc].pre = b[pos];
                b[pos] = b[pos + 1] ^ a[pos];
                mfy[idc].val = b[pos];
                swap(a[pos], a[pos + 1]);
            }
        }
        sort(ask + 1, ask + idq + 1);
        int tmp = nw;
        for (int i = 1, l = 1, r = 0; i <= idq; ++i) {
            while (r < ask[i].r) add(b[++r]);
            while (l > ask[i].l) add(b[--l]);
            while (r > ask[i].r) del(b[r--]);
            while (l < ask[i].l) del(b[l++]);
            while (tmp < ask[i].t) {
                tmp++;
                if (mfy[tmp].pos >= ask[i].l && mfy[tmp].pos <= ask[i].r) {
                    del(mfy[tmp].pre);
                    add(mfy[tmp].val);
                }
                b[mfy[tmp].pos] = mfy[tmp].val;
            }
            while (tmp > ask[i].t) {
                if (mfy[tmp].pos >= ask[i].l && mfy[tmp].pos <= ask[i].r) {
                    del(mfy[tmp].val);
                    add(mfy[tmp].pre);
                }
                b[mfy[tmp].pos] = mfy[tmp].pre;
                tmp--;
            }
            ask[ask[i].id].ans = 1LL * (ask[i].r - ask[i].l) * (ask[i].r - ask[i].l + 1) / 2 - sum;
        }
        for (int i = 1; i <= idq; ++i) {
            printf("%lld\n", ask[i].ans);
        }
    }
    return 0;
}