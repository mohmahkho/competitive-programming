struct HLD {
  int N, LgN;
  vector<int> depth, heavy, top, pos;
  vector<vector<int>> G, P;

  HLD(int n, const vector<pair<int, int>>& edges) : N(n), LgN(32 - __builtin_clz(N)),
    depth(N), heavy(N, -1), top(N), pos(N), G(N), P(LgN, vector<int>(N)) {
    for(auto [u, v] : edges) {
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(0, 0);
    decompose(0, 0);
    for(int i = 1; i < LgN; ++i) {
      for(int u = 0; u < N; ++u) {
        P[i][u] = P[i - 1][P[i - 1][u]];
      }
    }
  }

  int dfs(int u, int p) {
    P[0][u] = p;
    int u_sz = 1, max_subtree = 0;
    for(int v : G[u]) if(v != p) {
      depth[v] = depth[u] + 1;
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
    static int pos_cnt = 0;
    pos[u] = pos_cnt++;
    top[u] = t;
    if(heavy[u] != -1) {
      decompose(heavy[u], t);
    }
    for(int v : G[u]) if(v != P[0][u] && v != heavy[u]) {
      decompose(v, v);
    }
  }

  int lca(int u, int v) {
    if(depth[u] < depth[v]) {
      swap(u, v);
    }
    for(int msk = depth[u] - depth[v], i = 0; msk; msk >>= 1, ++i) if(msk & 1) {
      u = P[i][u];
    }
    if(u == v) {
      return u;
    }
    for(int i = LgN - 1; i >= 0; --i) {
      if(P[i][u] != P[i][v]) {
        u = P[i][u];
        v = P[i][v];
      }
    }
    return P[0][u];
  }
  int kth_parent(int u, int k) {
    for(int i = 0; k; k >>= 1, ++i) if(k & 1) {
      u = P[i][u];
    }
    return u;
  }
  void add_path_decomposition(int u, int w, vector<pair<int, int>>& res) {
    while(depth[u] > depth[w]) {
      int t = depth[top[u]] > depth[w] ? top[u] : kth_parent(u, depth[u] - depth[w] - 1);
      res.emplace_back(pos[t], pos[u]);
      u = P[0][t];
    }
  }
  vector<pair<int, int>> path_decomposition(int u, int v) {
    int w = lca(u, v);
    vector<pair<int, int>> res;
    add_path_decomposition(u, w, res);
    add_path_decomposition(v, w, res);
    res.emplace_back(pos[w], pos[w]);
    return res;
  } // returns a vector of (l, r) where l and r are poss and segment [l, r] is a part of poss of path from u to v
  // vector size is O(LgN)
};
