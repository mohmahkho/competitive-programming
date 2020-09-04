struct HLD : public LCA {
  vector<int> heavy;
  vector<int> top;
  vector<int> idx;
  int idx_cnt = 0;

  HLD(int n_, const vector<pair<int, int>>& edges, int root_ = 0)
    : LCA(n_, edges, root_) 
    , heavy(n, -1)
    , top(n)
    , idx(n)
  {
    dfs(root, -1);
    decompose(root, root);
  }

  int dfs(int u, int p) {
    int u_sz = 1, max_subtree = 0;
    for(int v : g[u]) if(v != p) {
      int v_sz = dfs(v, u);
      u_sz += v_sz;
      if(max_subtree < v_sz) {
        max_subtree = v_sz;
        heavy[u] = v;
      }
    }
    return u_sz;
  }

  void decompose(int u, int t) {
    idx[u] = idx_cnt++;
    top[u] = t;
    if(heavy[u] != -1) {
      decompose(heavy[u], t);
    }
    for(int v : g[u]) if(v != par[0][u] && v != heavy[u]) {
      decompose(v, v);
    }
  }
  void add_path_decomposition(int u, int w, vector<pair<int, int>>& res) {
    while(depth[u] > depth[w]) {
      int t = depth[top[u]] > depth[w] ? top[u] : kth_parent(u, depth[u] - depth[w] - 1);
      res.emplace_back(idx[t], idx[u]);
      u = par[0][t];
    }
  }

  /* returns a vector of pairs (l, r) 
   * where l and r are idxs and segment [l, r] is a part of idxs of path from u to v
   * returns size is O(lgn)
   */
  vector<pair<int, int>> get_path_decomposition(int u, int v) {
    int w = lca(u, v);
    vector<pair<int, int>> res;
    add_path_decomposition(u, w, res);
    add_path_decomposition(v, w, res);
    // res.emplace_back(idx[w], idx[w]);
    return res;
  }
};
