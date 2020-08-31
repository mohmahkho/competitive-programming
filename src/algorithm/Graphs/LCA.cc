struct LCA {
  int n;
  int lgn;
  int root = 0;
  vector<vector<int>> g;
  vector<vector<int>> par;
  vector<int> depth;

  LCA(int n_, const vector<pair<int, int>>& edges, int root_ = 0)
    : n(n_)
    , lgn(32 - __builtin_clz(n))
    , root(root_)
    , g(n)
    , par(lgn, vector<int>(n, -1))
    , depth(n)
  {
    assert(n > 0 && (int) edges.size() == n - 1);
    for(auto [u, v] : edges) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(root, -1);
    for(int j = 1; j < lgn; ++j) {
      for(int u = 0; u < n; ++u) if(par[j - 1][u] != -1) {
        par[j][u] = par[j - 1][par[j - 1][u]]; 
      }
    }
  }

  void dfs(int u, int p) {
    for(int v : g[u]) if(v != p) {
      par[0][v] = u;
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }

  int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    for(int msk = depth[u] - depth[v], j = 0; msk; msk >>= 1, ++j) if(msk & 1) {
      u = par[j][u];
    }
    if(u == v) return u;
    for(int j = lgn - 1; j >= 0; --j) if(par[j][u] != par[j][v]) {
      u = par[j][u];
      v = par[j][v];
    }
    return par[0][u];
  }

  int kth_parent(int u, int k) {
    for(int i = 0; k; k >>= 1, ++i) if(k & 1) {
      u = par[i][u];
    }
    return u;
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
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
