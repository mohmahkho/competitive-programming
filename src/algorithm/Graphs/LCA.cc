struct LCA {
  const int n, lgn;
  vector<vector<int>> g, par;
  vector<int> lev;
  LCA(int n_, vector<pair<int, int>>& edges) : n(n_), lgn(32 - __builtin_clz(n_)) {
    assert(n > 0 && edges.size() == n - 1);
    g.assign(n, {});
    par.assign(lgn, vector(n, 0));
    lev.assign(n, 0);
    for(auto [u, v] : edges) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int p) {
      par[0][u] = p;
      lev[u] = lev[p] + (u != p);
      for(int v : g[u]) {
        if(v != p) {
          dfs(v, u);
        }
      }
    };
    dfs(0, 0);
    for(int i = 1; i < lgn; ++i) {
      for(int u = 0; u < n; ++u) {
        par[i][u] = par[i - 1][par[i - 1][u]]; 
      }
    }
  }
  int lca(int u, int v) {
    if(lev[u] < lev[v]) {
      swap(u, v);
    }
    for(int msk = lev[u] - lev[v], i = 0; msk; msk >>= 1, ++i) {
      if(msk & 1) {
        u = par[i][u];
      }
    }
    if(u == v) {
      return u;
    }
    for(int i = lgn - 1; i >= 0; --i) {
      if(par[i][u] != par[i][v]) {
        u = par[i][u];
        v = par[i][v];
      }
    }
    return par[0][u];
  }
  int dist(int u, int v) {
    return lev[u] + lev[v] - 2 * lev[lca(u, v)];
  }
  vector<int> path(int u, int v) {
    vector<int> p;
    int w = lca(u, v);
    while(u != w) {
      p.push_back(u);
      u = par[0][u];
    }
    p.push_back(w);
    int s = p.size();
    while(v != w) {
      p.push_back(v);
      v = par[0][v];
    }
    reverse(p.begin() + s, p.end());
    return p;
  }
};
