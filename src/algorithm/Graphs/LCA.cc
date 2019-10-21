// Not so good coded lca :)
int lca(int u, int v) {
    if(u == v) return u;
    if(lev[u] < lev[v]) return lca(v, u); 
    if(par[u][0] == par[v][0]) return par[u][0];
    int dif = lev[u] - lev[v];
    if(dif) for(int j = 0; j < L; ++j) {
        if(1 << j & dif) u = par[u][j];
    }   
    if(u == v) return u;
    assert(lev[u] == lev[v]);
    for(int j = L - 1; j >= 0; --j) {
        if(par[u][j] != par[v][j]) return lca(par[u][j], par[v][j]);
    }   
    return lca(u, v); 
}
