class FenwickTree {
    size_t n;
    vector<int> tree;

    void add(int at, int by) {
        while(at <= n) {
            tree[at] += by;
            at += (at & -at);
        }
    }

    int sum(int to) {
        int ans = 0;
        while(to > 0) {
            ans += tree[to];
            to -= (to & -to);
        }
        return ans;
    }


public:
    FenwickTree(const vector<int>& v) { // 1 based vector
        n = v.size() - 1;
        tree.assign(v.size() + 1, 0);
        for(int i = 1; i <= n; ++i) update(i, i, v[i]);
    }

    void update(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    } // O(2 * lgn)

    int get(int i) {
        return sum(i);
    } // O(lgn)
};
