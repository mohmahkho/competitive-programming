class FenwickTree {
    size_t n;
    vector<int> tree;

public:
    FenwickTree(const vector<int>& v) { // 1 based vector
        n = v.size() - 1;
        tree.assign(v.size(), 0);
        for(int i = 1; i <= n; ++i) add(i, v[i]);
    }

    void add(int at, int by) {
        while(at <= n) {
            tree[at] += by;
            at += (at & -at);
        }
    } // O(lgn)

    int sum(int to) {
        int ans = 0;
        while(to > 0) {
            ans += tree[to];
            to -= (to & -to);
        }
        return ans;
    } // O(lgn)

    int sum(int from, int to) {return sum(to) - sum(from - 1);}
};
