class DSU {
    int n;
    vector<int> p;
public:
    DSU(int n) : n(n) {
        p.assign(n, -1);
    }   
    int S(int v) { return p[v] < 0 ? v : p[v] = S(p[v]); }
    int U(int u, int v) {
        u = S(u), v = S(v);
        if(v == u) return 0;
        if(p[u] < p[v]) swap(u, v); 
        p[u] = v;
        return 1;
    }   
};
