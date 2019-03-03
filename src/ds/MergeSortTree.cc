class MergeSortTree {
    vector<vector<int>> tree;
    vector<int>& A;
    int idx_begin, idx_end;


    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

    void merge(int s1, int s2, int dest) {
        vector<int>& v1 = tree[s1];
        vector<int>& v2 = tree[s2];
        vector<int>& vdest = tree[dest];
        vdest.resize(v1.size() + v2.size());

        int j1 = 0, j2 = 0;
        for(int i = 0; i < vdest.size(); ++i) {
            if(j1 >= v1.size())       vdest[i] = v2[j2++];
            else if(j2 >= v2.size())  vdest[i] = v1[j1++];
            else if(v1[j1] <= v2[j2]) vdest[i] = v1[j1++];
            else                      vdest[i] = v2[j2++];
        }
    }

    void build(int node, int l, int r) {
        // [l, r] inclusive
        if(tree.size() <= node) tree.resize(node + 1);
        if(l == r) {
            tree[node] = { A[l] };
            return;
        }

        int mid = (l + r) / 2;
        build(left(node), l, mid);
        build(right(node), mid + 1, r);
        merge(left(node), right(node), node);
    }

    int hmlt(int x, int l, int r, int node, int start, int end) {
        // answer to the query of (x, l, r)
        if(l > end || r < start) return 0;
        if(l <= start && end <= r) {
            return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin());
        }

        int mid = (start + end) / 2;
        return hmlt(x, l, r, left(node), start, mid) + hmlt(x, l, r, right(node), mid + 1, end);
    }

public:
    MergeSortTree(vector<int>& A, int idx_begin, int idx_end)
    : A(A), idx_begin(idx_begin), idx_end(idx_end) {
        assert(A.size() > 0);
        tree.resize(2);
        build(1, idx_begin, idx_end); // building 1 based tree
    }
    
    int greater(int x, int l, int r) {
        // with the assumption that l and r are in range of A
        // return how many numbers are greater than x in the range of [l, r] in O(lg(n) * lg(n))
        return hmlt(x, l, r, 1, idx_begin, idx_end);
    }
};
