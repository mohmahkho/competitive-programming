class UnionFind {
    vector<int> p, rank;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; ++i) p[i] = i;
    }
    int find_set(int v) {
        return p[v] == v ? v : p[v] = find_set(p[v]); // path compression
    }
    bool in_same_set(int u, int v) {
        return find_set(u) == find_set(v);
    }
    void unite(int u, int v) {
        if(in_same_set(u, v)) return ;
        u = find_set(u); v = find_set(v);
        if(rank[u] > rank[v]) p[v] = u; // union by rank
        else {
            p[u] = v;
            if(rank[u] == rank[v]) ++rank[v];
        }
    }
};
