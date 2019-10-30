class MergeSortTree {
    const vector<int>& a;
    int from, to;
    vector<vector<int>> tree;

    inline int L(int v) { return v << 1; }
    inline int R(int v) { return (v << 1) + 1; }

    void build(int v, int l, int r) {
        if(l == r) {
            tree[v] = { a[l] };
        } else {
            int m = (l + r) >> 1;
            build(L(v), l, m);
            build(R(v), m + 1, r);
            merge(tree[L(v)].begin(), tree[L(v)].end(),
                  tree[R(v)].begin(), tree[R(v)].end(),
                  back_inserter(tree[v]));
        }
    }

    int leq(int v, int l, int r, int ql, int qr, int x) {
        if(ql > r || qr < l)
            return 0;
        if(ql <= l && r <= qr)
            return upper_bound(tree[v].begin(), tree[v].end(), x) - tree[v].begin();
        int m = (l + r) >> 1;
        return leq(L(v), l, m, ql, qr, x) + leq(R(v), m + 1, r, ql, qr, x);
    }

public:
    MergeSortTree(const vector<int>& a, int from, int to)
    : a(a), from(from), to(to) {
        tree.resize((to - from + 1) << 2);
        build(1, from, to);
    }

    int leq(int ql, int qr, int x) {
        return leq(1, from, to, ql, qr, x);
    }
};
