class DSU {
    vector<int> p;
public:
    DSU(int n) { p.assign(n, -1); }
    int S(int v) { return p[v] < 0 ? v : p[v] = S(p[v]); }
    int U(int u, int v) {
        u = S(u), v = S(v);
        if(u != v) {
            if(p[u] < p[v]) swap(u, v);
            p[u] = v;
            return 1;
        }
        return 0;
    }
};
