template <class T, class BinOp, T id>
class SegTree {
    vector<T>& A;
    vector<T> tree;
    BinOp op;
    int from, to;

    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

    void build(int node, int l, int r) {
        // l and r are in the main array
        if(tree.size() <= node) tree.resize(node + 1);
        if(l == r) {
            tree[node] = A[l];
        } else {
            int mid = (l + r) / 2;
            build(left(node), l, mid);
            build(right(node), mid + 1, r);
            tree[node] = op(tree[left(node)], tree[right(node)]);
        }
    }

    T rq(int node, int l, int r, int ql, int qr) {
        if(l > qr || ql > r) return id;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return op(rq(left(node), l, mid, ql, qr), rq(right(node), mid + 1, r, ql, qr));
    }

    void upd(int node, int l, int r, int qi, T qval) {
        if(l == r && l == qi) {
            tree[node] = qval;
            return;
        }
        int mid = (l + r) / 2;
        if(qi <= mid) upd(left(node), l, mid, qi, qval);
        else          upd(right(node), mid + 1, r, qi, qval);

        tree[node] = op(tree[left(node)], tree[right(node)]);
    }

public:
    SegTree(vector<T>& A, int from, int to)
    : A(A), from(from), to(to), op(BinOp()) {
        build(1, from, to); // 1 based tree // it means root of the tree is index
    }

    T rq(int ql, int qr) {
        return rq(1, from, to, ql, qr);
    }

    void upd(int qi, T qval) {
        A[qi] = qval; // if you want to change the main array
        upd(1, from, to, qi, qval);
    }  
};
