struct dsu {
    int n;
    vector<int> p;
    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        return u == p[u] ? u : p[u] = find(p[u]);
    }
    int unite(int u, int v) {
        u = find(u), v = find(v);
        p[u] = v;
    }
};
