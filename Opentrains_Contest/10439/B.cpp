#include <bits/stdc++.h>

const int max_N = 2000 + 21;

using LL = long long;

LL ask(LL a, LL b) {
    if (a == -1) return b;
    if (b == -1) return a;
    printf("? %lld %lld\n", a, b);
    fflush(stdout);
    LL ret;
    scanf("%lld", &ret);
    return ret;
}

int n, logn, tot, q, k, p[max_N];

LL A[max_N], prefix[max_N], suffix[max_N], compressed[max_N];

int ql, qr;

LL qa;

using pTree = std::unique_ptr<const struct Tree>;

struct Tree {
    std::vector<LL> a, s;
    int l, r, m;
    pTree ls, rs;
    Tree (LL *A, int l, int r) : ls(nullptr), rs(nullptr) {
        this->l = l;
        this->r = r;
        for (int i = l; i <= r; ++i) a.push_back(A[i]);
        m = (l + r) >> 1;
        s.resize(a.size());
        s[m - l] = A[m];
        for (int i = m - 1; i >= l; --i) {
            s[i - l] = ask(A[i], s[i + 1 - l]);
        }
        s[m + 1 - l] = A[m + 1];
        for (int i = m + 2; i <= r; ++i) {
            s[i - l] = ask(A[i], s[i - 1 - l]);
        }
        if (l < r) {
            ls = std::move(pTree(new Tree(A, l, m)));
            rs = std::move(pTree(new Tree(A, m + 1, r)));
        }
    }

    void query() const {
        if (ql > qr) return;
        assert(l <= ql && qr <= r);
        if (ql == qr) {
            qa = ask(qa, a[ql - l]);
            return;
        }
        if (qr <= m) return ls->query();
        if (ql >  m) return rs->query();
        qa = ask(qa, s[ql - l]);
        qa = ask(qa, s[qr - l]);
    }
};

pTree rt;

void query(int l, int r) {
    if (l > r) return;
    int lx = l / logn;
    int rx = r / logn;
    if (lx == rx) {
        for (int i = l; i <= r; ++i) {
            qa = ask(qa, A[i]);
        }
        return;
    }
    qa = ask(qa, suffix[l]);
    qa = ask(qa, prefix[r]);
    ql = lx + 1, qr = rx - 1;
    rt->query();
}

int main() {
    scanf("%d%d%d", &n, &q, &k);
    for (int i = 0; i < n; ++i) p[i] = i;
    std::random_shuffle(p, p + n);
    for (int i = 0; i < n; ++i) scanf("%lld", A + p[i]);
    for (logn = 0; (1 << logn) < n; ++logn);
    tot = (n - 1) / logn;
    for (int i = 0; i < n; ++i) {
        prefix[i] = A[i];
        if (i % logn != 0) prefix[i] = ask(prefix[i - 1], prefix[i]);
    }
    suffix[n - 1] = A[n - 1];
    for (int i = n - 2; ~i; --i) {
        suffix[i] = A[i];
        if (i % logn != logn - 1) suffix[i] = ask(suffix[i + 1], suffix[i]);
    }
    for (int i = 0; i <= tot; ++i) compressed[i] = suffix[i * logn];
    rt = pTree(new Tree(compressed, 0, tot));
    while (q--) {
        puts("next");
        fflush(stdout);
        std::vector<int> pos;
        for (int i = 1, x; i <= k; ++i) {
            scanf("%d", &x);
            pos.push_back(p[x - 1]);
        }
        std::sort(pos.begin(), pos.end());
        qa = -1;
        query(0, pos[0] - 1);
        query(pos.back() + 1, n - 1);
        for (int i = 1; i < k; ++i) query(pos[i - 1] + 1, pos[i] - 1);
        printf("! %lld\n", qa);
        fflush(stdout);
    }
}