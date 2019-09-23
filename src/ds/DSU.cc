struct DSU {
    int n;
    vector<int> p;
    DSU(int n_) {
        n = n_;
        p.assign(n, -1);
    }
 
    int get(int u) { return p[u] < 0 ? u : p[u] = get(p[u]); }
 
    void unite(int u, int v) {
        u = get(u), v = get(v);
        if(u == v) return;
        if(p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
};
