class UnionFind {
    vector<int> p, rank;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.resize(n);
        for(int v = 0; v < n; v++) p[v] = v;
    }
    int find_set(int v) { return (p[v] == v) ? v : (p[v] = find_set(p[v])); }
    bool in_same_set(int u, int v) { return find_set(u) == find_set(v); }
    void union_set(int u, int v) {
        if(in_same_set(u, v)) return;
        int u_set = find_set(u), v_set = find_set(v);
        if(rank[u_set] > rank[v_set]) p[v_set] = u_set;
        else {
            p[u_set] = v_set;
            if(rank[u_set] == rank[v_set]) rank[v_set]++;
        }
    }
};

template<typename weight_t>
weight_t kruskal(int n, vector<pair<weight_t, pair<int, int>>>& edge_list) {
    sort(begin(edge_list), end(edge_list));
    
    UnionFind uf(n + 1);
    int needed = n - 1;
    weight_t mst = 0;
    
    for(auto& edge : edge_list) {
        if(needed == 0) break;
        if(uf.in_same_set(edge.second.first, edge.second.second)) continue;
        uf.union_set(edge.second.first, edge.second.second);
        mst += edge.first;
        needed--;
    }

    return mst;
}
