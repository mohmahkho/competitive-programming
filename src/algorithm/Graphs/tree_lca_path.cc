struct tree {
  const int n, lgn;
  vector<vector<int>> g, par;
  vector<int> lvl;
  tree(int n_) : n(n_), lgn(log2(n_) + 2) {
    g.assign(n, {});
    par.assign(lgn, vector(n, 0));
    lvl.assign(n, 0);
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void dfs(int u, int p) {
    par[0][u] = p;
    lvl[u] = lvl[p] + 1;
    for(int v : g[u]) {
      if(v != p) {
        dfs(v, u);
      }
    }
  }
  void lca_precompute() {
    dfs(0, 0);
    for(int j = 1; j < lgn; ++j) {
      for(int u = 0; u < n; ++u) {
        par[j][u] = par[j - 1][par[j - 1][u]];
      }
    }
  }
  int lca(int u, int v) {     
    static bool precomputed = false;
    if(precomputed == false) {
      lca_precompute();
      precomputed = true;
    }
    if(lvl[u] < lvl[v]) {
      swap(u, v);
    }
    for(int j = lgn - 1; j >= 0; --j) {
      if(lvl[par[j][u]] >= lvl[v]) {
        u = par[j][u];
      }
    }
    assert(lvl[u] == lvl[v]);
    if(u == v) {
      return u;
    }
    for(int j = lgn - 1; j >= 0; --j) {
      if(par[j][u] != par[j][v]) {
        u = par[j][u];
        v = par[j][v];
      }
    }
    return par[0][u];
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
