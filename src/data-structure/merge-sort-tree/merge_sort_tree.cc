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

    // returns number of numbers less than or equal to x in a[ql:qr]
    int leq(int ql, int qr, int x) {
        return leq(1, from, to, ql, qr, x);
    }
};


/*
when using merge sort we devide array into two pieces and sort them then merge them up
so we can create a tree that the first node of it is the whole array but sorted
left child is first half of the array but sorted and right child is second half of the array but sorted

 for example if we have array 3, 2, 1, 3, 5, 1, 5, 4
 
 then the tree would be like :
                                1, 1, 2, 3, 3, 4, 5, 5
                                    /          \
                                   /            \
                                  /              \
                             1, 2, 3, 3      1, 4, 5, 5
                                ...              ...
                              

we can use this structure to answer the queries like : "how many numbers are less than 3 in the range of 3, 8"
in O(lg(n)*lg(n)) using the method that we use to answer queries in segment tree.

the space complexity of this data structure is O(n * lg(n))
because merge sort tree has lg(n) layers and at each layer we have the whole array. 
*/
