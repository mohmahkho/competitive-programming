struct UnionFind {
    vector<int> p, s;
    UnionFind(int n) {
        s.assign(n, 1);
        p.resize(n);
        for(int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
    bool same(int u, int v) { return find(u) == find(v); }
    void unite(int u, int v) {
        if(same(u, v)) return;
        u = find(u), v = find(v);
        if(s[u] > s[v]) p[u] = v, s[v] += s[u];
        else            p[v] = u, s[u] += s[v];
    }
};
